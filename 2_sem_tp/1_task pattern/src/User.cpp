//
// Created by darin on 18.03.18.
//

#include "../include/User.h"

const std::string &User::getName() const {
    return _userName;
}

User::User() { }

void User::setSide(Side side) {
    _side = side;
}

Side User::getSide() const {
    return _side;
}

void User::setName(const std::string &name) {
    _userName = name;
}

void User::addArmy(ArmyPtr armyPtr) {
    _armies.push_back(armyPtr);
}

const std::vector<ArmyPtr>& User::getArmies() const {
    return _armies;
}
