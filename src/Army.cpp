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

Army::Army(ArmyType type) : _type(type) {
//    vector<ArmyUnitPtr> un = getUnits();
//    for (int i = 0; i < un.size(); i++){
//
//    }
}

ArmyType Army::getType() const {
    return _type;
}

ArmyType Army::getAmount() const{
    return _amount;
}

std::string Army::getInfo() const {
    return ArmiesInfo[getType()];
}
