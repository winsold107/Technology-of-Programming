//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMY_H
#define INC_1_TASK_PATTERN_ARMY_H


#include <vector>
#include "ArmyUnit.h"
#include <unordered_map>
#include <map>

enum class ArmyType {
    eOrcArmy,
    eMankindArmy,
    eEnthArmy,
    eGoblinArmy,
    eKrebainArmy,
    eGiantWormArmy,
    eNazgulArmy,
    eElfArmy,
    eDwarfArmy,
    eDeadSoulArmy,
    eEagle
};

static std::map<ArmyType, std::string> ArmiesInfo {
        { ArmyType::eOrcArmy, "Orcs army!" },
        { ArmyType::eMankindArmy, "Mankind army!" },
        { ArmyType::eEnthArmy, "Enths Army!"},
        { ArmyType::eGoblinArmy, "Goblins Army!"},
        { ArmyType::eKrebainArmy, "The Army of Krebains from Dunland!"},
        { ArmyType::eGiantWormArmy, "Giant worm Army!"},
        { ArmyType::eNazgulArmy, "Nine Nazguls"},
        { ArmyType::eElfArmy, "Elves Army"},
        { ArmyType::eDwarfArmy, "Dwarfs Army"},
        { ArmyType::eDeadSoulArmy, "Dead Soul Pirates Army"},
        { ArmyType::eEagle, "Eagles!"}
};


class Army {
public:
    explicit Army(ArmyType type);

    void pushUnit(ArmyUnit* unit);

    const std::vector<ArmyUnitPtr>& getUnits() const;

    ArmyType getType() const;

    std::string getInfo() const;


private:
    std::vector<ArmyUnitPtr> _units;
    ArmyType _type;
};

typedef std::shared_ptr<Army> ArmyPtr;



#endif //INC_1_TASK_PATTERN_ARMY_H
