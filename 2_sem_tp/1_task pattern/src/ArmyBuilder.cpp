//
// Created by darin on 18.03.18.
//

#include "../include/ArmyBuilder.h"

ArmyBuilder::ArmyBuilder(ArmyType type) : p(new Army(type)) {}

void ArmyBuilder::buildInfantryCreature() {
    p->pushUnit(new InfantryCreature());
}

void ArmyBuilder::buildArcher() {
    p->pushUnit(new Archer());
}

void ArmyBuilder::buildWargRider() {
    p->pushUnit(new WargRider());
}

void ArmyBuilder::buildCatapult() {
    p->pushUnit(new Catapult());
}

void ArmyBuilder::buildUrugHai() {
    p->pushUnit(new UrugHai());
}

void ArmyBuilder::buildEnth() {
    p->pushUnit(new Enth());
}

void ArmyBuilder::buildEagle() {
    p->pushUnit(new Eagle());
}

void ArmyBuilder::buildGiantWorm() {
    p->pushUnit(new GiantWorm());
}

void ArmyBuilder::buildDeadSoul() {
    p->pushUnit(new DeadSoul());
}

void ArmyBuilder::buildNazgul() {
    p->pushUnit(new Nazgul());
}

void ArmyBuilder::buildKrebain() {
    p->pushUnit(new Krebain());
}

void ArmyBuilder::buildManKing() {
    p->pushUnit(new ManKing());
}

void ArmyBuilder::buildMechanisme() {
    p->pushUnit(new Mechanisme());
}
