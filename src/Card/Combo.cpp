#include "../lib-header/Card/Combo.hpp"
#include "../lib-header/Player/Player.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

IndividualCombo::IndividualCombo() : comboId(0) {}

IndividualCombo::IndividualCombo(int comboId) : comboId(comboId) {}

int IndividualCombo::getComboId() {
    return comboId;
}

vector<Card> IndividualCombo::getCardCombo() {
    return cardCombo;
}

void IndividualCombo::insertCardCombo(const vector<Card> vecCard) {
    copy(vecCard.begin(), vecCard.end(), back_inserter(cardCombo));
}

bool IndividualCombo::operator<(const IndividualCombo& other) {
    if (comboId < other.comboId) {
        return true;
    } else if (comboId > other.comboId) {
        return false;
    } else {
        return value < other.value;
    }
}

bool IndividualCombo::operator>(const IndividualCombo& other) {
    if (comboId > other.comboId) {
        return true;
    } else if (comboId < other.comboId) {
        return false;
    } else {
        return value > other.value;
    }
}

bool IndividualCombo::operator==(const IndividualCombo& other) {
    return comboId == other.comboId && value == other.value;
}

bool IndividualCombo::operator!=(const IndividualCombo& other) {
    if (comboId == other.comboId) {
        if (cardCombo.size() == other.cardCombo.size()) {
            for (int i = 0; i < cardCombo.size(); i++) {
                if (cardCombo[i] != other.cardCombo[i]) {
                    return true;
                }
            }
            return false;
        }
    }
    return true;
}

void IndividualCombo::computeValue() {
    if (comboId == 2) { // pair
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33 + colorCode[cardCombo[1].getColor()] * 0.0033;
    } else if (comboId == 3) { // two pair
        value = cardCombo[0].getNumber();
    } else if (comboId == 4) { // three of a kind
        value = cardCombo[0].getNumber();
    } else if (comboId == 5) { // straight
        value = cardCombo[0].getNumber();
    } else if (comboId == 6) { // flush
        for (int i = 0; i < cardCombo.size(); i++) {
            value += cardCombo[cardCombo.size() - 1 - i].getNumber() * (pow(100, i));
        }   
        value += colorCode[cardCombo[0].getColor()] * 0.33;
    } else if (comboId == 7) { // full house
        // map<int, int> freqNum = getCardFreqByNumber();
        // value = 0;
    } else if (comboId == 8) { // four of a kind
        value = cardCombo[0].getNumber();
    } else if (comboId == 9) { // straight flush
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33;
    }
}

Combo::Combo(Player player, TableCard tableCard) : valueMax(valueMax) {
    for (int i = 0; i < 2; i++) {
        finalSetCard.push_back(player.getNormalCard(i));
    }
    for (int i = 0; i < 6; i++) {
        finalSetCard.push_back(tableCard.getContainerAt(i));
    }

    sort(finalSetCard.begin(), finalSetCard.end(), [](Card a, Card b){return a > b;});
}

Combo::Combo(const Combo& other) {
    valueMax = other.valueMax;
    finalSetCard = other.finalSetCard;
}

vector<Card> Combo::getFinalSetCard() {
    return finalSetCard;
}

vector<IndividualCombo> Combo::getAllCombo() {
    return allCombo;
}

map<int, int> Combo::getCardFreqByNumber() {
    map<int, int> freqNum;
    for (int i = 0; i < finalSetCard.size(); i++) {
        if (freqNum.find(finalSetCard[i].getNumber()) == freqNum.end()) {
            freqNum[finalSetCard[i].getNumber()] = 1;
        } else {
            freqNum[finalSetCard[i].getNumber()]++;
        }
    }
    return freqNum;
}

map<string, int> Combo::getCardFreqByColor() {
    map<string, int> freqColor;
    for (int i = 0; i < finalSetCard.size(); i++) {
        if (freqColor.find(finalSetCard[i].getColor()) == freqColor.end()) {
            freqColor[finalSetCard[i].getColor()] = 1;
        } else {
            freqColor[finalSetCard[i].getColor()]++;
        }
    }
    return freqColor;
}

map<int, int> Combo::getComboFreq() {
    map<int, int> freqCombo;
    for (int i = 0; i < allCombo.size(); i++) {
        if (freqCombo.find(allCombo[i].getComboId()) == freqCombo.end()) {
            freqCombo[allCombo[i].getComboId()] = 1;
        } else {
            freqCombo[allCombo[i].getComboId()]++;
        }
    }
    return freqCombo;
}

void Combo::checkPair() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 2) {
            IndividualCombo combo(2);
            vector<Card> pairSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(pairSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            combo.insertCardCombo(pairSetCard);
            combo.computeValue();
            allCombo.push_back(combo);
        }
    }
}

void Combo::checkThreeOfAKind() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 3) {
            IndividualCombo combo(4);
            vector<Card> threeSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(threeSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            combo.insertCardCombo(threeSetCard);
            combo.computeValue();
            allCombo.push_back(combo);
        }
    }
}

