//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMY_H
#define INC_1_TASK_PATTERN_ARMY_H


#include <vector>
#include "ArmyUnit.h"
#include <unordered_map>
#include <map>
#include <sstream>

enum class ArmyType {
    eOrcArmy,
    eMankindArmy,
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
        { ArmyType::eOrcArmy, "Orcs army" },
        { ArmyType::eMankindArmy, "Mankind army" },
        { ArmyType::eGoblinArmy, "Goblins Army"},
        { ArmyType::eKrebainArmy, "The Army of Krebains from Dunland"},
        { ArmyType::eGiantWormArmy, "Giant worm Army"},
        { ArmyType::eNazgulArmy, "Nine Nazguls"},
        { ArmyType::eElfArmy, "Elves Army"},
        { ArmyType::eDwarfArmy, "Dwarfs Army"},
        { ArmyType::eDeadSoulArmy, "Dead Soul Pirates Army"},
        { ArmyType::eEagle, "Eagles"}

};

using ArmyTypeToIntMap = std::map<ArmyType, int>;


extern UnitTypeToStringMap UnitTypesStrings;


class Army {
public:
    explicit Army(ArmyType type);

    void pushUnit(ArmyUnit* unit);

    const std::vector<ArmyUnitPtr>& getUnits() const;

    ArmyType getType() const;

    std::string getInfo() const;

    ArmyType getAmount() const;

    string getState() const {
        ArmyInfo info(_units);
        return info.getAsString();
    }


private:

    std::vector<ArmyUnitPtr> _units;

private:

    class ArmyInfo {
    public:
        ArmyInfo(const std::vector<ArmyUnitPtr>& _units) {
            UnitTypeToIntMap counts;
            for (const auto& unit: _units) {
                UnitType type = unit->getType();
                if (counts.find(type) != counts.end()) {
                    counts[type] = 0;
                }

                counts[type]++;
            }

            ss << "Army has:" << std::endl;
            for (const auto& it: counts) {
                ss << UnitTypesStrings[it.first] << endl;
            }
        }

        string getAsString() const {
            return ss.str();
        }

    private:
        stringstream ss;

    };

    ArmyType _type;
    ArmyType _amount;
};

typedef std::shared_ptr<Army> ArmyPtr;





#endif //INC_1_TASK_PATTERN_ARMY_H
