#include "property.h"
using namespace std;

// Property::Property(unsigned int purchasePrice, unsigned int visitPrice): owner{nullptr}, mortgage{false}, purchasePrice{purchasePrice}, visitPrice{visitPrice} {}
Property::Property(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice): Board{position, name}, owner{nullptr}, mortgage{false}, purchasePrice{purchasePrice}, visitPrice{visitPrice} {}


Property::~Property() {} //don't need delete

// void Property::setOwner(Player *owner) {
//   this->owner = owner;
// }
void Property::setOwner(shared_ptr<Player> owner)  {
  this->owner = owner;
}

// Player *Property::getOwner() {
//   return owner;
// }

shared_ptr<Player> Property::getOwner() const {
  return owner;
}

void Property::changeMortgage() {
  // change player money
  mortgage = !mortgage;
}

bool Property::isMortgaged() const {
  return mortgage;
}


