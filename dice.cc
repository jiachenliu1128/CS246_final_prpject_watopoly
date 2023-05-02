#include "dice.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

int Dice::rollDice() {
	vector<int> v = { 1, 2, 3, 4, 5, 6};
  	vector<int> s = {};
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
	default_random_engine rng{seed};
	for ( int i = 0; i < 1; i++ ) {
		std::shuffle( v.begin(), v.end(), rng );
		for ( int i : v ) s.emplace_back(i);
	} 
	return s[0];
} // main



