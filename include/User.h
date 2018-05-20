//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_USER_H
#define INC_1_TASK_PATTERN_USER_H

#include <memory>
#include <utility>
#include "Side.h"
#include "Army.h"

class User;
typedef std::shared_ptr<User> UserPtr;

class User {
public:
//    struct TurnProcess{
//
//    }

    explicit User();

    void setName(const std::string& name);
    const std::string& getName() const;

    void setSide(Side side);
    Side getSide() const;

    int turnWhite(ArmyType ty, int round, int rn, string type);
    int turnDark(ArmyType ty, int round, int rn, string type);
    int check(ArmyType, int RING, int ans);
    pair<int, string> eagleHelp(ArmyType ty, int round);
    pair<int, string> harmless(ArmyType ty, int round);

    void addArmy(ArmyPtr armyPtr);
    const std::vector<ArmyPtr>& getArmies() const;

//    FightResult fightAll(UserPtr otherUser) {
//        for (auto army: _armies) {
//            for (auto other_army: otherUser->getArmies()) {
//                army->fight(other_army);
//            }
//        }
//        return FightResult();
//    }

private:
    std::vector<ArmyPtr> _armies;

    std::string _userName;
    Side _side;
};



#endif //INC_1_TASK_PATTERN_USER_H
