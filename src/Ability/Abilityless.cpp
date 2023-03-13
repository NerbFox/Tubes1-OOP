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

}