#include <iostream>
#include "player.h"
#include "board.h"
using namespace std;

Player::Player(string name, char c): name{name}, nameChar{c}, cash{1500}, position{0}, OSAPcollect{false}, sentToDCTL{false}, DCTLtimes{0}, RUR_Cup{0} {
  ownBlock = {{"Arts1", 0}, {"Arts2", 0}, {"Eng", 0}, {"Health", 0}, {"Env", 0}, {"Sci1", 0}, {"Sci2", 0}, {"Math", 0}, {"Residence", 0}, {"Gym", 0}};
  //dice = make_shared<Dice>();
  // if (name == "Goose") nameChar = 'G';
  // if (name == "GRT Bus") nameChar = 'B';
  // if (name == "Tim Hortons Doughnut") nameChar = 'D';
  // if (name == "Professor") nameChar = 'P';
  // if (name == "Student") nameChar = 'S';
  // if (name == "Money") nameChar = '$';
  // if (name == "Laptop") nameChar = 'L';
  // if (name == "Pink tie") nameChar = 'T';
}

Player::Player(string name, char nameChar, int RUR_Cup, int cash, int position, bool sentToDCTL, int DCTLtimes): name{name}, nameChar{nameChar}, cash{cash}, position{position}, OSAPcollect{false}, sentToDCTL{sentToDCTL}, DCTLtimes{DCTLtimes}, RUR_Cup{RUR_Cup} {}

vector<shared_ptr<Board>> Player::getProperty(){
  return property;
}

Player::~Player() {
}


int Player::getCashAmount() {
  return cash;
}


int Player::getTotalWorth() {
  int total = cash;
  int p_len = property.size();
  for (int i = 0; i < p_len; ++i){
    total += property[i]->getPrice();
  } return total;
}


void Player::giveCash(shared_ptr<Player> other, int amount){
  other->addCash(amount);
  cash -= amount;
}


void Player::addProperties(shared_ptr<Board> b){
  property.emplace_back(b);
  string blockName = b->getBlock();
  for (auto& it: ownBlock) {
    if (it.first == blockName) {
      it.second++;
      // cout << blockName << " " << it.second << endl; //////
    }
  }
}


void Player::sellProperties (shared_ptr<Board> b) {
  int p_len = property.size();
  string blockName = b->getBlock();
  // delete from property
  for (int i = 0; i < p_len; i++){
    if (property[i] == b){
      property.erase(property.begin() + i);
      break;
    }
  }
  // delete from ownBlock
  for (auto& it: ownBlock) {
    if (it.first == blockName) {
      --it.second;
      if (it.second < 0) {
        cerr << endl << "==> Error: ownBlock < 0" << endl;
      }
    }
  }
}

int Player::getPosition() {
  return position;
}

void Player::setPosition(int position) {
  this->position = position;
}

void Player::addCash(int amount) {
  cash += amount;
}

string Player::getName() {
  return name;
}

char Player::getNameChar() {
  return nameChar;
}


bool Player::ifMonopoly(string type) {
  int target = 0;
  if (type == "Arts1" || type == "Math") {
    target = 2;
  } else {
    target = 3;
  }
  for (auto& it: ownBlock) {
    if (it.first == type && it.second == target) {
      return true;
    }
  }
  return false;
}


int Player::getResidenceNum() {
  int count = 0;
  int p_len =  property.size();
  for (int i = 0; i < p_len; i++){
    if (property[i]->getType() == "Residence") count++; 
  } return count;
}

bool Player::getOSAPcollect() {
  return OSAPcollect;
}

void Player::setOSAPcollect(bool boo) {
  OSAPcollect = boo;
}

bool Player::getsentToDCTL() {
  return sentToDCTL;
}

void Player::setsentToDCTL(bool boo) {
  sentToDCTL = boo;
}

int Player::getDCTLtimes() {
  return DCTLtimes;
}

void Player::setDCTLtimes(int times) {
  DCTLtimes = times;
}

int Player::getRURCup() {
  return RUR_Cup;
}

void Player::setRURCup(int cup) {
  RUR_Cup = cup;
}

int Player::getPropertySize(){
  return property.size();
}

int Player::getGymNum(){
  int count = 0;
  int p_len = property.size();
  for (int i = 0; i < p_len; i++){
    if (property[i]->getType() == "Gym") count++;
  } return count;
}



