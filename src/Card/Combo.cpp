#include "../lib-header/Card/Combo.hpp"
#include "../lib-header/Player/Player.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

Combo::Combo(int comboId, Player player, TableCard tableCard) : comboId(comboId) {
    for (int i = 0; i < 2; i++) {
        finalSetCard.push_back(player.getNormalCard(i));
    }
    for (int i = 0; i < 6; i++) {
        finalSetCard.push_back(tableCard.getContainerAt(i));
    }

    sort(finalSetCard.begin(), finalSetCard.end(), [](Card a, Card b){return a > b;});
}

Combo::Combo(const Combo& other) {
    value = other.value;
    comboId = other.comboId;
    finalSetCard = other.finalSetCard;
}

int Combo::getComboId() {
    return comboId;
}

vector<Card> Combo::getFinalSetCard() {
    return finalSetCard;
}

vector<tuple<vector<Card>, int, float>> Combo::getAllCombo() {
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
        if (freqCombo.find(get<1>(allCombo[i])) == freqCombo.end()) {
            freqCombo[get<1>(allCombo[i])] = 1;
        } else {
            freqCombo[get<1>(allCombo[i])]++;
        }
    }
    return freqCombo;
}

void Combo::checkPair() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 2) {
            vector<Card> pairSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(pairSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            float valuePair = pairSetCard[0].getNumber() + colorCode[pairSetCard[0].getColor()] * 0.33 + colorCode[pairSetCard[1].getColor()] * 0.0033;
            allCombo.push_back(make_tuple(pairSetCard, 2, valuePair));
        }
    }
}

void Combo::checkThreeOfAKind() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 3) {
            vector<Card> threeSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(threeSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            float valuePair = threeSetCard[0].getNumber();
            allCombo.push_back(make_tuple(threeSetCard, 4, valuePair));
        }
    }
}

void Combo::checkFourOfAKind() {
    map<int, int> freqNum = getCardFreqByNumber();
    for (auto it = freqNum.begin(); it != freqNum.end(); it++) {
        if (it->second == 4) {
            vector<Card> fourSetCard;
            int numCheck = it->first;
            copy_if(finalSetCard.begin(), finalSetCard.end(), back_inserter(fourSetCard), [numCheck](Card c){ return c.getNumber() == numCheck; });
            float valuePair = fourSetCard[0].getNumber();
            allCombo.push_back(make_tuple(fourSetCard, 8, valuePair));
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

void Combo::sortAllCombo() {
    
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
                            float valueSet = fiveSetCard[0].getNumber() + colorCode[fiveSetCard[0].getColor()] * 0.33;
                            allCombo.push_back(make_tuple(fiveSetCard, 9, valueSet));
                        } else if (isStraight(fiveSetCard)) {
                            float valueSet = fiveSetCard[0].getNumber();
                            allCombo.push_back(make_tuple(fiveSetCard, 5, valueSet));
                        } else if (isFlush(fiveSetCard)) {
                            float valueSet = 0.0f;
                            for (int i = 0; i < fiveSetCard.size(); i++) {
                                value += fiveSetCard[fiveSetCard.size() - 1 - i].getNumber() * (pow(100, i));
                            }   
                            valueSet += colorCode[fiveSetCard[0].getColor()] * 0.33;
                            allCombo.push_back(make_tuple(fiveSetCard, 6, valueSet));
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
    
    // for (int i = 0; i < finalSetCard.size() - 4; i++) {
    //     bool isStraight = true;
    //     bool isFlush = true;
    //     vector<Card> fiveSetCard;
    //     for (int j = 0; j < finalSetCard.size() - 1; j++) {
    //         if (finalSetCard[j].getNumber() <= finalSetCard[j + 1].getNumber()) {
    //             isStraight = false;
    //         }
    //         if (finalSetCard[j].getColor() != finalSetCard[j + 1].getColor()) {
    //             isFlush = false;
    //         }
    //         fiveSetCard.push_back(finalSetCard[j]);
    //     }

    //     if (isStraight && isFlush) {
    //         float valueSet = fiveSetCard[0].getNumber() + colorCode[fiveSetCard[0].getColor()] * 0.33;
    //         allCombo.push_back(make_tuple(fiveSetCard, 5, valueSet));
    //     } else if (isStraight) {
    //         float valueSet = fiveSetCard[0].getNumber();
    //         allCombo.push_back(make_tuple(fiveSetCard, 5, valueSet));
    //     } else if (isFlush) {
    //         float valueSet = 0.0f;
    //         for (int i = 0; i < fiveSetCard.size(); i++) {
    //             value += fiveSetCard[fiveSetCard.size() - 1 - i].getNumber() * (pow(100, i));
    //         }   
    //         valueSet += colorCode[fiveSetCard[0].getColor()] * 0.33;
    //         allCombo.push_back(make_tuple(fiveSetCard, 6, valueSet));
    //     }
    // }
}

void Combo::checkTwoPair() {
    map<int, int> freqCombo = getComboFreq();
    if (freqCombo[2] > 1) {

    }
}

// INCOMPLETE
// void getAllCardCombination(vector<Card> setCard) {

// }

// void combinationUtil(vector<Card> setCard, int comboSize, int index, vector<Card> temp, int i) {
//     if (index == comboSize) {
        
//         return;
//     }

//     if (i >= setCard.size())
//         return;
 
//     temp[index] = setCard[i];
//     combinationUtil(setCard, comboSize, index + 1, temp, i + 1);
//     combinationUtil(setCard, comboSize, index, temp, i + 1);
// }
 
// void printCombination(vector<Card> setCard, int n, int comboSize) {
//     vector<Card> temp(comboSize);
//     combinationUtil(setCard, comboSize, 0, temp, 0);
// }

// INCOMPLETE
void Combo::computeValue() {
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
        map<int, int> freqNum = getCardFreqByNumber();
        value = 0;
    } else if (comboId == 8) { // four of a kind
        value = cardCombo[0].getNumber();
    } else if (comboId == 9) { // straight flush
        value = cardCombo[0].getNumber() + colorCode[cardCombo[0].getColor()] * 0.33;
    }
}