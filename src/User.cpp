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

int User::turnWhite(ArmyType ty, int round, int rn, string type){
    string str = ArmiesInfo[ty];
    if (rn == round && type == str){
        return 0;
    }
    else{
        if (str == "Mankind army"){
            return 11580;
        }

        if (str == "Elves Army"){
            return 12000;
        }

        if (str == "Dwarfs Army"){
            return 8500;
        }

        if (str == "Dead Soul Pirates Army"){
            return numeric_limits<int>::max();
        }
    }

}

int User::turnDark(ArmyType ty, int round, int rn, string type){
    string str = ArmiesInfo[ty];
    if (rn == round && type == str){
        return 0;
    }
    else{
        if (str == "Orcs army"){
            return 12400;
        }

        if (str == "Goblins Army"){
            return 11500;
        }

        if (str == "Giant worm Army"){
            return 10000;
        }
    }

}

int User::check(ArmyType, int RING, int ans){
    if (ans == RING)
        {std::cout << "DARK SIDE WON!!! LONG LIVE SAURON!!!";
        return 1;}
    else
        {std::cout << "nothing was found!" << std::endl;
        return 0;}

}

pair<int, string> User::harmless(ArmyType ty, int round){
    string str = ArmiesInfo[ty];
    return make_pair(round, str);
}

pair<int, string> User::eagleHelp(ArmyType ty, int round){
    string str = ArmiesInfo[ty];
    return make_pair(round, str);
}