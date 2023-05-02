#ifndef OSAP_H
#define OSAP_H

#include "nonproperty.h"

class OSAP: public NonProperty {
public:
    OSAP(int position, std::string name): NonProperty(position, name) {}
    ~OSAP() {};
    int getNextMove() override {return 0;}

    int action(Player &p, int cup) override {
        if (p.getOSAPcollect()){
            p.addCash(200);
            std::cout << std::endl << "==> " << "You have arrived Collect OSAP, collected $200." << std::endl;
        }
        return cup;
    }
};

#endif

