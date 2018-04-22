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
    virtual void buildInfantryCreature();

    virtual void buildArcher();
    virtual void buildWargRider();
    virtual void buildCatapult();
    virtual void buildUrugHai();
    virtual void buildEnth();
    virtual void buildEagle();
    virtual void buildGiantWorm();
    virtual void buildKrebain();
    virtual void buildDeadSoul();
    virtual void buildNazgul();
    virtual void buildMechanisme();
    virtual void buildManKing();

    virtual ArmyPtr getArmy() { return p; }

    virtual ~ArmyBuilder() = default;
};


#endif //INC_1_TASK_PATTERN_ARMYBUILDER_H
