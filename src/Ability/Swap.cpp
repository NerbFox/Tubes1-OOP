#include "../lib-header/Ability/Swap.hpp"

Swap::Swap() {
    Ability::setType("Swap");
}

// action
void Swap::action(Game game){
    /* menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak 
    boleh ditukar dengan kartu main deck diri sendiri. */
    cout << "Swap diaktifkan" << endl;
    cout << "Pilih 2 pemain yang ingin ditukar kartunya: " << endl;
    

    
}