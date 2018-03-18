//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_ARMYUNIT_H
#define INC_1_TASK_PATTERN_ARMYUNIT_H

#include <memory>
#include <iostream>

using namespace std;

enum class UnitType {
    eGiantWorm,
    eNazgul,
    eKrebain,
    eManKing,
    eMechanisme,
    eEnth,
    eEagle,
    eDeadSoul,
    eUrugHai,
    eInfantryCreature,
    eArcher,
    eWargRider,
    eCatapult
};

class ArmyUnit {
public:
    ArmyUnit(UnitType type);

    virtual UnitType getType();;
    virtual void info() = 0;
private:
    UnitType _type;
};

typedef std::shared_ptr<ArmyUnit> ArmyUnitPtr;


// Классы всех возможных родов войск
class InfantryCreature : public ArmyUnit
{
public:
    InfantryCreature();
    virtual void info() override;
};

class Archer : public ArmyUnit
{
public:
    Archer();
    virtual void info() override;
//private:
//    std::size_t _arrowNumber;
};

class WargRider : public ArmyUnit
{
public:
    WargRider();
    void info() override;
};

class Catapult : public ArmyUnit
{
public:
    Catapult();
    virtual void info() override;
};

class UrugHai : public ArmyUnit
{
public:
    UrugHai();
    virtual void info() override ;
};

class Mechanisme : public ArmyUnit
{
public:
    Mechanisme();
    virtual void info();
};

class GiantWorm : public ArmyUnit
{
public:
    GiantWorm();
    virtual void info() override ;
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
};

class Enth : public ArmyUnit
{
public:
    Enth() ;
    void info() override;
};

class Eagle : public ArmyUnit
{
public:
    Eagle() ;
    virtual void info() override;
};

class DeadSoul : public ArmyUnit
{
public:
    DeadSoul();
    virtual void info();
};

class ManKing : public ArmyUnit
{
public:
    ManKing() ;
    virtual void info() ;
};


#endif //INC_1_TASK_PATTERN_ARMYUNIT_H
