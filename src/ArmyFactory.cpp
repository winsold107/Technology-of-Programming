//
// Created by darin on 18.03.18.
//

#include "ArmyFactory.h"

ArmyPtr ArmyFactory::createOrcArmy() {
    ArmyBuilder builder(ArmyType::eOrcArmy);

    builder.buildInfantryCreature(100);
    builder.buildArcher(50);
    builder.buildWargRider(30);
    builder.buildCatapult(20);
    builder.buildUrugHai(1);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createMankindArmy() {
    ArmyBuilder builder(ArmyType::eMankindArmy);

    builder.buildInfantryCreature(100);
    builder.buildArcher(50);
    builder.buildMechanisme(50);
    builder.buildManKing(1);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createGoblinArmy() {
    ArmyBuilder builder(ArmyType::eGoblinArmy);

    builder.buildInfantryCreature(100);
    builder.buildArcher(50);
    builder.buildMechanisme(50);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createGiantWorm() {
    ArmyBuilder builder(ArmyType::eGiantWormArmy);

    builder.buildGiantWorm(20);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createNazgul() {
    ArmyBuilder builder(ArmyType::eNazgulArmy);

    builder.buildNazgul(9);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createKrebain() {
    ArmyBuilder builder(ArmyType::eKrebainArmy);

    builder.buildKrebain(100);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createElfArmy() {
    ArmyBuilder builder(ArmyType::eElfArmy);

    builder.buildInfantryCreature(100);
    builder.buildArcher(100);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createDwarfArmy() {
    ArmyBuilder builder(ArmyType::eDwarfArmy);

    builder.buildInfantryCreature(100);
    builder.buildArcher(50);

    return builder.getArmy();
}


ArmyPtr ArmyFactory::createEagle() {
    ArmyBuilder builder(ArmyType::eEagle);

    builder.buildEagle(100);

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createDeadSoul() {
    ArmyBuilder builder(ArmyType::eDeadSoulArmy);

    builder.buildDeadSoul();

    return builder.getArmy();
}