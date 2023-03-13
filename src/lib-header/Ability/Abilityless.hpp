#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP
#include "../lib-header/Command/Ability.hpp"

class Abilityless : public Ability {
    /* mematikan kartu ability milik pemain lain. Harus digunakan saat giliran (preventif), tidak
     bisa mencegah seperti mematikan kartu ability ketika ada yang memakai. Sehingga, apabila
     semua pemain selain pemegang kemampuan ini sudah memakai kemampuan, maka secara tidak 
     langsung pemegang kemampuan ini terkena abilityless (karena semua kartu kemampuan sudah 
     dipakai) dan harus memilih aksi selain power.
    */
   
    private:
    public:
        Abilityless();
        ~Abilityless();
        void action(Game game) = 0;        
};  


#endif