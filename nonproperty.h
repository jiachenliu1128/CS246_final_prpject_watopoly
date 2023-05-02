#ifndef NONPROPERTY_H
#define NONPROPERTY_H

#include "board.h"
#include <string>
#include "player.h"
#include <memory>

class NonProperty: public Board {
public: 
  NonProperty(int position, std::string name): Board(position, name) {};
  virtual ~NonProperty() = 0;
  virtual int action(Player &p, int cup) = 0;
  virtual int getNextMove() = 0;
  std::shared_ptr<Player> getOwner() const override {return nullptr;}
  int getPrice() const override {return 0;}
  int getVisitPrice(Player& visitor) override {return 0;}
  void setOwner(std::shared_ptr<Player> owner) override {return;}
  int getImproveLevel() const override {return 0;}
  int getImproveCost() const override {return 0;}
  void improve() override {return;}
  void degrade() override {return;}
  void changeMortgage() override {return;}
  bool isMortgaged() const override {return 1;}
  std::string getBlock() const override{return "noBlock";}
  void setImproveLevel(int level) override {return;}

};

#endif

