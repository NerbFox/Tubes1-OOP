#include "../lib-header/Inventory/TableCard.hpp"
#include <iostream>
#include "../Card/colors.hpp"
#include <iomanip>

// ctor
TableCard::TableCard() : InventoryHolder{} {}

// method for adding a card to an empty slot.
void TableCard::operator+(const Card& newCard) {
  cardContainer.push_back(newCard);
}

// Method to remove the first card from container n times.
void TableCard::operator-(int n) {
  if (n > cardContainer.size()) {
    throw "number of cards will be removed is bigger than the number of cards in the table card\n";
  }

  for (int i = 0; i < n; i++) {
    cardContainer.erase(cardContainer.begin());
  }
}

Card TableCard::getContainerAt(int index) {
  return cardContainer[index];
}


// print cards in the container
void TableCard::printCards() const{
  if(cardContainer.size() == 1){
    // cardContainer[0].printCard();
    // cout << "1. Kartu " << cardContainer[0].getNumber() << " " << cardContainer[0].getColor() << endl;
    string c1;
    c1 = getCardColor(cardContainer[0].getColor());
    cout << c1 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << cardContainer[0].getNumber() << "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << cardContainer[0].getNumber() << "|" << endl;
    cout << c1 << "'---------'" << endl;
    cout << RESET;
  }
  else if (cardContainer.size()==2){
    // cardContainer[0].printCard(cardContainer[1]);
    // cout << "1. Kartu " << cardContainer[0].getNumber() << " " << cardContainer[0].getColor() << endl;
    // cout << "2. Kartu " << cardContainer[1].getNumber() << " " << cardContainer[1].getColor() << endl;
    string c1, c2;
    c1 = getCardColor(cardContainer[0].getColor());
    c2 = getCardColor(cardContainer[1].getColor());

    cout << c1 << ".---------." << "\t" << c2 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << left << cardContainer[1].getNumber()<< "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << "\t" << c2 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << right << cardContainer[1].getNumber() << "|" << endl;
    cout << c1 << "'---------'" << "\t" << c2 << "'---------'" << endl;

    cout << RESET;
  }
  else if (cardContainer.size()==3){
    // cout << "1. Kartu " << cardContainer[0].getNumber() << " " << cardContainer[0].getColor() << endl;
    // cout << "2. Kartu " << cardContainer[1].getNumber() << " " << cardContainer[1].getColor() << endl;
    // cout << "3. Kartu " << cardContainer[2].getNumber() << " " << cardContainer[2].getColor() << endl;
    string c1, c2, c3;
    c1 = getCardColor(cardContainer[0].getColor());
    c2 = getCardColor(cardContainer[1].getColor());
    c3 = getCardColor(cardContainer[2].getColor());

    cout << c1 << ".---------." << "\t" << c2 << ".---------." << "\t" << c3 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << left << cardContainer[1].getNumber()<< "|" << "\t" << c3 << "|" << setw(9) << left << cardContainer[2].getNumber()<< "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << "\t" << c2 << "|         |" << "\t" << c3 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << right << cardContainer[1].getNumber() << "|" << "\t" << c3 << "|" << setw(9) << right << cardContainer[2].getNumber() << "|" << endl;
    cout << c1 << "'---------'" << "\t" << c2 << "'---------'" << "\t" << c3 << "'---------'" << endl;

    cout << RESET;
  }
  else if (cardContainer.size()==4){
    // cout << "1. Kartu " << cardContainer[0].getNumber() << " " << cardContainer[0].getColor() << endl;
    // cout << "2. Kartu " << cardContainer[1].getNumber() << " " << cardContainer[1].getColor() << endl;
    // cout << "3. Kartu " << cardContainer[2].getNumber() << " " << cardContainer[2].getColor() << endl;
    // cout << "4. Kartu " << cardContainer[3].getNumber() << " " << cardContainer[3].getColor() << endl;
    string c1, c2, c3, c4;
    c1 = getCardColor(cardContainer[0].getColor());
    c2 = getCardColor(cardContainer[1].getColor());
    c3 = getCardColor(cardContainer[2].getColor());
    c4 = getCardColor(cardContainer[3].getColor());

    cout << c1 << ".---------." << "\t" << c2 << ".---------." << "\t" << c3 << ".---------." << "\t" << c4 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << left << cardContainer[1].getNumber()<< "|" << "\t" << c3 << "|" << setw(9) << left << cardContainer[2].getNumber()<< "|" << "\t" << c4 << "|" << setw(9) << left << cardContainer[3].getNumber()<< "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << "\t" << c2 << "|         |" << "\t" << c3 << "|         |" << "\t" << c4 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << right << cardContainer[1].getNumber() << "|" << "\t" << c3 << "|" << setw(9) << right << cardContainer[2].getNumber() << "|" << "\t" << c4 << "|" << setw(9) << right << cardContainer[3].getNumber() << "|" << endl;
    cout << c1 << "'---------'" << "\t" << c2 << "'---------'" << "\t" << c3 << "'---------'" << "\t" << c4 << "'---------'" << endl;
    cout << RESET;
  }
  else if (cardContainer.size()==5){
    // cout << "1. Kartu " << cardContainer[0].getNumber() << " " << cardContainer[0].getColor() << endl;
    // cout << "2. Kartu " << cardContainer[1].getNumber() << " " << cardContainer[1].getColor() << endl;
    // cout << "3. Kartu " << cardContainer[2].getNumber() << " " << cardContainer[2].getColor() << endl;
    // cout << "4. Kartu " << cardContainer[3].getNumber() << " " << cardContainer[3].getColor() << endl;
    // cout << "5. Kartu " << cardContainer[4].getNumber() << " " << cardContainer[4].getColor() << endl;
    string c1, c2, c3, c4, c5;
    c1 = getCardColor(cardContainer[0].getColor());
    c2 = getCardColor(cardContainer[1].getColor());
    c3 = getCardColor(cardContainer[2].getColor());
    c4 = getCardColor(cardContainer[3].getColor());
    c5 = getCardColor(cardContainer[4].getColor());

    cout << c1 << ".---------." << "\t" << c2 << ".---------." << "\t" << c3 << ".---------." << "\t" << c4 << ".---------." << "\t" << c5 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << left << cardContainer[1].getNumber()<< "|" << "\t" << c3 << "|" << setw(9) << left << cardContainer[2].getNumber()<< "|" << "\t" << c4 << "|" << setw(9) << left << cardContainer[3].getNumber()<< "|" << "\t" << c5 << "|" << setw(9) << left << cardContainer[4].getNumber()<< "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << "\t" << c2 << "|         |" << "\t" << c3 << "|         |" << "\t" << c4 << "|         |" << "\t" << c5 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << cardContainer[0].getNumber() << "|" << "\t" << c2 << "|" << setw(9) << right << cardContainer[1].getNumber() << "|" << "\t" << c3 << "|" << setw(9) << right << cardContainer[2].getNumber() << "|" << "\t" << c4 << "|" << setw(9) << right << cardContainer[3].getNumber() << "|" << "\t" << c5 << "|" << setw(9) << right << cardContainer[4].getNumber() << "|" << endl;
    cout << c1 << "'---------'" << "\t" << c2 << "'---------'" << "\t" << c3 << "'---------'" << "\t" << c4 << "'---------'" << "\t" << c5 << "'---------'" << endl;
    cout << RESET;
  }
}

string TableCard::getCardColor(string color) const{
   if (color == "merah")
      {
          return RED;
      }
      else if (color == "hijau")
      {
          return GREEN;
      }
      else if (color == "kuning")
      {
          return YELLOW;
      }
      else if (color == "biru")
      {
          return BLUE;
      }
}
