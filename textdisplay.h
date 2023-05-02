#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include <memory>
#include "player.h"
#include <utility>

class Board;

class TextDisplay{
  std::vector<std::string> boardMap;
  std::vector<std::pair<int,int>> playerpos;
  std::vector<std::pair<int,int>> impropos;
  
public:
  TextDisplay();
  void addPlayer(int pos, char symbol);
  void deletePlayer(int pos, char symbol);
  void addImprovement(Board& a);
  void removeImprovement(Board& a);
  void drawBoard(std::ostream& out, std::vector<std::shared_ptr<Player>> player, std::vector<std::shared_ptr<Board>> board);
};

#endif


