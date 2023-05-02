
#include "game.h"
#include "board.h"
using namespace std;
class OSAP;
class CoopFee;
class DCTimsLine;
class GoToTims;
class NeedleHall;
class SLC;
class Tuition;
class GoToTims;
class AcademicBuilding;
class Gym;
class Residence;
class GooseNesting;

// ctor of Game
Game::Game(): activeRim{0} {
  vector<string> names = {"COLLECT OSAP", "AL", "SLC", "ML", "TUITION", "MKV", "ECH", "NEEDLES HALL", "PAS", "HH", "DC Tims Line", "RCH", "PAC", "DWE", "CPH", "UWP", "LHI", "SLC", "BMH", "OPT", "Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1", "PHYS", "B1", "CIF", "B2", "GO TO TIMS", "EIT", "ESC", "SLC", "C2", "REV", "NEEDLES HALL", "MC", "COOP FEE", "DC"};

  dice = make_unique<Dice>();
  currentPlayer = nullptr;
  // auto& osap = make_shared<OSAP>(0, "COLLECT OSAP");
  // board.emplace_back(osap);
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<OSAP>(0, "COLLECT OSAP"))); //unique or shared?
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(1, "AL", 40, 0, vector<unsigned int>{2, 10, 30, 90, 160, 250}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(2, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(3, "ML", 60, 0, vector<unsigned int>{4, 20, 60, 180, 320, 450}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Tuition>(4, "TUITION")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(5, "MKV", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(6, "ECH", 100, 0, vector<unsigned int>{6, 30, 90, 270, 400, 550}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(7, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(8, "PAS", 100, 0, vector<unsigned int>{6, 30, 90, 270, 400, 550}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(9, "HH", 120, 0, vector<unsigned int>{8, 40, 100, 300, 450, 600}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<DCTimsLine>(10, "DC Tims Line")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(11, "RCH", 140, 0, vector<unsigned int>{10, 50, 150, 450, 625, 750}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Gym>(12, "PAC", 150, 0)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(13, "DWE", 140, 0, vector<unsigned int>{10, 50, 150, 450, 625, 750}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(14, "CPH", 160, 0, vector<unsigned int>{12, 60, 180, 500, 700, 900}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(15, "UWP", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(16, "LHI", 180, 0, vector<unsigned int>{14, 70, 200, 550, 750, 950}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(17, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(18, "BMH", 180, 0, vector<unsigned int>{14, 70, 200, 550, 750, 950}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(19, "OPT", 200, 0, vector<unsigned int>{16, 80, 220, 600, 800, 1000}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<GooseNesting>(20, "GOOSE NESTING")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(21, "EV1", 220, 0, vector<unsigned int>{18, 90, 250, 700, 875, 1050}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(22, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(23, "EV2", 220, 0, vector<unsigned int>{18, 90, 250, 700, 875, 1050}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(24, "EV3", 240, 0, vector<unsigned int>{20, 100, 300, 750, 925, 1100}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(25, "V1", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(26, "PHYS", 260, 0, vector<unsigned int>{22, 110, 330, 800, 975, 1150}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(27, "B1", 260, 0, vector<unsigned int>{22, 110, 330, 800, 975, 1150}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Gym>(28, "CIF", 150, 0)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(29, "B2", 280, 0, vector<unsigned int>{24, 120, 360, 850, 1025, 1200}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<GoToTims>(30, "GO TO TIMS")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(31, "EIT", 300, 0, vector<unsigned int>{26, 130, 390, 900, 1100, 1275}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(32, "ESC", 300, 0, vector<unsigned int>{26, 130, 390, 900, 1100, 1275}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(33, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(34, "C2", 320, 0, vector<unsigned int>{28, 150, 450, 1000, 1200, 1400}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(35, "REV", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(36, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(37, "MC", 350, 0, vector<unsigned int>{35, 175, 500, 1100, 1300, 1500}, 200, "Math")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<CoopFee>(38, "Coop Fee")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(39, "DC", 400, 0, vector<unsigned int>{50, 200, 600, 1400, 1700, 2000}, 200, "Math")));
}

// dctor of Game
Game::~Game() {}

// roll dice in Game
int Game::roll() {
  return dice->rollDice();
}

// initialize currentPlayer
void Game::gameStart() {
  currentPlayer = player[0];
}

Player& Game::getCurrentPlayer() {
  return *currentPlayer;
}

// check if there is only one player left
bool Game::endGame() {
  return player.size() == 1;
}

// print all Players' name and char
void Game::printPlayers() {
  for (auto& p : player) {
    std::cout << std::endl << "==> Name: " << p->getName() << endl << "==> Char:" << p->getNameChar() << endl;
  }
}


// get the winner
string Game::getWinner() {
  return (player[0])->getName();
}







// move the player num steps and do corresponding actions
void Game::move(int num, shared_ptr<Player> p) {
  if (p == nullptr) p = currentPlayer;
  int curPos = p->getPosition();
  int newPos = curPos + num;
  // Check if get OSAP
  if (newPos >= 40) {
    p->addCash(200);
    std::cout << std::endl << "==> You passed OSAP and got $200" << endl;
    newPos -= 40;
  } else if (newPos < 0) {
    newPos += 40;
  }
  p->setPosition(newPos);

  bool buy = false;
  shared_ptr<Board> now = board[newPos];
  string nowType = now->getType();


  if (nowType == "AcademicBuilding" || nowType == "Gym" || nowType == "Residence") {
    std::cout << std::endl << "==> You have arrived at " << now->getName() << "." << endl;
    // is property
    if (board[newPos]->getOwner() == nullptr) { 
      // No owner Property
      printMap();
      std::cout << std::endl << "==> You can buy " << now->getName() << " for " << now->getPrice() << endl;
      std::cout << std::endl << "==> Choose: 'buy' or 'auction'" << endl;
      string choice;
      
      while (cin >> choice) {
        if (choice == "buy") {
          if (p->getCashAmount() >= now->getPrice()) {
            string name = now->getName();
            purchase(name, *p); 
            buy = true;
            // std::cout << "==> You bought " << name << endl;
          } else {
            std::cout << std::endl << "==> You don't have enough money, choose again." << endl;
            buy = false;
            continue;
          } break;
        } else if (choice == "auction" || buy == false) {
          string name = now->getName();
          auction(name);
          buy = true;
          break;
        } else {
          std::cout << std::endl << "==> Invalid input, choose again." << endl;
        }
      }

    } else { 
      // Has owner Property
      printMap();
      if (now->isMortgaged() && now->getOwner() != p) {
        std::cout << std::endl << "==> This property has been morgaged.";
        return;
      }
      if (now->getOwner() == p) {
        std::cout << std::endl << "==> It is your own Property" << endl;
        return;
      }
      int visitPrice = now->getVisitPrice(*p);
      if(p->getCashAmount() < visitPrice){
        // owe owner more than player have
        bankruptcy(p->getName(),now->getOwner()->getName(),visitPrice);
      }else{
        p->addCash(-visitPrice);
        now->getOwner()->addCash(visitPrice);
        std::cout << std::endl << "==> You paid $" << visitPrice << " to " << (now->getOwner())->getName() << endl;
      }
      // if (p->getCashAmount() >= 0) return;
      // else { // in debt
      //   // bankruptcy(p->getName(),now->getOwner()->getName(),visitPrice);
      //   // std::cout << "You are in debt" << endl;
      //   // std::cout << "Choose: 'mortgage' or 'trade' or 'degrade'" << endl;
      //   // string choice;
      //   // cin >> choice;
        ////////////////////////////////////////////////////////////////////////////
        // input property name and check
        // if (choice == "mortgage") {
        //   mortgage(now);
        // } else if (choice == "trade") {
        //   trade(now);
        // } else if (choice == "degrade") {
        //   degrade(now);
        // } else {
        //   std::cout << "Invalid input" << endl;
        // }
        ////////////////////////////////////////////////////////////////////////////////
      // } 
    }
  } else { // NonProperty 
    printMap();
    string nowName = now->getName();
    if (nowName == "SLC") {
      SLC tmp{0, "slc"};
      int n = getActiverRim();
      int m = tmp.action(*p, n);
      setActiverRim(m);
      move(tmp.getNextMove(), p);

    } else if (nowName == "TUITION") {
      Tuition tmp{0, "tuition"};
      int n = getActiverRim();
      tmp.action(*p,n);
      if(p->getCashAmount() < 0 ){
        std::cout << std::endl << "==> You've owed the bank $" << -p->getCashAmount() <<endl;
        string name = p->getName();
        bankruptcy(name, "bank", -p->getCashAmount());
      }

    } else if (nowName == "GO TO TIMS") {
      GoToTims tmp{0, "go to tims"};
      int n = getActiverRim();
      tmp.action(*p,n);
      DCTimsLine tmp1{0, "dc times line"};
      printMap();
      int m = tmp1.action(*p, n);
      printMap();
      setActiverRim(m);

    } else if (nowName == "Coop Fee") {
      CoopFee tmp{0, "coop fee"};
      int n = getActiverRim();
      tmp.action(*p, n);

    } else if (nowName == "DC Tims Line") {
      //std::cout << std::endl << "==> You have landed on DC Tims Line, nothing happens." << endl;
      int n = getActiverRim();
      DCTimsLine tmp1{0, "dc times line"};
      int m = tmp1.action(*p, n);
      setActiverRim(m);


    } else if (nowName == "NEEDLES HALL") {
      NeedleHall tmp{0, "needles hall"};
      int n = getActiverRim();
      int m = tmp.action(*p, n);
      setActiverRim(m);

    } else if (nowName == "GOOSE NESTING") {
      GooseNesting tmp{0, "goose nesting"};
      int n = getActiverRim();
      tmp.action(*p,n);
    } else {
      return;
    }
  }
  //////////////////////////////////////////////////////////////////////////
}


void Game::nextPlayer() {
  for (size_t i = 0; i < player.size(); ++i) {
    if (player[i] == currentPlayer) {
      if (i == player.size() - 1) currentPlayer = player[0];
      else currentPlayer = player[i + 1];
      break;
    }
  }
}





bool Game::initPlayer(string name, char c) {
  // bool flag = false;
  for (auto& p: player) {
    if (p->getName() == name) {
      return false;
    }
  }
  for (auto& p: player) {
    if (p->getNameChar() == c) {
      return false;
    }
  }
  // if (name == "Goose") flag = true;
  // if (name == "GRT Bus") flag = true;
  // if (name == "Tim Hortons Doughnut") flag = true;
  // if (name == "Professor") flag = true;
  // if (name == "Student") flag = true;
  // if (name == "Money") flag = true;
  // if (name == "Laptop") flag = true;
  // if (name == "Pink tie") flag = true;
  // if (!flag) {
  //   return false;
  // }
  shared_ptr<Player> p = make_shared<Player>(name, c);
  player.emplace_back(p);
  return true;
  //td->drawBoard(std::cout, player, board);
}





shared_ptr<Player> Game::getOwner(const Board& b) {
  return b.getOwner();
}





void Game::purchase(string b, Player& p) {
  shared_ptr<Board> tmp = nullptr;
  shared_ptr<Player> tmp1 = nullptr;
  for(auto& it:board){
      if(it->getName()==b){
    //    p.addProperties(it);
        //p.addCash(-it->getPrice());
        tmp = it;
        break;
      }
    }

  if (tmp->getOwner() == nullptr) {
    if (p.getCashAmount() >= tmp->getPrice()) {
      for (auto& it1:player) {
        if (it1->getName() == p.getName()) {
          tmp1 = it1;
          break;
        }
      }
      tmp->setOwner(tmp1);
      p.addProperties(tmp);
      p.addCash(-tmp->getPrice());
      std::cout << std::endl << "==> " << p.getName() << " purchased " << tmp->getName() << endl;
    } else {
      std::cout << std::endl << "==> You don't have enough money" << endl;
    }
    
    // shared_ptr<Board> sharedb = make_shared<Board>(b);
    // auto sharedb = std::dynamic_pointer_cast<Board>(b);
    // shared_ptr<Board> sharedb = b;
    
  } else std::cout << std::endl << "==> This property is already owned by " << (tmp->getOwner())->getName() << endl;
  std::cout << std::endl << "==> "<< tmp->getName() <<"'s new owner is " << (tmp->getOwner())->getName() << endl;
}




bool Game::isValidPlayer(string name) {
  for (auto& p : player) {
    if (p->getName() == name) return true;
  }
  return false;
}





bool Game::isValidProperty(string bName) {
  for (auto& b : board) {
    if (b->getName() == bName && b->getType() != "NonProperty") return true;
  }
  return false;
}





Player& Game::getPlayer(string name) {
  for (auto &p : player) {
    if (p->getName() == name) return *p;
  }
  cerr << endl << "==> Cannot find the Player" << endl;
  return *(player[0]);
}





bool Game::trade(Player& p, string b, unsigned int n) {
  shared_ptr<Board> sharedb = nullptr;
  for(auto& it : board){
    if(it->getName()==b){
      sharedb = it;
      break;
    }
  }

  // check if mortgage;
  if (sharedb->isMortgaged()) {
    std::cout << endl  << "==> " << sharedb->getName() << " is mortgaged, you cannot trade this property." << endl;
    return false;
  }

  // check owner
  if(sharedb->getOwner() == nullptr || sharedb->getOwner()->getName() != currentPlayer->getName()){
      std::cout << std::endl << "==> " << currentPlayer->getName() << " doesn't own " << sharedb->getName() << endl;
      return false;
  }

  //check if monopoly block has improved
  string blockName = sharedb->getBlock();
  if (currentPlayer->ifMonopoly(blockName)) {
    // if monopoly this block
    for (auto it: board) {
      if (it->getBlock() == blockName && it->getImproveLevel() > 0) {
        // in the block and improved
        std::cout << endl  << "==> " << it->getName() << " is in the monopoly block of " << b << "." << endl;
        std::cout << endl  << "==> However, " << sharedb->getName() << " is improved, you need to sell them before trade this property." << endl;
        return false;
    }
    }
  }

  int tmp = n;
  if (p.getCashAmount() < tmp) {
    std::cout << std::endl << "==> " << p.getName() << " doesn't have enough money" << endl;
    return false;
  }
  
  if (sharedb->getOwner() == currentPlayer) {
    std::cout << std::endl << "==> " << currentPlayer->getName() << " is trading " << sharedb->getName() << " with " << p.getName() <<  " for " << n << endl;
    std::cout << std::endl << "==> " << p.getName() << ", please make a decision." << endl;
    std::cout << std::endl << "==> Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      // shared_ptr<Player> sharedp = make_shared<Player>(p); 
      // sharedb->setOwner(sharedp);
      shared_ptr<Player> sharedp = nullptr; 
     for(auto& it3 : player){
        if(it3->getName()==p.getName()){
          sharedp = it3;
          break;
        }
      }
      sharedb->setOwner(sharedp);
      p.addProperties(sharedb);
      p.addCash(-n);
      currentPlayer->sellProperties(sharedb);
      currentPlayer->addCash(n);
      return true;
    } else if (choice == "reject") {
      std::cout << std::endl << "==> Trade rejected" << endl;
      return false;
    } else {
      std::cout << std::endl << "==> Invalid input" << endl;
      return false;
    }
  } else return false;
}







bool Game::trade(Player& p, string b_give, string b_receive) {
      shared_ptr<Board> sharedb = nullptr;
      for(auto& it : board){
        if(it->getName()==b_give){
          sharedb = it;
          break;
        }
      }
      shared_ptr<Board> sharedb2 = nullptr;
      for(auto& it2 : board){
        if(it2->getName()==b_receive){
          sharedb2 = it2;
          break;
        }
      }
     shared_ptr<Player> sharedp = nullptr; 
     for(auto& it3 : player){
        if(it3->getName()==p.getName()){
          sharedp = it3;
          break;
        }
      }

    // if mortgaged
    if (sharedb->isMortgaged()) {
      std::cout << endl  << "==> " << sharedb->getName() << " is mortgaged, you cannot trade this property" << endl;
      return false;
    } else if (sharedb2->isMortgaged()){
      std::cout << endl  << "==> " << sharedb2->getName() << " is mortgaged, you cannot trade this property" << endl;
      return false;
    }

    // check owner
    if(sharedb2->getOwner() == nullptr || sharedb2->getOwner()->getName() != p.getName()){
      std::cout << std::endl << "==> " << p.getName() << " doesn't own " << sharedb2->getName() << endl;
      return false;
    }
    if(sharedb->getOwner() == nullptr || sharedb->getOwner()->getName() != currentPlayer->getName()){
      std::cout << std::endl << "==> " << currentPlayer->getName() << " doesn't own " << sharedb->getName() << endl;
      return false;
    }

    //check if both monopoly block has improved
    string blockName = sharedb->getBlock();
    if (currentPlayer->ifMonopoly(blockName)) {
      // if monopoly this block
      for (auto it: board) {
        if (it->getBlock() == blockName && it->getImproveLevel() > 0) {
          // in the block and improved
          std::cout << endl  << "==> " << it->getName() << " is in the monopoly block of " << b_give << "." << endl;
          std::cout << endl  << "==> However, " << it->getName() << " is improved, you need to sell them before trade this property." << endl;
          return false;
        }
      }
    }
    string blockName2 = sharedb2->getBlock();
    if (p.ifMonopoly(blockName2)) {
      // if monopoly this block
      for (auto it: board) {
        if (it->getBlock() == blockName2 && it->getImproveLevel() > 0) {
          // in the block and improved
          std::cout << endl  << "==> " << it->getName() << " is in the monopoly block of " << b_receive << "." << endl;
          std::cout << endl  << "==> However, " << it->getName() << " is improved, you need to sell them before trade this property." << endl;
          return false;
        }
      }
    }
    

  if (sharedb->getOwner() == currentPlayer) {
    std::cout << std::endl << "==> " << currentPlayer->getName() << " is trading " << sharedb->getName() << " with " << p.getName() <<  " for " << sharedb2->getName() << endl;
    std::cout << std::endl << "==> " << p.getName() << ", please make a decision." << endl;
    std::cout << std::endl << "==> Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      // shared_ptr<Player> sharedp = make_shared<Player>(p);
      sharedb->setOwner(sharedp);
      p.addProperties(sharedb);
      p.sellProperties(sharedb2);
      sharedb2->setOwner(currentPlayer);
      currentPlayer->addProperties(sharedb2);
      currentPlayer->sellProperties(sharedb);
      return true;
    } else if (choice == "reject") {
      std::cout << std::endl << "==> Trade rejected" << endl;
      return false;
    } else {
      std::cout << std::endl << "==> Invalid input" << endl;
      return false;
    }
  } else {
    std::cout << std::endl << "==> You don't own " << sharedb->getName() << endl;
    return false;
  }
}






bool Game::trade(Player& p, unsigned int n, string b) {
  shared_ptr<Board> sharedb = nullptr;
  for(auto& it : board){
    if(it->getName()==b){
      sharedb = it;
      break;
    }
  }

  if (sharedb->isMortgaged()) {
    std::cout << endl  << "==> " << sharedb->getName() << " is mortgaged, you cannot trade this property" << endl;
    return false;
  }

  if(sharedb->getOwner() == nullptr || sharedb->getOwner()->getName() != p.getName()){
      std::cout << std::endl << "==> " << p.getName() << " doesn't own " << sharedb->getName() << endl;
      return false;
    }

  // check is monopoly
  string blockName = sharedb->getBlock();
    if (p.ifMonopoly(blockName)) {
      // if monopoly this block
      for (auto it: board) {
        if (it->getBlock() == blockName && it->getImproveLevel() > 0) {
          // in the block and improved
          std::cout << endl  << "==> " << it->getName() << " is in the monopoly block of " << b << "." << endl;
          std::cout << endl  << "==> However, " << sharedb->getName() << " is improved, you need to sell them before trade this property." << endl;
          return false;
        }
      }
    }


  int q = n;
  if (currentPlayer->getCashAmount() < q) {
    std::cout << std::endl << "==> " << currentPlayer->getName() << " doesn't have enough money" << endl;
    return false;
  }
  // shared_ptr<Player> sharedp = make_shared<Player>(p);
  if (sharedb->getOwner()->getName() == p.getName()) {
    std::cout << std::endl << "==> " << currentPlayer->getName() << " is trading " << n << " with " << p.getName() <<  " for " << sharedb->getName() << endl;
    std::cout << std::endl << "==> " << p.getName() << ", please make a decision." << endl;
    std::cout << std::endl << "==> Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      sharedb->setOwner(currentPlayer);
      currentPlayer->addProperties(sharedb);
      currentPlayer->addCash(-n);
      p.sellProperties(sharedb);
      p.addCash(n);
      std::cout << std::endl << "==> Trade accepted" << endl;
      return true;
    } else if (choice == "reject") {
      std::cout << std::endl << "==> Trade rejected" << endl;
      return false;
    } else {
      std::cout << std::endl << "==> Invalid input" << endl;
      return false;
    }
  } else {
    std::cout << std::endl << "==> " << p.getName() << " doesn't own " << sharedb->getName() << endl;
    return false;
  }
}





bool Game::improve(string b_name, bool improve) {
  shared_ptr<Board> b = nullptr;
  for(auto& it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }

  if (b->getType() != "AcademicBuilding") {
    std::cout << std::endl << "==> Not an Academic Building" << endl;
    return false;
  }

  if (b->getOwner() == currentPlayer) {
    if (improve) {
      // check if monopoly
      string blockName = b->getBlock();
      if (!(currentPlayer->ifMonopoly(blockName))) {
        std::cout << std::endl << "==> You haven't own all properties in a monopoly." << endl;
        return  false;

      } else if (b->getImproveLevel() < 5) {
        // not fully improved
        if (currentPlayer->getCashAmount() >= b->getImproveCost()) {
          int n = b->getImproveCost();
          currentPlayer->addCash(-b->getImproveCost());
          b->improve();
          std::cout << std::endl << "==> You have successfully improved " << b->getName() << " by paying $" << n << "." << endl;
          return true;
        } else {
          std::cout << std::endl << "==> You don't have enough money to improve this property." << endl;
          return false;
        }

      } else{
        std::cout << std::endl << "==> It is already full upgraded!" << endl;
        return false;
      }

    } else {
       // degrade
      if (b->getImproveLevel() > 0) {
        currentPlayer->addCash(b->getImproveCost() / 2);
        b->degrade();
        std::cout << std::endl << "==> You have successfully degraded " << b->getName() << " and gained $" << (b->getImproveCost() / 2) << "." << endl;
        return true;
        
      } else {
        std::cout << std::endl << "==> It can't be degraded anymore" << endl;
        return false;
      }
    }
  } else {
    std::cout << std::endl << "==> You don't own this property" << endl;
    return false;
  }
}







bool Game::mortgage(string b_name) {
  shared_ptr<Board> b = nullptr;
  for(auto& it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }

  if (b->getOwner() == currentPlayer) {
    if (b->getImproveLevel() == 0 && !b->isMortgaged()) {
      int m = b->getPrice() / 2;
      currentPlayer->addCash(m);
      b->changeMortgage();
      std::cout << std::endl << "==> You've mortgaged succesfully and received: $" << m <<endl;
      //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
      return true;
    } else {
      if (b->getImproveLevel() != 0) {
        std::cout << std::endl << "==> You can't mortgage this property because it has improvements" << endl;
        //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
      } else {
        std::cout << std::endl << "==> You can't mortgage this property because it is already mortgaged" << endl;
        // std::cout << "Enter a command or end your turn by 'next'." << endl;
      }
      return false;
    }
  } else {
    std::cout << std::endl << "==> You don't own this property." << endl;
    // std::cout << "==> Enter a command or end your turn by 'next'." << endl;
    return false;
  }
}





bool Game::unmortgage(string b_name) {
  shared_ptr<Board> b = nullptr;
  for(auto& it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }
  if (b->getOwner() == currentPlayer) {
    if (b->isMortgaged()) {
      if (currentPlayer->getCashAmount() >= b->getPrice() / 10 * 6) {
        int m = -b->getPrice() / 10 * 6;
        currentPlayer->addCash(m);
        b->changeMortgage();
        std::cout << std::endl << "==> You've unmortgaged by using $" << m << endl;
        //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
        return true;
      } else {
        std::cout << std::endl << "==> You don't have enough money to unmortgage" << endl;
        //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
        return false;
      }
    } else {
      std::cout << std::endl << "==> This property is not mortgaged" << endl;
      //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
      return false;
    }
  } else {
     std::cout << std::endl << "==> You are not the owner" << endl;
     //std::cout << std::endl << "==> Enter a command or end your turn by 'next'." << endl;
    return false;
  }
}





void Game::bankruptcy(string playerName, string owePlayer, int oweAmount){
  shared_ptr<Player> cur_p = nullptr;
  shared_ptr<Player> owe_p = nullptr;
  for(auto& a : player){
    if(a->getName() == playerName){
      cur_p = a;
    }
  }
  if (owePlayer != "Bank") {
    for(auto& a : player){
      if(a->getName() == owePlayer){
        owe_p = a;
      }
    }
  }

  if (owePlayer == "Bank") {
    // cash is negative when owe bank. make cash amount back to 0
    cur_p->addCash(oweAmount);
  }

  if(cur_p->getCashAmount() < oweAmount){
    int choice = -1;
    std::cout << std::endl << "==> Your cash is not enough, you need to sell improvements(input 0), or mortgage (input 1), or declare bankruptcy (input 2)" <<endl;
    std::cout << endl << "==> Input: "<< endl;

    while(true) {
      cin >> choice;
      if (cin.eof()) {
        return;
      } else if (cin.fail()){
        std::cout << endl << "==> Invalid Input"<< endl;
        std::cout << endl << "==> Input: "<< endl;
        cin.clear();
        cin.ignore();
        continue;
      }

      if(choice == 2){
        std::cout << std::endl << "==> You decided to declare bankruptcy. " << endl;

        if (player.size() == 2) {
          nextPlayer();
          removePlayer(playerName);
          return;
        }
        
        std::cout << std::endl << "==> Your properties will be liquidated and we will move to the next player. " << endl;

        // decide bankrupty
        if (owe_p != nullptr) {
          // owe to a player
          std::cout << std::endl << "==> All your asset will be moved to " << owePlayer << endl;
          // give cash
          owe_p->addCash(cur_p->getCashAmount());
          // give cup
          owe_p->setRURCup(owe_p->getRURCup() + cur_p->getRURCup());
          // give property
          // std::vector<std::shared_ptr<Board>> cur_p_property = cur_p->getProperty();
          // for every property
          for (auto& it: (cur_p->getProperty())) {
            // move to owe_p
            owe_p->addProperties(it);
            it->setOwner(owe_p);
            // cur_p->sellProperties(it);
            if (it->isMortgaged()) {
              // found a mortgaged property
              int movePrice_10pc = it->getPrice() / 10;
              int movePrice_50pc = it->getPrice() / 2;

              std::cout << endl << "==> Found a mortgaged property: " << it->getName() << endl;
              std::cout << endl << "==>" << owePlayer << " has been charged 10% of property price from the bank." << endl;
              owe_p->addCash(-movePrice_10pc);
              std::cout << endl << "==>" << owePlayer << " can choose to unmortgage now (input 0) with $" << movePrice_50pc <<  " or unmortgage later (input 1) with 10% extra charge." << endl;
              std::cout << endl << "==>" << owePlayer << ", please make a decision."<< endl;
              std::cout << endl << "==> Input: "<< endl;
              int opt = -1;

              while (true) {
                cin >> opt;
                if (cin.eof()) {
                  return;
                } else if (cin.fail()) {
                  std::cout << endl << "==> Invalid Input"<< endl;
                  std::cout << endl << "==> Input: "<< endl;
                  cin.clear();
                  cin.ignore();
                  continue;
                }

                if (opt == 0) {
                  if (cur_p->getCashAmount() < movePrice_50pc) {
                    // not enough money
                    std::cout << endl << "==> You don't have enough money to unmortgage the property now. Try other options." << endl;
                    std::cout << endl << "==> Input: "<< endl;
                    continue;
                  }
                  // unmortgage now
                  owe_p->addCash(-movePrice_50pc);
                  it->changeMortgage();
                  std::cout << endl << "==> You have unmortgaged " << it->getName() << "." << endl;
                  break;

                } else if (opt == 1) {
                  std::cout << endl << "==> " << it->getName() << " is still mortgaged." << endl;
                  break;

                } else {
                  std::cout << endl << "==> Invalid Input"<< endl;
                  std::cout << endl << "==> Input: "<< endl;
                  continue;
                }
              }
            }
          }
          // initialize to next turn;
          string removeName = playerName;
          nextPlayer();
          setdoubleroll(0);
          setrolled(false);
          setcannotRoll(false);
          removePlayer(playerName);
          return;

        } else {
          // owe to bank;
          std::cout << std::endl << "==> All your buildings are returned to the open market as unmortgaged properties." << endl;
          // cups are destroyed;
          setActiverRim(getActiverRim() - cur_p->getRURCup());
          // properties are actions;
          std::vector<std::shared_ptr<Board>> cur_p_property = cur_p->getProperty();
          nextPlayer();
          setdoubleroll(0);
          setrolled(false);
          setcannotRoll(false);
          removePlayer(playerName);
          for (auto it: cur_p_property) {
            if (it->isMortgaged()) {
              it->changeMortgage();
            }
            auction(it->getName());
          }
          return;
        }
        break;

      } else if (choice == 0 || choice == 1) {
        // sell or mortgage
        // has no property
        if(cur_p->getPropertySize()<=0){
            std::cout << std::endl << "==> You don't have any property." << endl;
            std::cout << endl << "==> Input: "<< endl;
            continue;
        } else {
          std::cout << std::endl << "==> Your current property: ";
          for (auto it: cur_p->getProperty()) {
            std::cout << it->getName() << " ";
          }
          std::cout << endl;
        }

        if(choice == 0){
            // choose to sell improvements
            std::cout << std::endl << "==> Input the name of the property you want to sell: " << endl;
            string pro;
            cin >> pro;
            if (isValidProperty(pro)) {
              improve(pro, false);
            } else {
              std::cout << std::endl << "==> Invalid Property" << endl;
            }

        } else if(choice == 1){
          // choose to mortgage
            std::cout << std::endl << "==> Input the name of the property you want to mortgage: " << endl;
            string pro;
            cin >> pro;
            if (isValidProperty(pro)) {
              mortgage(pro);
            } else {
              std::cout << std::endl << "==> Invalid Property" << endl;
            }
        }
      } else {
        std::cout << std::endl << "==> Invalid Input" << endl;
        std::cout << endl << "==> Input: "<< endl;
      }

      
      if(cur_p->getCashAmount() < oweAmount){
          std::cout << std::endl << "==> Your cash is still not enough, you need to sell improvements (input 0), or mortgage (input 1), or declare bankrupt (input 2)" <<endl;
          continue;
      } else {
        std::cout << std::endl << "==> You have raised enough money." <<endl;
        if (owe_p) {
          // owe player
          owe_p->addCash(oweAmount);
          cur_p->addCash(-oweAmount);
          std::cout << std::endl << "==> You've paid the money you owed to " << owe_p->getName() << " ($" << oweAmount << ")." <<endl;
        } else {
          // owe bank
          cur_p->addCash(-oweAmount);
          std::cout << std::endl << "==> You've paid the money you owed to Bank ($" << oweAmount << ")." <<endl;
        }
        break;
      }
    }
  }
}

     


void Game::removePlayer(string name) {
  for (size_t i = 0; i < player.size(); ++i) {
    if (player[i]->getName() == name) {
      player.erase(player.begin() + i);
      return;
    }
  }
}

void Game::asset() {
  std::cout << endl << "=============================================" << endl;
  std::cout << std::endl << "==> " << currentPlayer->getName()<<", your assets:" << endl;
  std::cout << std::endl << "==> " << "Cash: " << currentPlayer->getCashAmount() << endl;
  std::cout << std::endl << "==> " << "Properties: ";
  for (auto& it : currentPlayer->getProperty()) {
    std::cout << it->getName() << " ";
  }
  std::cout << endl;
  std::cout << std::endl << "==> " << "Roll up the Rim Cup: " << currentPlayer->getRURCup() << endl;
  std::cout << endl << "=============================================" << endl;
  std::cout << std::endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
}

void Game::all() {
  std::cout << endl << "=============================================" << endl;
  for (auto& it : player) {
    std::cout << std::endl << "==> " << it->getName()<<", your assets:" << endl;
    std::cout << std::endl << "==> " << "Cash: " << it->getCashAmount() << endl;
    std::cout << std::endl << "==> " << "Properties: " ;
    for (auto& it2 : it->getProperty()) {
      std::cout << it2->getName() << " ";
    }
    std::cout << endl;
    std::cout << std::endl << "==> " << "Roll up the Rim Cup: " << it->getRURCup() << endl;
    std::cout << endl << "=============================================" << endl;
  }
  std::cout << std::endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
}

ofstream Game::save(string filename) {
  ofstream file(filename);
  file << player.size() << endl;
  for (auto& it : player) {
    file << it->getName() << " " << it->getNameChar() << " " << it->getRURCup() << " " << it->getCashAmount()<< " " << it->getPosition();
    if(it->getPosition() == 10){
      if (it->getsentToDCTL()){
        file << " 1" << " " << it->getDCTLtimes();
      }else{
        file << " 0";
      }
    }
    file << endl;
  }
  for (auto& it2 : board) {
    if(it2->getType()!= "NonProperty"){
    file << it2->getName() << " " ;
    auto tmp = dynamic_pointer_cast<Property>(it2);
    if(tmp){
      if(tmp->getOwner() != nullptr){
        file << it2->getOwner()->getName() << " " ;
      }else{
        file << "BANK ";
      }
      if(tmp->isMortgaged()){
        file << "-1" << " "<< endl;
      }else{
        auto tmp2 = dynamic_pointer_cast<AcademicBuilding>(tmp);
        if(tmp2){
          file << tmp2->getImproveLevel() << endl;
        }else{
          file << "0" << endl;
        }
      }
    }else{
      file << "BANK 0" << endl;
    } 
  }
  }
  std::cout << std::endl << "==> "<<"Game saved!"<<endl;
  return file;
}

void Game::load(ifstream& f) {
  int num = 0;
  string name = " ";
  char namechar = ' ';
  int rurcup = 0;
  int cash = 0;
  int pos = 0;
  string tmp;
  getline(f, tmp);
  // std::cout <<"test1: "<< tmp;
  istringstream ss{tmp};
  ss >> num;
  for (int i = 0; i < num; i++) {
    getline(f, tmp);
    istringstream s1{tmp};
    string tie = " tie";
    string bus = " Bus";
    string Hortons = " Hortons Doughnut";
    s1 >> name;
    if(name == "Pink"){
      string tmp = " ";
      s1 >> tmp;
      name = name + tie;
    }else if(name == "GRT"){
      string tmp = " ";
      s1 >> tmp;
      name = name + bus;
    }else if(name == "Tim"){
      string tmp = " ";
      s1 >> tmp;
      s1 >> tmp;
      name = name + Hortons;
    }

    s1 >> namechar >> rurcup >> cash >> pos;
    if (pos == 10) {
      int sent;
      s1 >> sent;
      if (sent == 0) {
        shared_ptr<Player> p = make_shared<Player>(name, namechar, rurcup, cash, pos, false, 0);
        player.push_back(p);
      } else {
        int times;
        s1 >> times;
        shared_ptr<Player> p = make_shared<Player>(name, namechar, rurcup, cash, pos, true, times);
        player.push_back(p);
      }
    } else {
      shared_ptr<Player> p = make_shared<Player>(name, namechar, rurcup, cash, pos, false, 0);
       player.push_back(p);
    }
  }
    while(getline(f, tmp)){
      istringstream s2{tmp};
      string name;
      string owner;
      int level;
      s2 >> name >> owner;
      for(int j = 0; j<40; j++){
          if(board[j]->getName()==name){
            auto p = dynamic_pointer_cast<Property>(board[j]);
            if(owner != "BANK"){
              s2 >> level;
              if(level == -1){
                level = 0;
                if (p != nullptr) p->changeMortgage();
              }
              for(size_t i =0; i<player.size();i++){
                  if(player[i]->getName()==owner){
                    p->setOwner(player[i]);
                    player[i]->addProperties(p);
                  }
                }
              auto academic = dynamic_pointer_cast<AcademicBuilding>(p);
              if(academic){
                academic->setImproveLevel(level);
              }
            }
          }
      }
    }
  currentPlayer = player[0];
  std::cout << std::endl << "==> "<<"Game loaded!"<<endl;
}

int Game::getActiverRim() {
  return activeRim;
}

void Game::setActiverRim(int n) {
  activeRim = n;
}

void Game::auction(string pro) {
  shared_ptr<Board> sharedb= nullptr;
  for(auto& it : board){
    if(it->getName() == pro){
      sharedb=it;
      break;
    }
  }
  std::cout << std::endl << "==> " << "Auction for " << sharedb->getName() << " starts!" << endl;
  int max = 0;
  string bider = " ";
  vector<shared_ptr<Player>> participants = player;
  int n = participants.size();
  while (1) {
    if (n == 0) {
      std::cout << std::endl << "==> " << "No one wants to buy this property" << endl;
      return;
    } if (n == 1 && max != 0) {
      std::cout << std::endl << "==> " << "The final bid is " << max << " from " << bider << endl;
      for (auto& p : player) {
        if (p->getName() == bider) {
          p->addCash(-max);
          p->addProperties(sharedb);
          sharedb->setOwner(p);
          std::cout << std::endl << "==> " << p->getName() << " has bought " << sharedb->getName() << " for " << max << endl;
          return;
        }
      }
    } 
    std::cout << std::endl << "==> " << "There are " << n << " players in the auction." << endl;
    for (int i = 0; i < n; ++i) {
      if( n == 1 && i > 0){
        break;
      }
      std::cout << std::endl << "==> " << participants[i]->getName() << ", it is your turn" << endl;
      std::cout << std::endl << "==> " << "Choose between: bid or quit" << endl;
      string choice;
      while (cin >> choice) {
        if (choice == "quit") {
          std::cout << std::endl << "==> " << "You quit the auction." << endl;
          participants.erase(participants.begin() + i);
          n--;
          i--;
          std::cout << std::endl << "==> " << "There are " << n << " players in the auction." << endl;
          if (n == 1 && max != 0) {
            std::cout << std::endl << "==> " << "The final bid is " << max << " from " << bider << endl;
            for (auto& p : player) {
              if (p->getName() == bider) {
                p->addCash(-max);
                p->addProperties(sharedb);
                sharedb->setOwner(p);
                // check Brankruptcy
                return;
              }
            }
          }
          break;
        } else if (choice == "bid") {
          std::cout << std::endl << "==> " << "Input your bid. Your bid must be higher than " << max << endl;
          int bid;
          cin >> bid;
          if (bid > max && participants[i]->getCashAmount() >= bid) {
            max = bid;
            bider = participants[i]->getName();
            std::cout << std::endl << "==> " << "Your bid is accepted" << endl;
            break;
          } else {
            if(participants[i]->getCashAmount() < bid){
              std::cout << std::endl << "==> " << "You don't have enough money to pay: $" << bid << endl;
              std::cout << std::endl << "==> " << "You currently have $" << participants[i]->getCashAmount() << endl;
            }else if(participants[i]->getCashAmount() < max){
              std::cout << std::endl << "==> " << "You don't have enough money, please choose quit. " << endl;
            }
            std::cout << std::endl << "==> " << "Your bid is not accepted" << endl;
            break;
          }
        } else {
          std::cout<< std::endl << "==> " << "Invalid input, input again." << endl;
        }
      }
    }
  }
  std::cout << std::endl << "==> " << "The final bid is " << max << " from " << bider << endl;
  for (auto& p : player) {
    if (p->getName() == bider) {
      p->addCash(-max);
      p->addProperties(sharedb);
      sharedb->setOwner(p);
      // check Brankruptcy
      return;
    }
  }
}

void Game::printMap(){
  TextDisplay td;
  td.drawBoard(std::cout, player, board);
}


