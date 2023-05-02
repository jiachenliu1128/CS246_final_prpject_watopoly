#ifndef NEEDLEHALL_H
#define NEEDLEHALL_H

#include "nonproperty.h"
#include <ctime>
#include <cstdlib>


class NeedleHall: public NonProperty {
    int roll(int n) {
        srand(static_cast<unsigned>(time(0)));
        int randnum = rand() % n + 1;
        return randnum;
    }
public:
    NeedleHall(int position, std::string name): NonProperty(position, name) {}
    ~NeedleHall() {};
    int getNextMove() override {return 0;}
    int action(Player& p, int cup) override {
        std::cout << std::endl << "==> You have arrived at Needles Hall" << std::endl;
        if (cup < 4) {
            int ran = roll(100);
            if (ran == 1) {
                int tmp = p.getRURCup();
                p.setRURCup(tmp + 1);
                std::cout << std::endl << "==> " << "You gained a Roll Up the Rim cup at Needles Hall." << std::endl;
                return cup + 1;
            }
        }
        int rand = roll(18);
        if (1 == rand) {
            p.addCash(-200);
            std::cout << std::endl << "==> " << "You lost $200 savings at Needles Hall." << std::endl;
        } else if (2 <= rand && rand <= 3) {
            p.addCash(-100);
            std::cout << std::endl << "==> " << "You lost $100 savings at Neddles Hall." << std::endl;
        } else if (4 <= rand && rand <= 6) {
            p.addCash(-50);
            std::cout << std::endl << "==> " << "You lost $50 savings at Neddles Hall." << std::endl;
        } else if (7 <= rand && rand <= 12) {
            p.addCash(25);
            std::cout << std::endl << "==> " << "You gained $25 savings at Neddles Hall." << std::endl;
        } else if (13 <= rand && rand <= 15) {
            p.addCash(50);
            std::cout << std::endl << "==> " << "You gained $50 savings at Neddles Hall." << std::endl;
        } else if (16 <= rand && rand <= 17) {
            p.addCash(100);
            std::cout << std::endl << "==> " << "You gained $100 savings at Neddles Hall." << std::endl;
        } else {
            p.addCash(200);
            std::cout << std::endl << "==> " << "You gained $200 savings at Neddles Hall." << std::endl;
        }
        return cup;
    }
};

#endif

