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
}

void Game::run() {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Game starts!" << std::endl;
    std::size_t roundNo = 0;
    while (!_finished) {
        std::cout << "Round number " << roundNo << std::endl;
//        _user1->turn();
//        _user2->turn();

        if (roundNo++ > 10) {
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
    white->addArmy(ArmyFactory::createEnth());

    // Show info:
    _showUserArmies(dark);
    _showUserArmies(white);

}

void Game::_showUserArmies(UserPtr usr) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << usr->getName() << " has: " << std::endl;
    for(const ArmyPtr army: usr->getArmies()) {
        std::cout << "ArmyInfo: " << std::endl << army->getInfo() << std::endl;
        for (const ArmyUnitPtr unit: army->getUnits()) {
            cout << " ";
            unit->info();
        }
    cout << std::endl;
//            if (unit->getType() == UnitType::eArcher) {
//
//            };
    }
}
