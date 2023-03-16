#include "../lib-header/Card/Combo.hpp"
#include "../lib-header/Player/Player.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
    if (comboId == 1) { // high card
        value = cardCombo[0].getValue();
    } else if (comboId == 2) { // pair
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33 + colorCode[cardCombo[1].getColor()] * 0.0033;
    } else if (comboId == 3) { // two pair
        value = 0.0;
        for (int i = 0; i < 4; i++) {
            value += cardCombo[i].getNumber() * pow(10, 12 - i*4) + colorCode[cardCombo[i].getColor()] * 33 * pow(10, 10 - i*4);
        }
    } else if (comboId == 4) { // three of a kind
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33;
        value += colorCode[cardCombo[1].getColor()] * 0.0033;
        value += colorCode[cardCombo[2].getColor()] * 0.000033;
    } else if (comboId == 5) { // straight
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()];
    } else if (comboId == 6) { // flush
        value = 0.0;
        for (int i = 0; i < cardCombo.size(); i++) {
            value += cardCombo[i].getNumber() * pow(10, 8 - i * 2);
        }
        value += colorCode[cardCombo[0].getColor()] * 0.33;
    } else if (comboId == 7) { // full house
        value = 0.0;
        for (int i = 0; i < 5; i++) {
            value += cardCombo[i].getNumber() * pow(10, 12 - i * 4) + colorCode[cardCombo[i].getColor()] * 33 * pow(10, 10 - i * 4);
        }
    } else if (comboId == 8) { // four of a kind
        value = cardCombo[0].getNumber();
    } else if (comboId == 9) { // straight flush
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33;
    }
}

Combo::Combo(){}

Combo::Combo(Player player, TableCard tableCard) {
    for (int i = 0; i < 2; i++) {
        finalSetCard.push_back(player.getNormalCard(i));
    }
    for (int i = 0; i < 6; i++) {
        finalSetCard.push_back(tableCard.getContainerAt(i));
    }

    sort(finalSetCard.begin(), finalSetCard.end(), [](Card a, Card b){return a > b;});
}

Combo::Combo(const Combo& other) {
    comboMax = other.comboMax;
    finalSetCard = other.finalSetCard;
    allCombo = other.allCombo;
}

IndividualCombo Combo::getComboMax() const {
    return comboMax;
}

vector<Card> Combo::getFinalSetCard() const {
    return finalSetCard;
}

vector<IndividualCombo> Combo::getAllCombo() const {
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

void Combo::setFinalSetCard(vector<Card> playerCard, vector<Card> tableCard) {
    copy(playerCard.begin(), playerCard.end(), back_inserter(finalSetCard));
    copy(tableCard.begin(), tableCard.end(), back_inserter(finalSetCard));
    sort(finalSetCard.begin(), finalSetCard.end(), [](Card a, Card b){return a > b;});
}

void Combo::clearFinalSetCard() {
    finalSetCard.clear();
}

void Combo::clearAllCombo() {
    allCombo.clear();
}

void Combo::resetValueMax() {
    comboMax = NULL;
}

void Combo::resetState() {
    clearFinalSetCard();
    clearAllCombo();
    resetValueMax();
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
                for (int l = k + 1; l < 7; l++) {
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
        for (int i = 0; i < pairComboVec.size() - 1; i++) {
            for (int j = i + 1; j < pairComboVec.size(); j++) {
                IndividualCombo newCombo(3);
                vector<Card> tempContainer;
                vector<Card> tempVec1 = pairComboVec[i].getCardCombo();
                vector<Card> tempVec2 = pairComboVec[j].getCardCombo();
                copy(tempVec1.begin(), tempVec1.end(), back_inserter(tempContainer));
                copy(tempVec2.begin(), tempVec2.end(), back_inserter(tempContainer));
                newCombo.insertCardCombo(tempContainer);
                newCombo.computeValue();
                allCombo.push_back(newCombo);
            }
        }
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
            for (int j = 0; j < pairComboVec.size(); j++) {
                IndividualCombo newCombo(7);
                vector<Card> tempContainer;
                vector<Card> tempVec1 = threeComboVec[i].getCardCombo();
                vector<Card> tempVec2 = pairComboVec[j].getCardCombo();
                copy(tempVec1.begin(), tempVec1.end(), back_inserter(tempContainer));
                copy(tempVec2.begin(), tempVec2.end(), back_inserter(tempContainer));
                newCombo.insertCardCombo(tempContainer);
                newCombo.computeValue();
                allCombo.push_back(newCombo);
            }
        }
    }
}

void Combo::generateHighCard() {
    for (int i = 0; i < finalSetCard.size(); i++) {
        IndividualCombo newCombo(1);
        vector<Card> tempContainer;
        tempContainer.push_back(finalSetCard[i]);
        newCombo.insertCardCombo(tempContainer);
        newCombo.computeValue();
        allCombo.push_back(newCombo);
    }
    sort(allCombo.begin(), allCombo.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
}

void Combo::computeValueMax() {
    sort(allCombo.begin(), allCombo.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
    comboMax = allCombo[0];
}

// int main() {
//     vector<Card> v1;
//     vector<Card> v2;
//     vector<Card> vt;

//     vector<IndividualCombo> ic;
//     Card c1(5, "merah");
//     Card c2(6, "merah");
//     Card c3(7, "merah");
//     Card c4(8, "merah");
//     Card c5(9, "merah");
//     Card c6(10, "merah");
//     Card c7(3, "biru");
//     Card c8(4, "kuning");
//     Card c9(5, "merah");
//     Card c10(6, "merah");
//     v1.push_back(c1);
//     v1.push_back(c2);
    
//     vt.push_back(c3);
//     vt.push_back(c4);
//     vt.push_back(c5);
//     vt.push_back(c6);
//     vt.push_back(c7);
//     vt.push_back(c8);

//     Combo testCombo;
//     testCombo.setFinalSetCard(v1, vt);
//     vector<Card> temp;
//     temp = testCombo.getFinalSetCard();
//     for (int i = 0; i < temp.size(); i++) {
//         cout << temp[i].getNumber() << " " << temp[i].getColor() << endl;
//     }

//     ic = testCombo.getAllCombo();
//     testCombo.checkPair();
//     ic = testCombo.getAllCombo();
//     testCombo.checkTwoPair();
//     ic = testCombo.getAllCombo();
//     testCombo.generateHighCard();
//     ic = testCombo.getAllCombo();
//     testCombo.checkThreeOfAKind();
//     ic = testCombo.getAllCombo();
//     testCombo.checkFullHouse();
//     ic = testCombo.getAllCombo();
//     testCombo.checkFourOfAKind();
//     ic = testCombo.getAllCombo();
//     testCombo.checkStraightAndFlush();
//     ic = testCombo.getAllCombo();
//     cout << "AAAA" << endl;
//     sort(ic.begin(), ic.end(), [](IndividualCombo combo1, IndividualCombo combo2){ return combo1 > combo2; });
//     for (int i = 0; i < ic.size(); i++) {
//         cout << "Combo ID: " << ic[i].getComboId() << endl;
//         vector<Card> temp1;
//         temp1 = ic[i].getCardCombo();
//         cout << "Cards:" << endl;
//         for (int j = 0; j < temp1.size(); j++) {
//             cout << temp1[j].getNumber() << " " << temp1[j].getColor() << endl;
//         }
//         cout << "Value: " << setprecision(20) << ic[i].getValue() << endl;
//         cout << endl;
//     }
// }