#include "../lib-header/Card/Combo.hpp"
#include "../lib-header/Player/Player.hpp"
using namespace std;

Combo::Combo(Player player, TableCard tableCard) : comboId(0) {
    for (int i = 0; i < 2; i++) {
        finalSetCard.push_back(player.getNormalCard(i));
    }
    for (int i = 0; i < 6; i++) {
        finalSetCard.push_back(tableCard.getContainerAt(i));
    }
}

Combo::Combo(const Combo& other) {
    value = other.value;
    comboId = other.comboId;
    finalSetCard = other.finalSetCard;
}

int Combo::getComboId() {
    return comboId;
}


void Combo::computeValue() {
    
}