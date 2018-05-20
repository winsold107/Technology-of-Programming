//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMYUNIT_H
#define INC_1_TASK_PATTERN_ARMYUNIT_H

#include <memory>
#include <iostream>
#include <limits>
#include <map>

using namespace std;

enum class UnitType {
    eGiantWorm = 0,
    eNazgul,
    eKrebain,
    eManKing,
    eMechanisme,
    eEagle,
    eDeadSoul,
    eUrugHai,
    eInfantryCreature,
    eArcher,
    eWargRider,
    eCatapult,
    eLastArmyUnitType
};

using UnitTypeToStringMap = std::map<UnitType, std::string>;

using UnitTypeToIntMap = std::map<UnitType, int>;

class ArmyUnit {
public:
    ArmyUnit(UnitType type);

    virtual UnitType getType();

    virtual std::string name() const final;
    virtual void info() = 0;

    virtual int getHealth() {
        return _health;
    }
    virtual int getStrength() {
        return _strength;
    }

protected:
    UnitType _type;
    int _health;
    int _strength;
};

typedef std::shared_ptr<ArmyUnit> ArmyUnitPtr;


// Классы всех возможных родов войск
class InfantryCreature : public ArmyUnit
{
public:

    static constexpr int INFANTRY_INITIAL_HEALTH = 30;
    InfantryCreature();
    virtual void info() override;
private:
    static constexpr int power = 20;
};

class Archer : public ArmyUnit
{
public:
    static constexpr int ARCHER_INITIAL_HEALTH = 40;
    Archer();
    virtual void info() override;
private:
    static constexpr int arrowNumber = 30;
};

class WargRider : public ArmyUnit
{
public:
    static constexpr int WARGRIDER_INITIAL_HEALTH = 50;
    WargRider();
    void info() override;
private:
    static constexpr int power = 50;
};

class Catapult : public ArmyUnit
{
public:
    static constexpr int CATAPULT_INITIAL_HEALTH = 20;
    Catapult();
    virtual void info() override;
private:
    static constexpr int shot = 20;
};

class UrugHai : public ArmyUnit
{
public:
    static constexpr int URUGHAI_INITIAL_HEALTH = 40;
    UrugHai();
    virtual void info() override ;
private:
    static constexpr int power = 60;
};

class Mechanisme : public ArmyUnit
{
public:
    static constexpr int MECHANISME_INITIAL_HEALTH = 20;
    Mechanisme();
    virtual void info();
private:
    static constexpr int power = 40;
};

class GiantWorm : public ArmyUnit
{
public:
    static constexpr int GIANT_WORM_INITIAL_HEALTH = 300;
    GiantWorm();
    virtual void info() override ;
private:
    static constexpr int power = 200;
};

class Nazgul : public ArmyUnit
{
public:
    Nazgul();
    virtual void info() ;
};

class Krebain : public ArmyUnit
{
public:
    Krebain();
    virtual void info();
private:
    static constexpr int harm = 50;
};

class Eagle : public ArmyUnit
{
public:
    Eagle() ;
    virtual void info() override;
private:
    static constexpr int harm = 50;
};

class DeadSoul : public ArmyUnit
{
public:
    static constexpr int DEAD_SOUL_INITIAL_HEALTH = numeric_limits<int>::max();
    DeadSoul();
    virtual void info();
private:
    static constexpr int power = 40;
};

class ManKing : public ArmyUnit
{
public:
    static constexpr int MAN_KING_INITIAL_HEALTH = 40;
    ManKing() ;
    virtual void info() ;
private:
    static constexpr int power = 40;
};


#endif //INC_1_TASK_PATTERN_ARMYUNIT_H
