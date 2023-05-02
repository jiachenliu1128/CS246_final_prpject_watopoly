#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <memory>
#include "player.h"
class Player;

class Board {
  int position;
  std::string name;
  std::string type;
  std::vector<std::shared_ptr<Player>> curPlayer;
public:
  Board(int position, std::string name);
  virtual ~Board();
  std::string getName();
  int getPosition();
  std::vector<std::shared_ptr<Player>> getCurPlayer();
  int getVisitorNum();
  std::string getType();
  virtual std::shared_ptr<Player> getOwner() const = 0;
  virtual int getPrice() const = 0;
  virtual int getVisitPrice(Player& visitor) = 0;
  virtual void setOwner(std::shared_ptr<Player> owner) = 0;
  virtual int getImproveLevel() const = 0;
  virtual int getImproveCost() const = 0;
  virtual void improve() = 0;
  virtual void degrade() = 0;
  virtual void changeMortgage() = 0; 
  virtual bool isMortgaged() const = 0;
  virtual std::string getBlock() const = 0;
  virtual void setImproveLevel(int level) = 0;
};

#endif

