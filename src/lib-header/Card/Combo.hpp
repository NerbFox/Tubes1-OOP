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

        void setFinalSetCard(vector<Card> playerCard, vector<Card> tableCard);

        void clearFinalSetCard();

        void clearAllCombo();

        void resetValueMax();

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

        void computeValueMax();
};  


#endif