#include "../lib-header/Ability/Swap.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"

Swap::Swap() {
    Ability::setType("SWAP");
}

// action
void Swap::action(Game game){
    /* menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak 
    boleh ditukar dengan kartu main deck diri sendiri. */
    game.playerPointer.first->setAbilityUsed(true);
    cout << "Swap diaktifkan" << endl;
    cout << "Pilih 2 pemain yang ingin ditukar kartunya: " << endl;
    int pilihanP1 = 0;
    int pilihanP2 = 0;
    int i = 1;
    int indeksPemain = 0;
    int pilihanKartuP1 = 0;
    int pilihanKartuP2 = 0;
    for (auto currentPair : game.playerQueue) {
        if (currentPair.first->getName() != game.playerPointer.first->getName()) {
            indeksPemain = i-1;
        }
        cout << i << ". " <<  currentPair.first->getName() << endl;
    }
    
    while (pilihanP1>7 || pilihanP1<1 || pilihanP1 == indeksPemain) {
        try{
            // cout << "Tidak boleh menukar kartu sendiri.\n";
            cout << "Pilih pemain pertama: ";
            cin >> pilihanP1; cout << endl;
            // if pilihan not an integer
            if(cin.fail()){
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
            if(pilihanP1>7 || pilihanP1<1){
                throw IndexOutOfBoundsException(pilihanP1, 7);
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
        catch(...){
            cout << "Input tidak valid" << endl;
        }
    }   
    while (pilihanP2>7 || pilihanP2<1 || pilihanP2 == indeksPemain || pilihanP2 == pilihanP1) {
        try{
            // cout << "Tidak boleh menukar kartu sendiri.\n";
            cout << "Pilih pemain kedua: ";
            cin >> pilihanP2; cout << endl;
            if(pilihanP2>7 || pilihanP2<1){
                throw IndexOutOfBoundsException(pilihanP2, 7);
            }
            if (pilihanP2 == indeksPemain) {
                throw IndexNotValidException(pilihanP2);
            }
            if (pilihanP2 == pilihanP1) {
                throw SameIndexException(pilihanP2);
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
        }
        catch (const IndexNotValidException &err) {
            cout << err.what() << endl;
        }
        catch (const IndexOutOfBoundsException &err){
            cout << err.what() << endl;
        }
        catch (const SameIndexException &err){
            cout << err.what() << endl;
        }
        catch (const NotIntegerException &err){
            cout << err.what() << endl;
        }
        catch(...){
            cout << "Input tidak valid" << endl;
        }
    }
    // take 1 cards from the player's card deck and put it to the other player's card deck
    cout << "Pilih kartu yang ingin ditukar: " << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;
    while (pilihanKartuP1 != 1 || pilihanKartuP1!=2){
        try {
            cout << "Pilih kartu pemain pertama: ";
            cin >> pilihanKartuP1; cout << endl;
            if (pilihanKartuP1 != 1 || pilihanKartuP1!=2) {
                throw IndexOutOfBoundsException(pilihanKartuP1, 2);
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
        }
        catch (const IndexOutOfBoundsException &err) {
            cout << err.what() << endl;
        }   
        catch (const NotIntegerException &err){
            cout << err.what() << endl;
        }
        catch(...){
            cout << "Input tidak valid" << endl;
        }
    }
    while (pilihanKartuP2 != 1 || pilihanKartuP2!=2){
        try {
            cout << "Pilih kartu pemain kedua: ";
            cin >> pilihanKartuP2; cout << endl;
            if (pilihanKartuP2 != 1 || pilihanKartuP2!=2) {
                throw IndexOutOfBoundsException(pilihanKartuP2, 2);
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
        }
        catch (const IndexOutOfBoundsException &err) {
            cout << err.what() << endl;
        }   
        catch (const NotIntegerException &err){
            cout << err.what() << endl;
        }
        catch(...){
            cout << "Input tidak valid" << endl;
        }
    }
    pilihanKartuP1--; pilihanKartuP2--; pilihanP1--; pilihanP2--;
    Card card1 = game.playerQueue[pilihanP1].first->getNormalCard(pilihanKartuP1);
    Card card2 = game.playerQueue[pilihanP2].first->getNormalCard(pilihanKartuP2);
    // cek apakah kartu yang di ubah adalah kartu yang dipilih
    game.playerQueue[pilihanP1].first->setNormalCard(card2, pilihanKartuP1);
    game.playerQueue[pilihanP2].first->setNormalCard(card1, pilihanKartuP2);
}