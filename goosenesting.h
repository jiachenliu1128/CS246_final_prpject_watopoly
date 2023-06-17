#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "nonproperty.h"

class GooseNesting: public NonProperty {
public:

    // ctor of GooseNesting
    GooseNesting(int position, std::string name): NonProperty(position, name) {}

    // dtor of GooseNesting
    ~GooseNesting() {};

    // int getNextMove() returns the steps of next move
    // requires: None
    // effects: None
    int getNextMove() override {return 0;}

    // int action(Player& p, int cup) do the action of GooseNesting
    // requires: None
    // effects: None
    int action(Player& p, int cup) override {
        std::cout << std::endl << "==> You have arrived at Goose Nesting" << std::endl;
        std::cout << std::endl << "==> " << "Attacked by a flock of nesting geese!!! Run!!!" << std::endl;
        return cup;
    }
};

#endif

