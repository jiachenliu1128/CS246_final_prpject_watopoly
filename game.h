#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "board.h"
#include "player.h"
#include "dice.h"
#include "textdisplay.h"
#include "property.h"
#include "academicbuilding.h"
#include "residence.h"
#include "gym.h"
#include "nonproperty.h"
#include "slc.h"
#include "needlehall.h"
#include "osap.h"
#include "tuition.h"
#include "coopfee.h"
#include "gototims.h"
#include "goosenesting.h"
#include "dctimsline.h"
#include <fstream>


class Game {
  int activeRim;
  int doubleroll = 0;
  bool rolled = false;
  bool cannotRoll = false;
  std::vector<std::shared_ptr<Board>> board;
  std::vector<std::shared_ptr<Player>> player;
  std::unique_ptr<Dice> dice;
  std::shared_ptr<Player> currentPlayer;
public:
  // ctor of Game
  Game();

  // dtor of Game
  ~Game();

  // int roll() returns the value rolled by the dice
  // requires: None
  // effects: None
  int roll(); 

  // void gameStart() initializes the game
  // requires: None
  // effects: modifies this
  void gameStart();

  // Player& getCurrentPlayer() returns the player this turn
  // requires: None
  // effects: None
  Player& getCurrentPlayer();

  // bool endGame() return if the Game has ended
  // requires: None
  // effects: None
  bool endGame();

  // void printPlayers() prints all the current players
  // requires: None
  // effects: None
  void printPlayers();

  // std::string getWinner() returns the winner
  // requires: game is ended
  // effects: None
  std::string getWinner();

  // void move(int num, std::shared_ptr<Player> p = nullptr) move the player
  // requires: None
  // effects: modify this
  void move(int num, std::shared_ptr<Player> p = nullptr); 

  // void nextPlayer() move to the next player
  // requires: None
  // effects: modifies this
  void nextPlayer();

  // bool initPlayer(std::string name, char c) initialize a player
  // requires: None
  // effects: None
  bool initPlayer(std::string name, char c); 

  // std::shared_ptr<Player> getOwner(const Board& b) returns the owner of the 
  //    property
  // requires: None
  // effects: None
  std::shared_ptr<Player> getOwner(const Board& b);

  // void purchase(std::string b, Player& p) purchase the property
  // requires: None
  // effects: modifies this
  void purchase(std::string b, Player& p);

  // bool isValidPlayer(std::string name) returns if name is valid
  // requires: None
  // effects: None
  bool isValidPlayer(std::string name); 

  // bool isValidProperty(std::string bName) returns if property is valid
  // requires: None
  // effects: None
  bool isValidProperty(std::string bName); 

  // Player& getPlayer(std::string name) returns the player
  // requires: None
  // effects: None
  Player& getPlayer(std::string name); 

  // bool trade(Player& p, std::string b, unsigned int n) trade building with money
  // requires: None
  // effects; Modifies this
  bool trade(Player& p, std::string b, unsigned int n); 

  // bool trade(Player& p, std::string b_give, std::string b_receive) trade building with building
  // requires: None
  // effects: modifies this
  bool trade(Player& p, std::string b_give, std::string b_receive); 

  // bool trade(Player& p, unsigned int n, std::string b) trade money with building
  // requires: None
  // effects: modifies this
  bool trade(Player& p, unsigned int n, std::string b);  

  // bool improve(std::string b_name, bool improve) improves the property
  // requires: None
  // effects: Modifies this
  bool improve(std::string b_name, bool improve); 

  // bool mortgage(std::string b) mortgage the property
  // requires: None
  // effects: Modifies this
  bool mortgage(std::string b); 

  // bool unmortgage(std::string b) unmortgage the property
  // requires: None
  // effects: modiifes this
  bool unmortgage(std::string b); 

  // void removePlayer(std::string name) removes the player
  // requires: player exists
  // effects: modifies this
  void removePlayer(std::string name);

  // void asset() displays the asset of this player
  // requires: None
  // effects: None
  void asset(); 

  // void all() displays the assets of all players
  // requires: None
  // effects: None
  void all(); 

  // std::ofstream save(std::string filename) saves the game
  // requires: None
  // effects: None
  std::ofstream save(std::string filename);

  // void load(std::ifstream& f) load the game
  // requires: None
  // effects: Modifies this
  void load(std::ifstream& f);

  // void bankruptcy(std::string playerName,std::string owePlayer, int oweAmount) send player into the bankruptcy procedure
  // requires: player owes money
  // effects: modifies this
  void bankruptcy(std::string playerName,std::string owePlayer, int oweAmount);

  // int getActiverRim() returns the number of active rim cup
  // requires: None
  // effects: None
  int getActiverRim();

  // void setActiverRim(int n) set number of active rim cup to n
  // requires: None
  // effects: Modifies this
  void setActiverRim(int n);

  // void auction(std::string pro) start auction process
  // requires: None
  // effects: Modifies this
  void auction(std::string pro);

  // void printMap() prints the map
  // requires: None
  // effects: None
  void printMap();

  // int getdoubleroll() is getter of doubleroll
  // requires: None
  // effects: None
  int getdoubleroll() {
    return doubleroll;
  }

  // void setdoubleroll(int num) is setter of doubleroll
  // requires: None
  // effects: Modifies this
  void setdoubleroll(int num) {
    doubleroll = num;
  }

  // bool getrolled() is getter of rolled
  // requires: None
  // effects: None
  bool getrolled() {
    return rolled;
  }

  // void setrolled(bool flag) is setter of rolled
  // requires: None
  // effects: Modifies this
  void setrolled(bool flag) {
    rolled = flag;
  }

  // bool getcannotRoll() s getter of cannotroll
  // requires: None
  // effects: None
  bool getcannotRoll() {
    return cannotRoll;
  }

  // void setcannotRoll(bool flag) s setter of rolled
  // requires: None
  // effects: Modifies this
  void setcannotRoll(bool flag) {
    cannotRoll = flag;
  }
};

#endif

