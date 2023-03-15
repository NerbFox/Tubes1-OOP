#include "../lib-header/Ability/Abilityless.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception//Exception.hpp"

Abilityless::Abilityless() {
    // Do nothing
    Ability::setType("ABILITYLESS");
}

Abilityless::~Abilityless() {
    // Do nothing
}

// action
void Abilityless::action(Game game) {
    /* mematikan kartu ability milik pemain lain. Harus digunakan saat giliran (preventif), tidak
     bisa mencegah seperti mematikan kartu ability ketika ada yang memakai. Sehingga, apabila
     semua pemain selain pemegang kemampuan ini sudah memakai kemampuan, maka secara tidak 
     langsung pemegang kemampuan ini terkena abilityless (karena semua kartu kemampuan sudah 
     dipakai) dan harus memilih aksi selain power.
    */
    game.playerPointer.first->setAbilityUsed(true);
    int indeksPemain = game.getIndexPlayerPointer();
    int i = 1;
    int pilihan;
    cout << "Abilityless diaktifkan" << endl;
    cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:\n";
    for (auto currentPair : game.playerQueue) {
        cout << i << ". " <<  currentPair.first.getName() << endl;
    }
    pilihan = 0;
    while (pilihan>7 || pilihan<1 || pilihan == indeksPemain) {
        try {
            cout << "\nPilih pemain: "; 
            cin >> pilihan;
            cout << endl;
            // check if the input is an integer
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256,'\n');
                throw NotIntegerException();
            }
            game.setAbilityUsedPlayer(pilihan-1, true);
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
        // if still error
        catch(...){
            cout << "Input tidak valid" << endl;
        }
    }
}