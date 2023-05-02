#ifndef GOTOTIMS_H
#define GOTOTIMS_H

#include "nonproperty.h"

class GoToTims: public NonProperty {
    int nextmove = 20;
public:
    GoToTims(int position, std::string name): NonProperty(position, name) {}
    ~GoToTims() {};

    int getNextMove() override {return nextmove;}
    
    int action(Player& p, int cup) override {
        p.setsentToDCTL(true);
        p.setDCTLtimes(0);
        p.setPosition(10);
        p.setOSAPcollect(false);
        std::cout << std::endl << "==> You have arrived at Go To Tims" << std::endl;
        std::cout << std::endl << "==> " << "You have been sent to DC Tims Line." << std::endl;
        return cup;
    }
};

#endif

