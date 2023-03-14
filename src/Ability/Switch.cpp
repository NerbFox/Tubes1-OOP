#include "../lib-header/Ability/Switch.hpp"

Switch::Switch()
{
    Ability::setType("SWICTH");
}

// action
void Switch::action(Game game)
{
    /* menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.
    Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain.
    */
    game.playerPointer.first->setAbilityUsed(true);
    cout << "Switch diaktifkan" << endl;
    cout << "Pilih pemain yang ingin ditukar kartunya: " << endl;

    // print playerQueue bertipe dequeue dari game 
    // dengan format no. nama pemain
    int pilihan;
    int i = 1;
    int indeksPemain = 0;
    for (auto currentPair : game.playerQueue) {
        if (currentPair.first.getName() != game.playerPointer.first->getName()) {
            indeksPemain = i-1;
        }
        cout << i << ". " <<  currentPair.first.getName() << endl;
    }
    cout << "Pilih pemain: ";
    cin >> pilihan;
    cout << endl;
    while (pilihan>7 || pilihan<1 || pilihan == indeksPemain) {
        cout << "Pilihan tidak valid. Pilih pemain: "; // throw exception
        cin >> pilihan;
        cout << endl;
    }
    // take 2 cards from the player's card deck and put it to the other player's card deck 
    pilihan--;
    Card card1 = game.playerPointer.first->getNormalCard(0);
    Card card2 = game.playerPointer.first->getNormalCard(1);
    Card card3 = game.playerQueue[pilihan].first.getNormalCard(0);
    Card card4 = game.playerQueue[pilihan].first.getNormalCard(1);
    game.playerPointer.first->setNormalCard(card3, 0);
    game.playerPointer.first->setNormalCard(card4, 1);
    game.playerQueue[pilihan].first.setNormalCard(card1, 0);
    game.playerQueue[pilihan].first.setNormalCard(card2, 1);

}