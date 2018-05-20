//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMYBUILDER_H
#define INC_1_TASK_PATTERN_ARMYBUILDER_H


#include "Army.h"

class ArmyBuilder
{
protected:
    ArmyPtr p;
public:
    explicit ArmyBuilder(ArmyType type);
    virtual void buildInfantryCreature(int count = 100);

    virtual void buildArcher(int count = 50);
    virtual void buildWargRider(int count = 30);
    virtual void buildCatapult(int count = 20);
    virtual void buildUrugHai(int count = 10);
    virtual void buildEagle(int count = 200);
    virtual void buildGiantWorm(int count = 10);
    virtual void buildKrebain(int count = 1);
    virtual void buildDeadSoul(int count = 100);
    virtual void buildNazgul(int count = 9);
    virtual void buildMechanisme(int count = 20);
    virtual void buildManKing(int count = 1);

    virtual ArmyPtr getArmy() { return p; }

    virtual ~ArmyBuilder() = default;
};


#endif //INC_1_TASK_PATTERN_ARMYBUILDER_H
