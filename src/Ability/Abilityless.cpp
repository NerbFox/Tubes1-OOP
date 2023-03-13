#include "../lib-header/Ability/Abilityless.hpp"

Abilityless::Abilityless() {
    // Do nothing
    Ability::setType("Abilityless");
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
    


}