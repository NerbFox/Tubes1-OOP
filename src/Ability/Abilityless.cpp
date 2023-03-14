#include "../lib-header/Ability/Abilityless.hpp"

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
    int indeksPemain = 0;
    int i = 1;
    int pilihan;
    cout << "Abilityless diaktifkan" << endl;
    cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:\n";
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
        // exception with class IndexNotValidException
        // IndexNotValidException I(pilihan);
        // IndexOutOfBoundsException I2(pilihan, 7);
        try {
            cout << "\nPilih pemain: "; 
            cin >> pilihan;
            cout << endl;
            game.setAbilityUsedPlayer(pilihan-1, true);
        }
        catch (const IndexNotValidException &err) {
            cout << err.what() << endl;
        }
        catch (const IndexOutOfBoundsException &err){
            cout << err.what() << endl;
        }
    }
}