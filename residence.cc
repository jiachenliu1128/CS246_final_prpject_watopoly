#include "residence.h"
using namespace std;


Residence::Residence(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice): Property{position, name, purchasePrice, visitPrice} {}

Residence::~Residence() {}

int Residence::getPrice() const{
  return purchasePrice;
}


// string Residence::getType() {
//   // return "Residence";
//   return type;
// }
void Residence::setVisitPrice(){
  int count = owner->getResidenceNum();
  if (count == 1) visitPrice = 25;
  else if (count == 2) visitPrice = 50;
  else if (count == 3) visitPrice = 100;
  else if (count == 4) visitPrice = 200;
}


int Residence::getVisitPrice(Player& visitor) {
  setVisitPrice();
  if (isMortgaged()) return 0;
  if (owner->getName() == visitor.getName() || owner == nullptr) return 0;
  return visitPrice;
}



