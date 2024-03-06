#ifndef _TXT_EDITOR_H
#define _TXT_EDITOR_H

#include <memory>
#include <stack>
#include <string>

// Command Interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class TextDocument {
public:
    void addText(const std::string& text) {
        content += text;
    }

    void deleteText(int length) {
        content = content.substr(0, content.length() - length);
    }

    std::string getContent() const {
        return content;
    }

private:
    std::string content;
};

// Concrete Command for Adding Text
class AddTextCommand : public Command {
public:
    AddTextCommand(TextDocument& doc, const std::string& text)
        : doc(doc), text(text) {}

    void execute() override {
        doc.addText(text);
    }

    void undo() override {
        doc.deleteText(text.length());
    }

private:
    // refence TextDocument
    TextDocument& doc;
    std::string text;
};

// Concrete Command for Deleting Text
class DeleteTextCommand : public Command {
public:
    DeleteTextCommand(TextDocument& doc, int length)
        : doc(doc), length(length) {}

    void execute() override {
        deletedText = doc.getContent().substr(doc.getContent().length() - length);
        doc.deleteText(length);
    }

    void undo() override {
        doc.addText(deletedText);
    }

private:
    // refence to TextDocument
    TextDocument& doc;
    int length;
    std::string deletedText;
};

// Invoker
class TextEditor {
public:
    void type(TextDocument *document,const std::string& text) {
        std::unique_ptr<Command> cmd = std::make_unique<AddTextCommand>(*document, text);
        cmd->execute();
        undoStack.push(std::move(cmd));
    }

    void deleteChars(TextDocument *document, int length) {
        std::unique_ptr<Command> cmd = std::make_unique<DeleteTextCommand>(*document, length);
        cmd->execute();
        undoStack.push(std::move(cmd));
    }

    void undo() {
        if (!undoStack.empty()) {
            undoStack.top()->undo();
            undoStack.pop();
        } else {
            std::cout << "Nothing to undo." << std::endl;
        }
    }

private:
    std::stack<std::unique_ptr<Command>> undoStack;
};

#endif