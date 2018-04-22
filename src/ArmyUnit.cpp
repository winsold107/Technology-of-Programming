//
// Created by darin on 18.03.18.
//

#include "../include/ArmyUnit.h"

ArmyUnit::ArmyUnit(UnitType type) : _type(type) {}

UnitType ArmyUnit::getType() {
    return _type;
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

void Enth::info() {
    cout << "Enth" << endl;
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

InfantryCreature::InfantryCreature() : ArmyUnit(UnitType::eInfantryCreature) {}

Archer::Archer() : ArmyUnit(UnitType::eArcher) {}

WargRider::WargRider() : ArmyUnit(UnitType::eWargRider) {}

Enth::Enth() : ArmyUnit(UnitType::eEnth) {}

Eagle::Eagle() : ArmyUnit(UnitType::eEagle) {}

DeadSoul::DeadSoul() : ArmyUnit(UnitType::eDeadSoul) {}

ManKing::ManKing() : ArmyUnit(UnitType::eManKing) {}

Krebain::Krebain() : ArmyUnit(UnitType::eKrebain) {}

Nazgul::Nazgul() : ArmyUnit(UnitType::eNazgul) {}

GiantWorm::GiantWorm() : ArmyUnit(UnitType::eGiantWorm) {}

Catapult::Catapult() : ArmyUnit(UnitType::eCatapult) {}

Mechanisme::Mechanisme() : ArmyUnit(UnitType::eMechanisme) {}

UrugHai::UrugHai() : ArmyUnit(UnitType::eUrugHai) {}