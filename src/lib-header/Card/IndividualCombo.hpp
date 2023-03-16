#ifndef INDIVIDUALCOMBO_HPP
#define INDIVIDUALCOMBO_HPP
#include "Card.hpp"
#include "BaseCard.hpp"
#include <vector>
#include <map>

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
#endif