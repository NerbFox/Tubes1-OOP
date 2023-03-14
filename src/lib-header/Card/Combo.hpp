#ifndef COMBO_HPP
#define COMBO_HPP
#include "../Player/Player.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/InventoryHolder.hpp"
#include <array>
#include <tuple>

class Combo : public BaseCard {
    protected:
        int comboId;
        vector<Card> finalSetCard;

    public:
        Combo(int comboId, Player player, TableCard tableCard);

        Combo(const Combo& other);

        int getComboId();

        void computeValue();

        
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