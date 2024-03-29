#include "../lib-header/Ability/Switch.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"

Switch::Switch()
{
    Ability::setType("SWITCH");
}
Switch::~Switch(){}

// action
void Switch::action(Game& game)
{
    /* menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.
    Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain.
    */
    game.playerPointer.first->setAbilityUsed(true);
    cout << "Switch diaktifkan" << endl;
    cout << "Pilih pemain yang ingin ditukar kartunya: " << endl;

    // print playerQueue bertipe dequeue dari game 
    // dengan format no. nama pemain
    int pilihan = 0;
    int i = 1;
    int indeksPemain = game.getIndexPlayerPointer();
    for (auto currentPair : game.playerQueue) {
        cout << i << ". " <<  currentPair.first->getName() << endl;
        i++;
    }
    while (pilihan>7 || pilihan<1 || pilihan-1 == indeksPemain) {
        try {
            cout << "\nPilih pemain: "; 
            cin >> pilihan;
            cout << endl;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
            else if (pilihan>7 || pilihan<1 ) {
                throw IndexOutOfBoundsException(pilihan, 7);
            }
            else if (pilihan-1 == indeksPemain) {
                throw IndexNotValidException(pilihan);
            }
        }
        catch (const IndexNotValidException &err) {
            cout << err.what() << endl;
        }
        catch (const IndexOutOfBoundsException &err){
            cout << err.what() << endl;
        }
        catch (const NotIntegerException &err){
            cout << err.what() << endl;
        }
    }
    // take 2 cards from the player's card deck and put it to the other player's card deck 
    pilihan--;
    Card card1 = game.playerPointer.first->getNormalCard(0);
    Card card2 = game.playerPointer.first->getNormalCard(1);
    Card card3 = game.playerQueue[pilihan].first->getNormalCard(0);
    Card card4 = game.playerQueue[pilihan].first->getNormalCard(1);
    game.playerPointer.first->setNormalCard(card3, 0);
    game.playerPointer.first->setNormalCard(card4, 1);
    game.playerQueue[pilihan].first->setNormalCard(card1, 0);
    game.playerQueue[pilihan].first->setNormalCard(card2, 1);
    cout << "Kartu berhasil ditukar" << endl;
    // print the result
    cout << "Kamu berhasil mendapatkan : " << endl; 
    // cout << "1. ";
    // game.playerPointer.first->getNormalCard(0).printCard();
    game.playerPointer.first->getNormalCard(0).printCard(game.playerPointer.first->getNormalCard(1));
    // cout << "2. ";
    // game.playerPointer.first->getNormalCard(1).printCard();
    cout << endl;
}