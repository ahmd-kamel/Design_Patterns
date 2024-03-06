#include <iostream>
#include "command.hpp"

int main() {
    
    std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();
    Invoker invoker;

    // Queue commands
    invoker.addCommand(std::make_unique<ConcreteCommand>(receiver, "Draw circle"));
    invoker.addCommand(std::make_unique<ConcreteCommand>(receiver, "Draw rectangle"));
    invoker.addCommand(std::make_unique<ConcreteCommand>(receiver, "Draw triangle"));

    // Execute commands
    std::cout << "Executing commands:" << std::endl;
    invoker.executeCommands();

    // Undo commands
    std::cout << "\nUndoing commands:" << std::endl;
    invoker.undoCommands();

    return 0;
}
