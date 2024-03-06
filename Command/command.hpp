#ifndef _COMMAND_H
#define _COMMAND_H

#include <string>
#include <vector>
#include <memory>


// Command Interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class Receiver {
public:
    void action(const std::string& message) {
        std::cout << "Receiver is executing action: " << message << std::endl;
    }

    void undoAction(const std::string& message) {
        std::cout << "Receiver is undoing action: " << message << std::endl;
    }
};

// Concrete Command
class ConcreteCommand : public Command {
public:
    ConcreteCommand(std::shared_ptr<Receiver> receiver, const std::string& message)
        : receiver(receiver), message(message) {}

    void execute() override {
        receiver->action(message);
    }

    void undo() override {
        receiver->undoAction(message);
    }

private:
    std::shared_ptr<Receiver> receiver;
    std::string message;
};


// Invoker
class Invoker {
public:
    void addCommand(std::unique_ptr<Command> command) {
        commands.push_back(std::move(command));
    }

    void executeCommands() {
        for (const auto& command : commands)
            command->execute();
    }

    void undoCommands() {
        for (auto it = commands.rbegin(); it != commands.rend(); it++)
            (*it)->undo();
    }

private:
    std::vector<std::unique_ptr<Command>> commands;

};

#endif