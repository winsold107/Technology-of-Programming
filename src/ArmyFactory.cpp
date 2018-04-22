//
// Created by darin on 18.03.18.
//

#include "ArmyFactory.h"

ArmyPtr ArmyFactory::createOrcArmy() {
    ArmyBuilder builder(ArmyType::eOrcArmy);

    builder.buildInfantryCreature();
    builder.buildArcher();
    builder.buildWargRider();
    builder.buildCatapult();
    builder.buildUrugHai();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createMankindArmy() {
    ArmyBuilder builder(ArmyType::eMankindArmy);

    builder.buildInfantryCreature();
    builder.buildArcher();
    builder.buildMechanisme();
    builder.buildManKing();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createGoblinArmy() {
    ArmyBuilder builder(ArmyType::eGoblinArmy);

    builder.buildInfantryCreature();
    builder.buildArcher();
    builder.buildMechanisme();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createGiantWorm() {
    ArmyBuilder builder(ArmyType::eGiantWormArmy);

    builder.buildGiantWorm();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createNazgul() {
    ArmyBuilder builder(ArmyType::eNazgulArmy);

    builder.buildNazgul();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createKrebain() {
    ArmyBuilder builder(ArmyType::eKrebainArmy);

    builder.buildKrebain();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createElfArmy() {
    ArmyBuilder builder(ArmyType::eElfArmy);

    builder.buildInfantryCreature();
    builder.buildArcher();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createDwarfArmy() {
    ArmyBuilder builder(ArmyType::eDwarfArmy);

    builder.buildInfantryCreature();
    builder.buildArcher();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createEnth() {
    ArmyBuilder builder(ArmyType::eEnthArmy);

    builder.buildEnth();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createEagle() {
    ArmyBuilder builder(ArmyType::eEagle);

    builder.buildEagle();

    return builder.getArmy();
}

ArmyPtr ArmyFactory::createDeadSoul() {
    ArmyBuilder builder(ArmyType::eDeadSoulArmy);

    builder.buildDeadSoul();

    return builder.getArmy();
}