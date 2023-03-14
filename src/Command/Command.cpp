#include "../lib-header/Command/Command.hpp"

// getter
bool Command::getTypeCommand() {
  return typeCommand;
}
// setter
void Command::setTypeCommand(bool newTypeCmd) {
  typeCommand = newTypeCmd;
}