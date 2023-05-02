#ifndef GYM_H
#define GYM_H

#include "property.h"

class Gym: public Property {
public:
  Gym(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice);
  ~Gym();
  int getPrice() const override;
  // std::string getType() const;
  void setVisitPrice() override;
  int getVisitPrice(Player& visitor) override;
  int getImproveLevel() const override {return 0;}
  int getImproveCost() const override {return 0;}
  void improve() override {return;}
  void degrade() override {return;}
  std::string getBlock() const override {return "Gym";}
  void setImproveLevel(int level) override {return;}
};

#endif




