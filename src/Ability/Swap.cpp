#include "../lib-header/Ability/Swap.hpp"

Swap::Swap() {
    Ability::setType("Swap");
}

// action
void Swap::action(Game game){
    /* menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak 
    boleh ditukar dengan kartu main deck diri sendiri. */
    game.playerPointer.first->setAbilityUsed(true);
    cout << "Swap diaktifkan" << endl;
    cout << "Pilih 2 pemain yang ingin ditukar kartunya: " << endl;
    int pilihanP1;
    int pilihanP2;
    int i = 1;
    int indeksPemain = 0;
    int pilihanKartuP1;
    int pilihanKartuP2;
    for (auto currentPair : game.playerQueue) {
        if (currentPair.first.getName() != game.playerPointer.first->getName()) {
            indeksPemain = i-1;
        }
        cout << i << ". " <<  currentPair.first.getName() << endl;
    }
    cout << "Pilih pemain pertama: ";
    cin >> pilihanP1; cout << endl;
    cout << "Pilih pemain kedua: ";
    cin >> pilihanP2; cout << endl;
    
    while (pilihanP1>7 || pilihanP1<1 || (pilihanP1 == indeksPemain || pilihanP2 == indeksPemain) ||  pilihanP2 == pilihanP1 ) {
        cout << "Pilihan tidak valid!\n";
        cout << "Tidak boleh menukar kartu sendiri.\n";
        cout << "Pilih pemain pertama: ";
        cin >> pilihanP1; cout << endl;
        cout << "Pilih pemain kedua: ";
        cin >> pilihanP2; cout << endl;
        cout << endl;
    }   
    // take 1 cards from the player's card deck and put it to the other player's card deck
    cout << "Pilih kartu yang ingin ditukar: " << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;
    cout << "Pemain pertama: " << endl;
    cin >> pilihanKartuP1; cout << endl;
    cout << "Pemain kedua: " << endl;
    cin >> pilihanKartuP2; cout << endl;
    while (pilihanKartuP1 != 1 || pilihanKartuP1!=2 || pilihanKartuP2 !=1 || pilihanKartuP2 !=2){
        cout << "Pilihan tidak valid!\n"; // nanti pakai exception
        cout << "Pemain pertama: " << endl;
        cin >> pilihanKartuP1; cout << endl;
        cout << "Pemain kedua: " << endl;
        cin >> pilihanKartuP2; cout << endl;
    }
    Card card1 = game.playerQueue[pilihanP1-1].first.getNormalCard(pilihanKartuP1-1);
    Card card2 = game.playerQueue[pilihanP2-1].first.getNormalCard(pilihanKartuP2-1);
    // cek apakah kartu yang di ubah adalah kartu yang dipilih
    game.playerQueue[pilihanP1-1].first.setNormalCard(card2, pilihanKartuP1-1);
    game.playerQueue[pilihanP2-1].first.setNormalCard(card1, pilihanKartuP2-1);
}