#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "nonproperty.h"

class GooseNesting: public NonProperty {
public:
    GooseNesting(int position, std::string name): NonProperty(position, name) {}
    ~GooseNesting() {};
    int getNextMove() override {return 0;}

    int action(Player& p, int cup) override {
        std::cout << std::endl << "==> You have arrived at Goose Nesting" << std::endl;
        std::cout << std::endl << "==> " << "Attacked by a flock of nesting geese!!! Run!!!" << std::endl;
        return cup;
    }
};

#endif

