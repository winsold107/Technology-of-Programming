//
// Created by darin on 18.03.18.
//

#include "../include/Army.h"


void Army::pushUnit(ArmyUnit* unit) {
    _units.push_back(ArmyUnitPtr(unit));
}

const std::vector<ArmyUnitPtr>& Army::getUnits() const {
    return _units;
}

std::string Army::getInfo() const {
    return ArmiesInfo[_type];
}

Army::Army(ArmyType type) : _type(type) {}

ArmyType Army::getType() const {
    return _type;
}
