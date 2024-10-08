#include "board.h"
using namespace std;

// details in board.h
Board::Board(int position, string name): position{position}, name{name} {
  vector<string> nonpro = {"COLLECT OSAP", "SLC", "TUITION", "NEEDLES HALL", "DC Tims Line", "GOOSE NESTING", "GO TO TIMS", "Coop Fee"};
  vector<string> academic = {"AL", "ML", "ECH", "PAS", "HH", "RCH", "DWE", "CPH", "LHI", "BMH", "OPT", "EV1", "EV2", "EV3", "PHYS", "B1", "B2", "EIT", "ESC", "C2", "MC", "DC"};
  vector<string> residence = {"MKV", "UWP", "V1", "REV"};
  vector<string> gyms = {"PAC", "CIF"};
  for (auto& i : nonpro) {
    if (name == i) this->type = "NonProperty";
  } for (auto& i : academic) {
    if (name == i) this->type = "AcademicBuilding";
  } for (auto& i : residence) {
    if (name == i) this->type = "Residence";
  } for (auto& i : gyms) {
    if (name == i) this->type = "Gym";
  }
  
}

// details in board.h
Board::~Board() {
}

// details in board.h
string Board::getName() {
  return name;
}

// details in board.h
int Board::getPosition() {
  return position;
}

// details in board.h
std::vector<std::shared_ptr<Player>> Board::getCurPlayer() {
  return curPlayer;
}

// details in board.h
int Board::getVisitorNum() {
  return curPlayer.size();
}

// details in board.h
string Board::getType(){
  return type;
}


