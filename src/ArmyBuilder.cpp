//
// Created by darin on 18.03.18.
//

#include "../include/ArmyBuilder.h"

ArmyBuilder::ArmyBuilder(ArmyType type) : p(new Army(type)) {}

void ArmyBuilder::buildInfantryCreature(int count) {
    for (int c = 0; c < count; ++c) {
        p->pushUnit(new InfantryCreature());
    }
}

void ArmyBuilder::buildArcher(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Archer());
}

void ArmyBuilder::buildWargRider(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new WargRider());
}

void ArmyBuilder::buildCatapult(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Catapult());
}

void ArmyBuilder::buildUrugHai(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new UrugHai());
}

void ArmyBuilder::buildEagle(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Eagle());
}

void ArmyBuilder::buildGiantWorm(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new GiantWorm());
}

void ArmyBuilder::buildDeadSoul(int count) {
    for (int i = 0; i < count; i++)
            p->pushUnit(new DeadSoul());
}

void ArmyBuilder::buildNazgul(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Nazgul());
}

void ArmyBuilder::buildKrebain(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Krebain());
}

void ArmyBuilder::buildManKing(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new ManKing());
}

void ArmyBuilder::buildMechanisme(int count) {
    for (int i = 0; i < count; i++)
        p->pushUnit(new Mechanisme());
}
