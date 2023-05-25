#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "property.h"
#include "player.h"
#include <string>

class AcademicBuilding: public Property {
  std::vector<unsigned int> tutWithImprove;
  int improvementLevel;
  int improvementCost;
  std::string monopolyBlock;

public:
  // ctor of AcademicBuilding
  AcademicBuilding(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice, std::vector<unsigned int> tut, int improvementCost, std::string monopolyBlock);

  // dtor of AcademicBuilding
  ~AcademicBuilding();

  // void setVisitPrice() sets the visit price of this
  // requires: None
  // effects: modifies this
  void setVisitPrice();

  // int getVisitPrice() gets the visit price of this
  // requires: None
  // effects: None
  int getVisitPrice(Player& visitor);

  // int getPrice() gets the price to buy this
  // requires: None
  // effects: None
  int getPrice() const;

  // std::string getBlock() const returns the monopoly block name of this
  // requires: None
  // effects: None
  std::string getBlock() const;

  // int getImproveLevel() const returns the inprovement level of this
  // requires: None
  // effects: None
  int getImproveLevel() const;
  
  // int getImproveCost() const returns the cost to improve a level
  // requires: None
  // effects: None
  int getImproveCost() const;

  // void improve() add one level to the improvement
  // requires: None
  // effects: modify this
  void improve();

  // void degrade() minus one level to the improvement
  // requires: None
  // effects: modify this
  void degrade();

  // void setImprovementLevel(int level) set the ImprovementLevel of this to 
  //    [level]
  // requires: None
  // effects: modify this
  void setImproveLevel(int level);
};

#endif

