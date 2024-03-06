#include <iostream>
#include "text_editor.hpp"

int main() {

    int delete_chars = 6;
    TextDocument *receiver =  new TextDocument();

    TextEditor editor;
    editor.type(receiver, "Hello, ");
    editor.type(receiver, "Design Patterns!");
    std::cout << "Content: " << receiver->getContent() << std::endl;

    editor.deleteChars(receiver, delete_chars);
    std::cout << "Content after deleting "<< delete_chars << " chars : " << receiver->getContent() << std::endl;

    editor.undo();
    std::cout << "Content after undo: " << receiver->getContent() << std::endl;

    return 0;
}
