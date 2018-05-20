//
// Created by darin on 18.03.18.
//

#include "../include/ArmyUnit.h"

UnitTypeToStringMap UnitTypesStrings = {
        { UnitType::eGiantWorm, "Giant worm" },
        { UnitType::eNazgul, "Nazgul" },
        { UnitType::eKrebain, "Krebain" },
        { UnitType::eManKing, "ManKing" },
        { UnitType::eMechanisme, "Mechanisme" },
        { UnitType::eEagle, "Eagle" },
        { UnitType::eDeadSoul, "Deal soul" },
        { UnitType::eUrugHai, "Urug hai" },
        { UnitType::eInfantryCreature, "Infantry creature" },
        { UnitType::eArcher, "Archer" },
        { UnitType::eWargRider, "Warg rider" },
        { UnitType::eCatapult, "Catapult" },
        { UnitType::eLastArmyUnitType, "Undefined" }
};

ArmyUnit::ArmyUnit(UnitType type) : _type(type) {}

UnitType ArmyUnit::getType() {
    return _type;
}

std::string ArmyUnit::name() const {
    return UnitTypesStrings[_type];
}

void InfantryCreature::info() {
    cout << "Infantry creature" << endl;
}

void Archer::info() {
    cout << "Archer" << endl;
}

void WargRider::info() {
    cout << "WargRider" << endl;
}

void Catapult::info() {
    cout << "Catapult" << endl;
}

void UrugHai::info() {
    cout << "Urug-Hai" << endl;
}

void Mechanisme::info() {
    cout << "Mechanism" << endl;
}

void GiantWorm::info() {
    cout << "Giant worm" << endl;
}

void Nazgul::info() {
    cout << "Nazgul" << endl;
}

void Krebain::info() {
    cout << "Krebain" << endl;
}

void Eagle::info() {
    cout << "Eagle" << endl;
}

void DeadSoul::info() {
    cout << "Dead Souls" << endl;
}

void ManKing::info() {
    cout << "The King of People" << endl;
}

InfantryCreature::InfantryCreature() : ArmyUnit(UnitType::eInfantryCreature) {
    _health = INFANTRY_INITIAL_HEALTH;
    _strength = power;
}

Archer::Archer() : ArmyUnit(UnitType::eArcher) {
    _health = ARCHER_INITIAL_HEALTH;
    _strength = arrowNumber;
}

WargRider::WargRider() : ArmyUnit(UnitType::eWargRider) {
    _health = WARGRIDER_INITIAL_HEALTH;
    _strength = power;
}

Eagle::Eagle() : ArmyUnit(UnitType::eEagle) {
    _strength = harm;
}

DeadSoul::DeadSoul() : ArmyUnit(UnitType::eDeadSoul) {
    _health = DEAD_SOUL_INITIAL_HEALTH;
    _strength = power;
}

ManKing::ManKing() : ArmyUnit(UnitType::eManKing) {
    _health = MAN_KING_INITIAL_HEALTH;
    _strength = power;
}

Krebain::Krebain() : ArmyUnit(UnitType::eKrebain) {
    _strength = harm;
}

Nazgul::Nazgul() : ArmyUnit(UnitType::eNazgul) {
}

GiantWorm::GiantWorm() : ArmyUnit(UnitType::eGiantWorm) {
    _health = GIANT_WORM_INITIAL_HEALTH;
    _strength = power;
}

Catapult::Catapult() : ArmyUnit(UnitType::eCatapult) {
    _health = CATAPULT_INITIAL_HEALTH;
    _strength = shot;
}

Mechanisme::Mechanisme() : ArmyUnit(UnitType::eMechanisme) {
    _health = MECHANISME_INITIAL_HEALTH;
    _strength = power;
}

UrugHai::UrugHai() : ArmyUnit(UnitType::eUrugHai) {
    _health = URUGHAI_INITIAL_HEALTH;
    _strength = power;
}