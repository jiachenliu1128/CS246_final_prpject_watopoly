#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "board.h"
#include "player.h"
#include "board.h"
#include "game.h"
#include "dice.h"
#include "dctimsline.h"
using namespace std;

int main(int argc,char* argv[]) {
    // initialize game
    Game g;

    // command line options
    bool testMode = false;
    bool loadFile = false;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-testing") {
            testMode = true;
        } else if (arg == "-load") {
            if (++i < argc) {
                ifstream f{argv[i]};
                g.load(f);
                cout << endl << "==========================" << endl;
                cout << endl << "==> Current Players: " << endl;
                g.printPlayers();
                cout << endl << "==========================" << endl;
                g.gameStart();
                g.printMap();
                loadFile = true;
            }
        }
    }





    // initialize players
    if (!loadFile){
        int num_of_players = 0;
        cout << endl << "==> " << "Welcome to Watopoly!" << endl;
        cout << endl <<  "==> " << "Number of players must be between 2 and 7." << endl;
        cout << endl <<  "==> " << "Please enter the number of players: " << endl;
        string tmp;
        getline(cin, tmp);
        if (cin.fail()) {
            cout << endl << "==> " << "Invalid Number, please restart the game. " << endl;
            return 0;
        }
        istringstream iss{tmp};
        iss >> num_of_players;
        if (num_of_players < 2 || num_of_players > 7) {
            cout << endl << "==> " << "Invalid Number, please restart the game. " << endl;
            return 0;
        }

        for (int i = 0; i < num_of_players; i++) {
            cout << endl << "==> " << "Enter the name and char in separate lines of Player " << i + 1 << ": " << endl;
            string naming1 = " ";
            string naming2 = " ";
            if (getline(cin, naming1)) {
                if (getline(cin, naming2)) {
                    istringstream iss{naming2};
                    char c;
                    iss >> c;
                    if (!g.initPlayer(naming1, c)) {
                        cout << endl << "==> " << "Invalid player name or player char, input a valid name and char: " << endl;
                        i--;
                    }
                }
            }
            // g.initPlayer need to check it's a valid name and char
        } 
        cout << endl << "==========================" << endl;
        cout << endl << "==> Current Players: " << endl;
        g.printPlayers();
        cout << endl << "==========================" << endl;
        g.gameStart();
        g.printMap();
    }




    // game start
    string cmd = " ";
    cout << endl << "==> " << "The game begins." << endl;
    while (true) { 

        if (g.getCurrentPlayer().getCashAmount() < 0) {
            // owe to bank;
            g.bankruptcy(g.getCurrentPlayer().getName(), "Bank", -g.getCurrentPlayer().getCashAmount());
        }

        if (g.endGame()) {
            cout << endl << "==> " << "Winner is :" << g.getWinner() << endl;
            break;
        }

        cout << endl << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
        cout <<         "| Commands: [roll], [next], [trade <name> <give> <receive>], [improve <property> buy/sell], [mortgage <property>] |" << endl; 
        cout <<         "|           [unmortgage <property>], [bankrupt], [assets], [all], [save <filename>], [print], [quit]              |" << endl;
        cout <<         "|-----------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl << "==> " << "Player this turn: " << g.getCurrentPlayer().getName() << endl;
        cout << endl << "==> " << "Your current cash: " << g.getCurrentPlayer().getCashAmount() << endl;
        cout << endl << "==> " << "Please Enter Command: " << endl;
        


        
        cin >> cmd;
        if (cin.eof()){
            return 0;
        } else if (cin.fail()) {
            cout << endl << "==> " << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }


        
        // In DC Tims Line
        if (cmd == "roll") {
            if (g.getcannotRoll()) {
                // can not roll
                cout << endl << "==> You cannot roll more." << endl;
                continue;
            }
            if (g.getCurrentPlayer().getsentToDCTL() == true) {
                // if last turn is also at DCTL
                //cout << endl << "You are in DC Tims Line." << endl;
                int n = g.getActiverRim();
                DCTimsLine tmp1{0, "dc times line"};
                Player& p = g.getCurrentPlayer();
                int m = tmp1.action(p, n);
                g.printMap();
                g.setActiverRim(m);
                int movenum = tmp1.getNextMove();
                if (movenum > 0) {
                    if (g.getCurrentPlayer().getCashAmount() < 0) {
                        // owe to bank;
                        string cur_p = g.getCurrentPlayer().getName();
                        g.bankruptcy(g.getCurrentPlayer().getName(), "Bank", -g.getCurrentPlayer().getCashAmount());
                        if (!g.isValidPlayer(cur_p)) {
                            // player changed
                            continue;
                        }
                    }
                    cout << endl << "==> " << "You cannot roll more after being moved out of DC Tims Line." << endl;
                    cout << endl << "==> " << "You can end your turn by 'next'." << endl;
                    g.move(movenum);
                    g.setcannotRoll (true);
                    g.setrolled (true);
                    continue;
                } else if (movenum == 0) {
                    cout << endl << "==> " << "You can roll to leave DC Tims Line." << endl;
                    cout << endl << "==> " << "You can end your turn by 'next'." << endl;
                    g.setcannotRoll (false);
                    g.setrolled (false);
                    continue;
                } else {
                    // rolled not double and stay
                    cout << endl << "==> " << "You cannot roll anymore." << endl;
                    cout << endl << "==> " << "You can end your turn by 'next'." << endl;
                    g.setcannotRoll (true);
                    g.setrolled (true);
                    continue;
                }
            }
            // roll dice and move
            // check if has passed over OSAP
            // if don't buy, auction.
            int num1 = 0;
            int num2 = 0;
            if (testMode) {
                cin >> num1 >> num2;
            } else {
                num1 = g.roll();
                num2 = g.roll();
            } 
            cout << endl << "==> " << "Roll result: " << num1 << " " << num2 << endl;
            if (g.getdoubleroll() >= 2 && num1 == num2) {
                // cout << "==> " << "You have been sent to DC Tims Line." << endl;
                //g.printMap();
                cout << endl << "==> It's your third time with double roll, you will be sent to DC Tims Line." << endl;
                g.getCurrentPlayer().setsentToDCTL(true);
                g.getCurrentPlayer().setDCTLtimes(0);
                g.getCurrentPlayer().setPosition(10); /////////////
                g.getCurrentPlayer().setOSAPcollect(false);
                g.move(10 - g.getCurrentPlayer().getPosition()); /////////
                cout << endl << "==> " << "You cannot roll more than three times." << endl;
                cout << endl << "==> " << "You can end your turn by 'next'." << endl;
                g.setcannotRoll(true);
                g.setrolled(true);
                g.setdoubleroll (g.getdoubleroll() + 1);
                continue;
            } //else {
                //g.move(num1 + num2);
            //}
            if (num1 == num2 && g.getCurrentPlayer().getsentToDCTL() != true) {
                cout << endl << "==> " << "You rolled double." << endl;
                cout << endl << "==> " << "You can roll again by 'roll'." << endl;
                g.move(num1 + num2);
                g.setdoubleroll (g.getdoubleroll() + 1);
                g.setrolled(true);
                g.setcannotRoll (false);
                continue;
            } else {
                cout << endl << "==> " << "You didn't roll double, you cannot roll more." << endl;
                cout << endl << "==> " << "You can end your turn by 'next'." << endl;
                g.move(num1 + num2);
                g.setcannotRoll (true);
                g.setrolled(true);
                continue;
            }
            
            

        } else if (cmd == "next") {
            // move to next 
            if (!g.getrolled()) {
                // not rolled yet
                cout << endl << "==> Cannot move to the next player. You must roll in your turn." << endl;
                continue;
            }
            g.nextPlayer();
            cout << endl << "==> " << "It's " << g.getCurrentPlayer().getName() << "'s turn." << endl;
            g.setdoubleroll (0);
            g.setrolled(false);
            g.setcannotRoll(false);
            


        } else if (cmd == "trade") {
            string name = " ";
            string give = " ";
            string receive = " ";
            cin >> name >> give >> receive;
            // check it's a valid player name
            if (!(g.isValidPlayer(name))) {
                cerr << endl << "==> Invalid Player." << endl;
                continue;
            }

            if ((give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade money to building
                // check receive is valid property name 
                if (!(g.isValidProperty(receive))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                istringstream iss{give};
                int money = 0;
                iss >> money;
                //Board& b = g.getBoard(receive);

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                // and player need to have enough money
                //string name = b.getName();
                if (!(g.trade(p, money, receive))) {
                    cout << endl << "==> " << "reject" << endl;
                }

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            (receive[0] >= '0' && receive[0] <= '9')) {
                // trade building to money
                // check give is valid property name
                if (!(g.isValidProperty(give))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                //Board& b = g.getBoard(give);
                istringstream iss{receive};
                int money = 0;
                iss >> money;

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                // and player need to have enough money
                //string name = b.getName();
                if (!(g.trade(p, give, money))) {
                    cout << endl << "==> " << "reject" << endl;
                }              

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade from building to building
                // check both are valid property name
                if (!(g.isValidProperty(give)) || !(g.isValidProperty(receive))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                //Board& b_give = g.getBoard(give);
                //Board& b_receive = g.getBoard(give);

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                //string name1 = b_give.getName();
                //string name2 = b_receive.getName();
                if (!(g.trade(p, give, receive))) {
                    cout << endl << "==> " << "reject" << endl;
                } 

            } else {
                // give money and receive money
                cout << endl << "==> You cannot trade money with money." << endl;
                cout << endl << "==> " << "reject" << endl;
            }

        } else if (cmd == "improve") {
            // cout << endl << "==> <Property> buy/sell" << endl;
            string property = " ";
            string behaviour = " ";
            cin >> property >> behaviour;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            if (behaviour == "buy") {
                // game function need to check property is a property
                // and player owns it
                // and it can buy improve
                // attempt to buy improvement
                if (!(g.improve(property, true))) {
                    cout << endl << "==> " << "Unable to buy improvements." << endl;
                }

            } else if (behaviour == "sell") {
                // game function need to check property is a property
                // and player owns it
                // and it can sell improve
                // attempt to sell improvement
                if (!(g.improve(property, false))) {
                    cout << endl << "==> " << "Unable to sell improvements." << endl;
                }

            } else {
                cerr << endl << "==> Invalid behaviour." << endl;
            } 
            g.printMap();

        } else if (cmd == "mortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to mortgage property
            // check property is owned by player, and can mortgage 
            // (not already mortgaged, has no improvements)
            if (!(g.mortgage(property))) {
                cout << endl << "==> " << "Unable to mortgage." << endl;
                //cout << endl << "==> " << "You can end your turn by 'next'." << endl;
            }

        } else if (cmd == "unmortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to unmortgage property
            // check property used to owned by player, and can unmortgage 
            // (not already unmortgaged)
            if (!(g.unmortgage(property))) {
                cout << endl << "==> " << "Unable to unmortgage." << endl;
            }

        } else if (cmd == "bankrupt") {
            if (g.getCurrentPlayer().getCashAmount()<0) {
            // owe to bank;
            g.bankruptcy(g.getCurrentPlayer().getName(), "Bank", g.getCurrentPlayer().getCashAmount());
            } else {
                cout << endl << "==> You still have sufficient muney. You cannot declare bankruptcy." << endl;
            }
            
        } else if (cmd == "assets") {
            // displays the assets of the current player. 
            // Does not work if the player is deciding how to pay Tuition
            // if (!(g.asset())) {
            //     cout << "==> " << "Cannot display your assets at this stage" << endl;
            // }
            g.asset();

        } else if (cmd == "all") {
            // displays the assets of every player. For verifying the 
            // correctness of your transactions. 
            // Does not work if a player is deciding how to pay Tuition. 
            // if (!(g.all())) {
            //     cout << "==> " << "Cannot display everyone's asset at this stage" << endl;
            // }
            g.all();

        } else if (cmd == "save") {
            string filename;
            cin >> filename;
            g.save(filename);

        } else if (cmd == "print") {
            g.printMap();
            
        } else if (cmd == "quit") {
            return 0;

        } else {
            cerr << endl << "==> Invalid Command." << endl;
        }
    }
}

