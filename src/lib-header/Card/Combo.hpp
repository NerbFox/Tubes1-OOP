#ifndef COMBO_HPP
#define COMBO_HPP
#include "../Inventory/TableCard.hpp"
#include "../Inventory/InventoryHolder.hpp"
#include "IndividualCombo.hpp"
#include <map>

class Player;

class Combo {
    private:
        IndividualCombo comboMax;
        vector<Card> finalSetCard;
        vector<IndividualCombo> allCombo;

    public:
        Combo();

        Combo(Player player, TableCard tableCard);

        Combo(const Combo& other);

        IndividualCombo getComboMax() const;

        vector<Card> getFinalSetCard() const;

        vector<IndividualCombo> getAllCombo() const;

        map<int, int> getCardFreqByNumber();

        map<string, int> getCardFreqByColor();

        map<int, int> getComboFreq();

        void setFinalSetCard(Player player, TableCard tableCard);

        void clearFinalSetCard();

        void clearAllCombo();

        void resetState();

        void checkPair();

        void checkTwoPair();

        void checkThreeOfAKind();

        void checkFullHouse();

        void checkFourOfAKind();

        void checkStraightAndFlush();

        bool isStraight(vector<Card>);

        bool isFlush(vector<Card>);

        void generateHighCard();

        void computeComboMax();
};  


#endif