//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMYFACTORY_H
#define INC_1_TASK_PATTERN_ARMYFACTORY_H


#include "Army.h"
#include "ArmyBuilder.h"

class ArmyFactory {
public:
    static ArmyPtr createOrcArmy();
    static ArmyPtr createMankindArmy();
    static ArmyPtr createGoblinArmy();
    static ArmyPtr createGiantWorm();
    static ArmyPtr createNazgul();
    static ArmyPtr createKrebain();
    static ArmyPtr createElfArmy();
    static ArmyPtr createDwarfArmy();
    static ArmyPtr createEagle();
    static ArmyPtr createDeadSoul();
};

#endif //INC_1_TASK_PATTERN_ARMYFACTORY_H
