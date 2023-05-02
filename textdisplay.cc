#include "textdisplay.h"
#include <utility>
#include "board.h"
#include "player.h"
using namespace std;

TextDisplay::TextDisplay(){
     boardMap={
        "_________________________________________________________________________________________\n",
        "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |\n",
        "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |\n",
        "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |\n",
        "|       |       |       |       |       |       |       |       |       |       |       |\n",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|OPT    |                                                                       |EIT    |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|BMH    |                                                                       |ESC    |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|SLC    |                                                                       |SLC    |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|LHI    |                                                                       |C2     |\n",
        "|       |         ______________________________________________________        |       |\n",
        "|_______|        |                                                      |       |_______|\n",
        "|UWP    |        | #   #   ##  #####   ###   ###     ###   #     #    # |       |REV    |\n",
        "|       |        | #   #  #  #   #    #   #  #  #  #    #  #     #    # |       |       |\n",
        "|       |        | # # #  ####   #    #   #  ###   #    #  #      #  #  |       |       |\n",
        "|       |        | # # #  #  #   #    #   #  #     #    #  #       #    |       |       |\n",
        "|_______|        | #####  #  #   #     ###   #      ###    ####    #    |       |_______|\n",
        "|       |        |______________________________________________________|       |NEDDLES|\n",
        "|-------|                                                                       |HALL   |\n",
        "|CPH    |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|DWE    |                                                                       |MC     |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|PAC    |                                                                       |COOP   |\n",
        "|       |                                                                       |FEE    |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|RCH    |                                                                       |DC     |\n",
        "|       |                                                                       |       |\n",
        "|_______|_______________________________________________________________________|_______|\n",
        "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|\n",
        "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n",
        "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n",
        "|       |       |       |       |       |       |       |       |       |       |       |\n",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n"
    };
    playerpos = {{54,81},{54,73},{54,65},{54,57},{54,49},{54,41},{54,33},{54,25},{54,17},{54,9},{54,1},
                 {49,1}, {44,1},{39,1},{34,1},{29,1},{24,1},{19,1},{14,1},{9,1},{4,1},{4,9},{4,17},{4,25},
                 {4,33},{4,41},{4,49},{4,57},{4,65},{4,73},{4,81},
                 {9,81},{14,81},{19,81},{24,81},{29,81},
                 {34,81},{39,81},{44,81},{49,81}};
    impropos = {{51,81},{51,73},{51,65},{51,57},{51,49},{51,41},{51,33},{51,25},{51,17},{51,9},{51,1},
                {46,1}, {41,1},{36,1},{31,1},{26,1},{21,1},{16,1},{11,1},{6,1},{1,1},{1,9},{1,17},{1,25},
                {1,33},{1,41},{1,49},{1,57},{1,65},{1,73},{1,81},
                {6,81},{11,81},{16,81},{21,81},{26,81},
                {31,81},{36,81},{41,81},{46,81}};
}

void TextDisplay::addPlayer(int pos, char symbol){
    //h,w
        auto it = playerpos[pos];
        int h = it.first;
        int w = it.second;
        while(boardMap[h][w]!=' '){
            w++;
        }
        boardMap[h][w] = symbol;
    
}
void TextDisplay::deletePlayer(int pos, char symbol){
        auto it = playerpos[pos];
        int h = it.first;
        int w = it.second;
        while(boardMap[h][w]!=symbol){
            w++;
        }
        boardMap[h][w] = ' ';
}

void TextDisplay::addImprovement(Board& a){
    int improvementL=a.getImproveLevel();
    int pos = a.getPosition();
        auto it = impropos[pos];
        int h = it.first;
        int w = it.second;
        for(int i = 0; i<improvementL; i++){
            if(boardMap[h][w+i]==' '){
                boardMap[h][w+i]='I';
            }
        }
}
void TextDisplay::removeImprovement(Board& a){
    int improvementL=a.getImproveLevel();
    int pos = a.getPosition();
        auto it = impropos[pos];
        int h = it.first;
        int w = it.second+4;
        for(int i = w; i >= improvementL+it.second; i++){
            if(boardMap[h][i]=='I'){
                boardMap[h][i]=' ';
            }
        }
}


void TextDisplay::drawBoard(std::ostream& out, vector<shared_ptr<Player>> player, vector<shared_ptr<Board>> board){
    for (auto& it : player) {
        int pos = it->getPosition();
        char symbol = it->getNameChar();
        addPlayer(pos, symbol);
    }
    for  (auto& it1 : board) {
        addImprovement(*it1);
    }
    out << endl;
    for(size_t i = 0; i<boardMap.size(); i++){
        out<<boardMap[i];
    }
    out<<endl;
}

