#include "../lib-header/Ability/ReverseDirection.hpp"
#include "../lib-header/Game/Game.hpp"


// implementasi sementara 
// supaya bisa ngerjain main
ReverseDirection::ReverseDirection() {
    Ability::setType("REVERSE");
}

ReverseDirection::~ReverseDirection() { }

void ReverseDirection::action(Game& game) {
    game.playerPointer.first->setAbilityUsed(true);
    deque<pair<Player*,bool>> copy; 
    for (int i = game.playerPointer.second + 1; i - game.playerPointer.second <= game.MAX_PLAYER; i++){
        copy.push_front(game.playerQueue.at(i%game.MAX_PLAYER));
    }
    game.playerQueue.swap(copy);
}
