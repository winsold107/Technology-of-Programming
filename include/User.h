//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_USER_H
#define INC_1_TASK_PATTERN_USER_H

#include <memory>
#include <utility>
#include "Side.h"
#include "Army.h"


class User {
public:
    explicit User();

    void setName(const std::string& name);
    const std::string& getName() const;

    void setSide(Side side);
    Side getSide() const;


    void addArmy(ArmyPtr armyPtr);
    const std::vector<ArmyPtr>& getArmies() const;

private:
    std::vector<ArmyPtr> _armies;

    std::string _userName;
    Side _side;
};

typedef std::shared_ptr<User> UserPtr;


#endif //INC_1_TASK_PATTERN_USER_H
