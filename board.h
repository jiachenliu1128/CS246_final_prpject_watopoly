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
  // ctor of Board
  Board(int position, std::string name);

  // dtor of Board
  virtual ~Board();

  // std::string getName() returns the name of the block on the Board
  // requires: None
  // effects: None
  std::string getName();

  // int getPosition() returns the number of position of the block on the Board
  // requires: None
  // effects: None
  int getPosition();

  // std::vector<std::shared_ptr<Player>> getCurPlayer() returns the current 
  //    players of the block on the Board
  // requires: None
  // effects: None
  std::vector<std::shared_ptr<Player>> getCurPlayer();

  // int getVisitorNum() returns how many players in the current block
  // requires: None
  // effects: None
  int getVisitorNum();

  // std::string getType() returns the type of the current block
  // requires: None
  // effects: None
  std::string getType();

  // virtual std::shared_ptr<Player> getOwner() const returns the owner of the 
  //    block
  // requires: None
  // effects: None
  virtual std::shared_ptr<Player> getOwner() const = 0;

  // virtual int getPrice() const returns the price to buy the block
  // requires: None
  // effects: None
  virtual int getPrice() const = 0;

  // virtual int getVisitPrice(Player& visitor) returns the price to visit the 
  //    block
  // requires: None
  // effects: None
  virtual int getVisitPrice(Player& visitor) = 0;

  // virtual void setOwner(std::shared_ptr<Player> owner) modifies the owner of 
  //    the block
  // requires: None
  // effects: modifies this
  virtual void setOwner(std::shared_ptr<Player> owner) = 0;

  // virtual int getImproveLevel() const returns the improvement level of the
  //    block
  // requires: None
  // effects: None
  virtual int getImproveLevel() const = 0;

  // virtual int getImproveCost() const returns the cost to add one improvement
  // requires: None
  // effects: None
  virtual int getImproveCost() const = 0;

  // virtual void improve() add one improvement level to the block
  // requires: None
  // effects: modifies this
  virtual void improve() = 0;

  // virtual void degrade() minus one improvement level to the block
  // requires: None
  // effects: None
  virtual void degrade() = 0;

  // virtual void changeMortgage() change the mortgage state of the block
  // requires: None
  // effects: modifies this
  virtual void changeMortgage() = 0; 

  // virtual bool isMortgaged() const returns whether this block is mortgaged
  // requires: None
  // effects: None
  virtual bool isMortgaged() const = 0;

  // virtual std::string getBlock() const returns the name of its monopoly block
  // requires: None
  // effects: None
  virtual std::string getBlock() const = 0;

  //virtual void setImproveLevel(int level) set the improvelent level of it to 
  //    level
  // requires: None
  // effects: modifies None
  virtual void setImproveLevel(int level) = 0;
};

#endif

