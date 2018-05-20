//
// Created by darin on 18.03.18.
//

#include <iostream>
#include "../include/Game.h"
#include "../include/ArmyFactory.h"

void Game::start() {
    initGame();
}

void Game::initGame() {

    _user1 = std::make_shared<User>();
    _user2 = std::make_shared<User>();

    std::string name1, name2;
    std::cout << "Enter user1 name: ";
    std::cin >> name1;
    std::cout << "Enter user2 name: ";
    std::cin >> name2;

    _user1->setName(name1);
    _user2->setName(name2);

    std::cout << name1 << ", it's your turn now:" << std::endl;
    _requireSide();

    showWelcome();

    _createArmiesForUsers();

    run();
}

void Game::showWelcome() const {
    std::cout << "Welcome to the Game "
              << _user1->getName() << " and " << _user2->getName() << std::endl;
    std::cout << "RULES: Now you would be able to choose a side white or dark \n"
            "each one contains different armies that you would be able to choose during the game.\n"
            "Each army has its special power:\n"
            "war ones (orcs, goblins, worms or elfs, people, dwarfs, dead souls)\n"
            "have powers to fight,\n"
            "magic ones (krebains or eagles) have powers to make one army of an anemy harmless one time a game,\n"
            "nazguls - they are able to check one white army one time a game if it has a RING\n"
            "(and dark side wins if nazguls find one).\n"
            "Good luck!";
}