void Combo::checkFourOfAKind() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 4) {
            IndividualCombo combo(8);
            vector<Card> fourSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(fourSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            combo.insertCardCombo(fourSetCard);
            combo.computeValue();
            allCombo.push_back(combo);
        }
    }
}

bool Combo::isStraight(vector<Card> fiveSetCard) {
    for (int i = 0; i < fiveSetCard.size() - 1; i++) {
        if (fiveSetCard[i].getNumber() - fiveSetCard[i + 1].getNumber() != 1) {
            return false;
        }
    }
    return true;
}

bool Combo::isFlush(vector<Card> fiveSetCard) {
    for (int i = 0; i < fiveSetCard.size() - 1; i++) {
        if (fiveSetCard[i].getColor() != fiveSetCard[i + 1].getColor()) {
            return false;
        }
    }
    return true;
}

void Combo::checkStraightAndFlush() {
    
    vector<Card> fiveSetCard;

    for (int i = 0; i < 4; i++) {
        fiveSetCard.push_back(finalSetCard[i]);
        for (int j = i + 1; j < 5;j++) {
            fiveSetCard.push_back(finalSetCard[j]);
            for (int k = j + 1; k < 6; k++) {
                fiveSetCard.push_back(finalSetCard[k]);
                for (int l = k + 1; k < 7; l++) {
                    fiveSetCard.push_back(finalSetCard[l]);
                    for (int m = l + 1; m < 8; m++) {
                        fiveSetCard.push_back(finalSetCard[m]);

                        if (isStraight(fiveSetCard) && isFlush(fiveSetCard)) {
                            IndividualCombo newCombo(9);
                            newCombo.insertCardCombo(fiveSetCard);
                            newCombo.computeValue();
                            allCombo.push_back(newCombo);
                        } else if (isStraight(fiveSetCard)) {
                            IndividualCombo newCombo(5);
                            newCombo.insertCardCombo(fiveSetCard);
                            newCombo.computeValue();
                            allCombo.push_back(newCombo);
                        } else if (isFlush(fiveSetCard)) {
                            IndividualCombo newCombo(6);
                            newCombo.insertCardCombo(fiveSetCard);
                            newCombo.computeValue();
                            allCombo.push_back(newCombo);
                        }
                        
                        fiveSetCard.pop_back();
                    }
                    fiveSetCard.pop_back();
                }
                fiveSetCard.pop_back();
            }
            fiveSetCard.pop_back();
        }
        fiveSetCard.pop_back();
    }
}

void Combo::checkTwoPair() {
    map<int, int> freqCombo = getComboFreq();
    if (freqCombo[2] > 1) {
        sort(allCombo.begin(), allCombo.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
        vector<IndividualCombo> pairComboVec;
        copy_if(allCombo.begin(), allCombo.end(), back_inserter(pairComboVec), [](IndividualCombo combo){ return combo.getComboId() == 2; });

        sort(pairComboVec.begin(), pairComboVec.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
        
        do {
            IndividualCombo newCombo(3);
            vector<Card> tempContainer;
            for (int i = 0; i < pairComboVec.size(); i++) {
                copy(pairComboVec[i].getCardCombo().begin(), pairComboVec[i].getCardCombo().end(), back_inserter(tempContainer));
            }
            newCombo.insertCardCombo(tempContainer);
            newCombo.computeValue();
            allCombo.push_back(newCombo);
        } while (next_permutation(pairComboVec.begin(), pairComboVec.end()) && pairComboVec[1] != pairComboVec[pairComboVec.size() - 1]);
    }
}

void Combo::checkFullHouse() {
    map<int, int> freqCombo = getComboFreq();
    if (freqCombo.find(2) != freqCombo.end() && freqCombo.find(4) != freqCombo.end()) {
        sort(allCombo.begin(), allCombo.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
        vector<IndividualCombo> pairComboVec;
        vector<IndividualCombo> threeComboVec;
        copy_if(allCombo.begin(), allCombo.end(), back_inserter(pairComboVec), [](IndividualCombo combo){ return combo.getComboId() == 2; });
        copy_if(allCombo.begin(), allCombo.end(), back_inserter(threeComboVec), [](IndividualCombo combo){ return combo.getComboId() == 4; });
        for (int i = 0; i < threeComboVec.size(); i++) {
            IndividualCombo newCombo(7);
            vector<Card> tempContainer;
            for (int j = 0; j < pairComboVec.size(); i++) {
                copy(threeComboVec[i].getCardCombo().begin(), threeComboVec[i].getCardCombo().end(), back_inserter(tempContainer));
                copy(pairComboVec[i].getCardCombo().begin(), pairComboVec[i].getCardCombo().end(), back_inserter(tempContainer));
            }
            newCombo.insertCardCombo(tempContainer);
            newCombo.computeValue();
            allCombo.push_back(newCombo);
        }
    }
}

// void Combo::generateHighCard() {
//     for (int i = 0; i < finalSetCard.size(); i++) {
//         IndividualCombo newCombo(1);
        
//     }
// }