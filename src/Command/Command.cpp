#include "../lib-header/Command/Command.hpp"
#include "../lib-header/Game/Game.hpp"

// ctor
Command::Command() : typeCommand{false} {

}

// ctor
Command::~Command() {

}

bool Command::getTypeCommand() {
  return typeCommand;
}
// setter
void Command::setTypeCommand(bool newTypeCmd) {
  typeCommand = newTypeCmd;
}