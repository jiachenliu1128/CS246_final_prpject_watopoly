#include "academicbuilding.h"
using namespace std;


// details in academicbuilding.h
AcademicBuilding::AcademicBuilding(int position, string name, unsigned int purchasePrice, unsigned int visitPrice, vector<unsigned int> tut, int improvementCost, string monopolyBlock): 
  Property{position, name, purchasePrice, visitPrice}, tutWithImprove{tut}, improvementLevel{0}, improvementCost{improvementCost}, monopolyBlock{monopolyBlock} {}


// details in academicbuilding.h
AcademicBuilding::~AcademicBuilding() {}


// details in academicbuilding.h
void AcademicBuilding::setVisitPrice() {
  return;
}


// details in academicbuilding.h
int AcademicBuilding::getVisitPrice(Player& visitor) {
  if (isMortgaged()) return 0;
  if (owner.get() == &visitor || owner == nullptr) return 0;
  else return tutWithImprove[improvementLevel];
}


// details in academicbuilding.h
int AcademicBuilding::getPrice() const {
  return purchasePrice + improvementLevel * improvementCost; 
}


// details in academicbuilding.h
string AcademicBuilding::getBlock() const {
  return monopolyBlock;
}


// details in academicbuilding.h
int AcademicBuilding::getImproveLevel() const {
  return improvementLevel;
}


// details in academicbuilding.h
int AcademicBuilding::getImproveCost() const{
  return improvementCost;
}


// details in academicbuilding.h
void AcademicBuilding::improve() {
  improvementLevel++;
}


// details in academicbuilding.h
void AcademicBuilding::degrade() {
  improvementLevel--;
}


// details in academicbuilding.h
void AcademicBuilding::setImproveLevel(int level){
  improvementLevel = level;
}


