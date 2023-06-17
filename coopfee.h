#ifndef COOPFEE_H
#define COOPFEE_H

#include "nonproperty.h"

class CoopFee: public NonProperty {
public:
    // ctor of CoopFee
    CoopFee(int position, std::string name): NonProperty(position, name) {}

    // dtor of CoopFee
    ~CoopFee() {};

    // int getNextMove() override returns the number of move of next step
    // requires: None
    // effects: None
    int getNextMove() override {return 0;}

    // int action(Player& p, int cup) override do the action when player land on
    //      CoopFee
    // requires: None
    // effects: modifies player
    int action(Player& p, int cup) override {
        std::cout << std::endl << "==> You have arrived at Coop Fee" << std::endl;
        p.addCash(-150);
        std::cout << std::endl << "==> You have paid $150 for the Coop Fee." << std::endl;
        return cup;
    }
};

#endif

