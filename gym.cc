#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "gym.h"
using namespace std;

Gym::Gym(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice): Property{position, name, purchasePrice, visitPrice} {}

Gym::~Gym() {}


int roll() {
  vector<int> v = { 1, 2, 3, 4, 5, 6};
  vector<int> s = {};
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
	default_random_engine rng{seed};
	for ( int i = 0; i < 1; i++ ) {
		//std::shuffle( v.begin(), v.end(), std::default_random_engine(seed) );
		std::shuffle( v.begin(), v.end(), rng );
		for ( int i : v ) s.emplace_back(i);
	} 
	return s[0];
}


int Gym::getPrice() const {
  return purchasePrice;
}


int Gym::getVisitPrice(Player& visitor) {
  if (isMortgaged()) return 0;
  if (owner.get() == &visitor || owner == nullptr) return 0;
  else {
    setVisitPrice();
    return visitPrice;
  }
}

void Gym::setVisitPrice(){
  int price1 = roll();
  int price2 = roll();
  cout << std::endl << "==> " << "Roll result: " << price1 << " " << price2 << " " << endl;
  int price = price1 + price2;
  int count = owner->getGymNum();
  if (count == 1) visitPrice = price * 4;
  else if (count == 2) visitPrice = price * 10;
}




