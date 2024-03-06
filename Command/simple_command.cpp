#include <iostream>
#include "command.hpp"


int main() {

    // Client Side
    std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();
    std::unique_ptr<Command> command = std::make_unique<ConcreteCommand>(receiver, "Draw a circle");

    Invoker invoker;
    invoker.addCommand(std::move(command));
    invoker.executeCommands();
    invoker.undoCommands();


    return 0;
}