int Game::run() {
    long long RING = time(nullptr) % 5 +1;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Game starts!" << std::endl;
    std::size_t roundNo = 0;
    int ds = 0;
    int index = 0;
    int hl = 0;
    int lh = 0;
    int rn = 0;
    int white = 0;
    int dark = 0;
    int darkTeam = 0;
    int whiteTeam = 0;
    string type = "";
    while (!_finished) {
        std::cout << "Round number " << roundNo << std::endl;
        std::cout << "Choose an army for the fight" << std::endl;
        while(true) {
            if (_user1->getSide() == Side::eDark) {
                std::string army;
                std::cout << _user1->getName()
                          << " choose from: Orcs army(type 'orc'), Krebains spy from Dunland(type 'krebain'), Goblins army(type 'goblin'), Nazguls(type'nazgul'), Giant worms(type 'worm')"
                          << std::endl;
                while (true) {
                    std::cin >> army;
                    if (army == "orc") {
                        dark = _user1->turnDark(ArmyType::eOrcArmy, roundNo, rn, type);
                    } else if (army == "krebain") {
                        if (hl == 1) {
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            std::cout
                                    << "choose which army of your enemy you want to make harmless (can do it only once) (white would not know) : (type 'human, 'elf', 'dwarf)"
                                    << std::endl;
                            std::string harmless;
                            while (true) {
                                hl = 1;
                                dark = 1;
                                std::cin >> harmless;
                                if (harmless == "dwarf") {
                                    rn = _user2->harmless(ArmyType::eDwarfArmy, roundNo).first;
                                    type = _user2->harmless(ArmyType::eDwarfArmy, roundNo).second;
                                } else if (harmless == "elf") {
                                    rn = _user2->harmless(ArmyType::eElfArmy, roundNo).first;
                                    type = _user2->harmless(ArmyType::eElfArmy, roundNo).second;
                                } else if (harmless == "human") {
                                    rn = _user2->harmless(ArmyType::eMankindArmy, roundNo).first;
                                    type = _user2->harmless(ArmyType::eMankindArmy, roundNo).second;
                                } else {
                                    std::cout << "Try again!" << std::endl;
                                    continue;
                                }
                                std::cout << "Done!" << std::endl;
                                break;
                            }
                        }
                    } else if (army == "goblin") {
                        dark = _user1->turnDark(ArmyType::eGoblinArmy, roundNo, rn, type);
                    } else if (army == "worm") {
                        dark = _user1->turnDark(ArmyType::eGiantWormArmy, roundNo, rn, type);
                    } else if (army == "nazgul") {
                        if (index == 1) {
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            string check;
                            std::cout
                                    << "choose which white army Nazguls should check in case of finding the RING (may be done once, after you should chose an army to fight) (type 'human, 'elf', 'dwarf, 'eagle', 'dead')"
                                    << std::endl;
                            while (true) {
                                index = 1;
                                dark = 1;
                                std::cin >> check;
                                if (check == "dead") {
                                    int ans = 1;
                                    if (_user2->check(ArmyType::eDeadSoulArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "dwarf") {
                                    int ans = 2;
                                    if (_user2->check(ArmyType::eDwarfArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "elf") {
                                    int ans = 3;
                                    if (_user2->check(ArmyType::eElfArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "eagle") {
                                    int ans = 4;
                                    if (_user2->check(ArmyType::eEagle, RING, ans) == 1)
                                        return 0;
                                } else if (check == "human") {
                                    int ans = 5;
                                    if (_user2->check(ArmyType::eMankindArmy, RING, ans) == 1)
                                        return 0;
                                } else {
                                    std::cout << "Try again!" << std::endl;
                                    continue;
                                }
                                break;
                            }
                        }
                    } else{
                        std::cout << "Try Again!" << std::endl;
                        continue;
                    }
                    break;
                }
                std::cout << _user2->getName()
                          << " choose from: Dead Soul Army(type 'dead'), Mankind Army(type 'human', Elvish army(type 'elf'), Dwarves army(type 'dwarf'), Eagle(type 'eagle'))"
                          << std::endl;
                while (true) {
                    std::cin >> army;
                    if (army == "dead") {
                        if (ds == 1){
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            ds = 1;
                            white = _user1->turnWhite(ArmyType::eDeadSoulArmy, roundNo, rn, type);
                        }
                    } else if (army == "dwarf") {
                        white = _user1->turnWhite(ArmyType::eDwarfArmy, roundNo, rn, type);
                    } else if (army == "elf") {
                        white = _user1->turnWhite(ArmyType::eElfArmy, roundNo, rn, type);
                    } else if (army == "eagle") {
                        if (lh == 1){
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            std::string move;
                            std::cout
                                    << "choose which army Eagles should make harmless (can use only once) (dark would not know) (type 'goblin', 'worm', 'orc')"
                                    << std::endl;
                            while (true) {
                                lh = 1;
                                white = 1;
                                std::cin >> move;

                                if (move == "goblin") {
                                    rn = _user1->eagleHelp(ArmyType::eGoblinArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eGoblinArmy, roundNo + 1).second;
                                } else if (move == "worm") {
                                    rn = _user1->eagleHelp(ArmyType::eGiantWormArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eGiantWormArmy, roundNo + 1).second;
                                } else if (move == "orc") {
                                    rn = _user1->eagleHelp(ArmyType::eOrcArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eOrcArmy, roundNo + 1).second;
                                } else {
                                    std::cout << "Try again" << std::endl;
                                    continue;
                                }
                                break;
                            }
                        }
                    } else if (army == "human") {
                        white = _user1->turnWhite(ArmyType::eMankindArmy, roundNo, rn, type);
                    } else {
                        std::cout << "Try again!" << std::endl;
                        continue;
                    }
                    break;
                }
//////////////////////////////////////////////////////////////////////////////////////////////
            } else if(_user1->getSide() == Side::eWhite) {
                std::string army;
                std::cout << _user1->getName()
                          << " choose from: Dead Soul Army(type 'dead'), "
                                  "Mankind Army(type 'human', Elvish army(type 'elf'), "
                                  "Dwarves army(type 'dwarf'), Eagle(type 'eagle'))"
                          << std::endl;
                std::cout << ">>>" << std::endl;
                while (true) {
                    std::cin >> army;
                    if (army == "dead") {
                        if (ds == 1){
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else{
                            ds = 1;
                            _user1->turnWhite(ArmyType::eDeadSoulArmy, roundNo, rn, type);
                        }
                    } else if (army == "dwarf") {
                        white = _user1->turnWhite(ArmyType::eDwarfArmy, roundNo, rn, type);
                    } else if (army == "human") {
                        white = _user1->turnWhite(ArmyType::eMankindArmy, roundNo, rn, type);
                    } else if (army == "elf") {
                        white = _user1->turnWhite(ArmyType::eElfArmy, roundNo, rn, type);
                    } else if (army == "eagle") {
                        if (lh == 1){
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            std::string move;
                            std::cout
                                    << "choose which army Eagles should make harmless "
                                            "(dark would not know) "
                                            "(type 'orc', 'goblin', 'worm')"
                                    << std::endl;
                            while (true) {
                                white = 1;
                                std::cin >> move;

                                if (move == "worm") {
                                    rn = _user1->eagleHelp(ArmyType::eGiantWormArmy, roundNo).first;
                                    type = _user1->eagleHelp(ArmyType::eGiantWormArmy, roundNo).second;
                                } else if (move == "orc") {
                                    rn = _user1->eagleHelp(ArmyType::eOrcArmy, roundNo).first;
                                    type = _user1->eagleHelp(ArmyType::eOrcArmy, roundNo).second;
                                } else if (move == "goblin") {
                                    rn = _user1->eagleHelp(ArmyType::eGoblinArmy, roundNo).first;
                                    type = _user1->eagleHelp(ArmyType::eGoblinArmy, roundNo).second;
                                } else {
                                    std::cout << "Try again!" << std::endl;
                                    continue;
                                }
                                break;
                            }
                        }
                    } else {
                        std::cout << "Try again!" << std::endl;
                        continue;
                    }
                    break;
                }
                std::cout << _user2->getName()
                          << " choose from: Orcs army(type 'orc'), "
                                  "Krebains spy from Dunland(type 'krebain'), "
                                  "Goblins army(type 'goblin'), "
                                  "Nazguls(type'nazgul'), "
                                  "Giant worms(type 'worm')"
                          << std::endl;
                while (true) {
                    std::cin >> army;
                    if (army == "orc") {
                        dark = _user2->turnDark(ArmyType::eOrcArmy, roundNo, rn, type);
                    } else if (army == "krebain") {
                        if (hl == 1) {
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            std::cout
                                    << "choose which army you want to make harmless (white would not know): (type 'human, 'elf', 'dwarf, 'dead')"
                                    << std::endl;
                            std::string harmless;
                            while (true) {
                                dark = 1;
                                std::cin >> harmless;
                                if (harmless == "dead") {
                                    rn = _user1->harmless(ArmyType::eDeadSoulArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eDeadSoulArmy, roundNo + 1).second;
                                } else if (harmless == "dwarf") {
                                    rn = _user1->harmless(ArmyType::eDwarfArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eDwarfArmy, roundNo + 1).second;
                                } else if (harmless == "elf") {
                                    rn = _user1->harmless(ArmyType::eElfArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eElfArmy, roundNo + 1).second;
                                } else if (harmless == "human") {
                                    rn = _user1->harmless(ArmyType::eMankindArmy, roundNo + 1).first;
                                    type = _user1->eagleHelp(ArmyType::eMankindArmy, roundNo + 1).second;
                                } else {
                                    std::cout << "Try again!" << std::endl;
                                    continue;
                                }
                                cout << "Done!";
                                break;
                            }
                        }
                    } else if (army == "goblin") {
                        dark = _user2->turnDark(ArmyType::eGoblinArmy, roundNo, rn, type);
                    } else if (army == "worm") {
                        dark = _user2->turnDark(ArmyType::eGiantWormArmy, roundNo, rn, type);
                    } else if (army == "nazgul") {
                        if (index == 1){
                            std::cout << "Try again! You have already used it!" << std::endl;
                            continue;
                        }
                        else {
                            string check;
                            std::cout
                                    << "choose which white army Nazguls should check in case of finding the RING (type 'human, 'elf', 'dwarf, 'eagle', 'dead')"
                                    << std::endl;
                            while (true) {
                                dark = 1;
                                std::cin >> check;
                                if (check == "dead") {
                                    int ans = 1;
                                    if (_user1->check(ArmyType::eDeadSoulArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "dwarf") {
                                    int ans = 2;
                                    if (_user1->check(ArmyType::eDwarfArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "elf") {
                                    int ans = 3;
                                    if (_user1->check(ArmyType::eElfArmy, RING, ans) == 1)
                                        return 0;
                                } else if (check == "eagle") {
                                    int ans = 4;
                                    if (_user1->check(ArmyType::eEagle, RING, ans) == 1)
                                        return 0;
                                } else if (check == "human") {
                                    int ans = 5;
                                    if (_user1->check(ArmyType::eMankindArmy, RING, ans) == 1)
                                        return 0;
                                } else {
                                    std::cout << "Try again!" << std::endl;
                                    continue;
                                }
                                break;
                            }
                        }
                    } else {
                        std::cout << "Try again!" << std::endl;
                        continue;
                    }
                    break;
                }
            }
            else{
                std::cout << "ERROR, start again!" << std::endl;
                continue;
            }
            break;
        }
        _turnResult(white, dark, whiteTeam, darkTeam);

        if (roundNo++ > 11) {
            if(whiteTeam > darkTeam){
                std::cout << "WHITE SIDE WON!!! DARK SIDE SHALL NOT PASS!!!" << std::endl;
            }
            else if (darkTeam > whiteTeam){
                std::cout << "DARK SIDE WON!!! LONG LIVE SAURON!!!" << std::endl;
            }
            else {
                std::cout << "NO SIDE IS A WINNER! BUT THE WAR WILL CONTINUE!!!" << std::endl;
            }
            break;
        }
    }
}

void Game::_requireSide() {
    std::cout << "Choose your side - white or dark (type 'w' or 'd')" << std::endl;
    std::cout << ">>> ";
    char choice;
    std::cin >> choice;

    while (true) {
        if (choice == 'w') {
            _user1->setSide(Side::eWhite);
            _user2->setSide(Side::eDark);
        } else if (choice == 'd') {
            _user1->setSide(Side::eDark);
            _user2->setSide(Side::eWhite);
        } else {
            std::cout << "Not correct choice, try again." << std::endl;
            continue;
        }

        break;
    }

}

void Game::_createArmiesForUsers() {
    UserPtr dark, white;
    dark = (_user1->getSide() == Side::eDark) ? _user1 : _user2;
    white = (_user1->getSide() == Side::eDark) ? _user2 : _user1;

    dark->addArmy(ArmyFactory::createOrcArmy());
    dark->addArmy(ArmyFactory::createGiantWorm());
    dark->addArmy(ArmyFactory::createGoblinArmy());
    dark->addArmy(ArmyFactory::createKrebain());
    dark->addArmy(ArmyFactory::createNazgul());

    white->addArmy(ArmyFactory::createMankindArmy());
    white->addArmy(ArmyFactory::createDwarfArmy());
    white->addArmy(ArmyFactory::createEagle());
    white->addArmy(ArmyFactory::createElfArmy());
    white->addArmy(ArmyFactory::createDeadSoul());

    // Show info:
    _showUserArmies(dark);
    _showUserArmies(white);

}

void Game::_turnResult(int wh, int dk, int& winc, int& dinc){
    if(wh > dk) {
        std::cout << "White Side won the round!" << std::endl;
        winc++; }
    else {
         std::cout << "Dark Side won the round!" << std::endl;
        dinc++; }
}

void Game::_showUserArmies(UserPtr usr) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << usr->getName() << " has: " << std::endl;
    for(const ArmyPtr army: usr->getArmies()) {
        std::cout << "ArmyInfo: " << std::endl << army->getInfo() << std::endl;
//        const ArmyUnitPtr unit;
        cout << army->getState();
//        for (const ArmyUnitPtr unit: army->getUnits()) {
//            cout << " ";
//            //todo разобраться с выводом подразделений
////            unit->info();
//            std::cout << army->getUnitAm();
//        }

    cout << std::endl;
//    const ArmyPtr army;
//    usr->getArmies();
//    std::cout << "Army Info: " << std::endl << army->getInfo() << std::endl;
//    const ArmyUnitPtr unit;
//    army->getUnits();
//    cout << " ";
//    unit->info();
//    cout << std::endl;
//            if (unit->getType() == UnitType::eArcher) {
//
//            };
    }
}
