#ifndef COMBO_HPP
#define COMBO_HPP
#include "../Inventory/TableCard.hpp"
#include "../Inventory/InventoryHolder.hpp"
#include "BaseCard.hpp"
#include <map>
#include <tuple>

class Player;

class IndividualCombo : public BaseCard {
    private:
        int comboId;
        vector<Card> cardCombo;
    public:
        IndividualCombo();

        IndividualCombo(int);

        int getComboId();

        vector<Card> getCardCombo();

        void insertCardCombo(const vector<Card>);

        bool operator<(const IndividualCombo&);

        bool operator>(const IndividualCombo&);

        bool operator==(const IndividualCombo&);

        bool operator!=(const IndividualCombo&);

        void computeValue();

};

class Combo {
    private:
        float valueMax;
        vector<Card> finalSetCard;
        // vector<tuple<vector<Card>, int, float>> allCombo;
        vector<IndividualCombo> allCombo;

    public:
        Combo(Player player, TableCard tableCard);

        Combo(const Combo& other);

        vector<Card> getFinalSetCard();

        vector<IndividualCombo> getAllCombo();

        map<int, int> getCardFreqByNumber();

        map<string, int> getCardFreqByColor();

        map<int, int> getComboFreq();

        void checkPair();

        void checkTwoPair();

        void checkThreeOfAKind();

        void checkFullHouse();

        void checkFourOfAKind();

        void checkStraightAndFlush();

        bool isStraight(vector<Card>);

        bool isFlush(vector<Card>);

        // void generateHighCard();

        void computeMaxValue();
        
    // 1 kartu
    // High card
    
    // 2 kartu
    // Pair, Two Pair

    // 3 kartu
    // Three of a kind

    // 3 kartu dan 2 kartu
    // full house

    // 4 kartu
    // Four of a kind

    // 5 kartu
    // Flush, straight flush, straight



};  


#endif