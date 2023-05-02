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
  AcademicBuilding(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice, std::vector<unsigned int> tut, int improvementCost, std::string monopolyBlock);
  ~AcademicBuilding();
  void setVisitPrice();
  int getVisitPrice(Player& visitor);
  int getPrice() const;
  // std::string getType() const;
  std::string getBlock() const;
  int getImproveLevel() const;
  int getImproveCost() const;
  void improve();
  void degrade();
  void setImproveLevel(int level);
};

#endif

