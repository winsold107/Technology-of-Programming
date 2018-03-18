//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//// Класс "Армия", содержащий все типы боевых единиц
//class Army
//{
//public:
//    vector<InfantryCreature> vi;
//    vector<Archer>      va;
//    vector<WargRider>    vw;
//    vector<Catapult>    vc;
//    vector<UrugHai>    vu;
//    vector<DeadSoul> vd;
//    vector<Mechanisme> vm;
//    vector<GinatWorm> vg;
//    vector<Nazgul> vn;
//    vector<Krebain> vk;
//    vector<Eagle> vea;
//    vector<Enth> ven;
//    vector<ManKing> vmk;
//    void info() {
//        int i;
//        for(i=0; i<vi.size(); ++i)  vi[i].info();
//        for(i=0; i<va.size(); ++i)  va[i].info();
//        for(i=0; i<vw.size(); ++i)  vw[i].info();
//        for(i=0; i<vc.size(); ++i)  vc[i].info();
//        for(i=0; i<vu.size(); ++i)  vu[i].info();
//        for(i=0; i<vd.size(); ++i)  vd[i].info();
//        for(i=0; i<vm.size(); ++i)  vm[i].info();
//        for(i=0; i<vg.size(); ++i)  vg[i].info();
//        for(i=0; i<vn.size(); ++i)  vn[i].info();
//        for(i=0; i<vk.size(); ++i)  vk[i].info();
//        for(i=0; i<vea.size(); ++i)  vea[i].info();
//        for(i=0; i<ven.size(); ++i)  ven[i].info();
//        for(i=0; i<vmk.size(); ++i)  vmk[i].info();
//    }
//};
//
//// Базовый класс ArmyBuilder объявляет интерфейс для поэтапного
//// построения армии и предусматривает его реализацию по умолчанию
//
//class ArmyBuilder
//{
//protected:
//    Army* p;
//public:
//    ArmyBuilder(): p(0) {}
//    virtual ~ArmyBuilder() {}
//    virtual void createArmy() {}
//    virtual void buildInfantryCreature() {}
//    virtual void buildArcher() {}
//    virtual void buildWargRider() {}
//    virtual void buildCatapult() {}
//    virtual void buildUrugHai() {}
//    virtual void buildEnth() {}
//    virtual void buildEagle() {}
//    virtual void buildGiantWorm() {}
//    virtual void buildKrebain() {}
//    virtual void buildDeadSoul() {}
//    virtual void buildNazgul() {}
//    virtual void buildMechanisme() {}
//    virtual void buildManKing() {}
//    virtual Army* getArmy() { return p; }
//};
//
//
//
//
//// армия имеет все типы боевых единиц кроме боевых слонов
//class OrcArmyBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildInfantryCreature() { p->vi.push_back( InfantryCreature()); }
//    void buildArcher() { p->va.push_back( Archer()); }
//    void buildWargRider() { p->vw.push_back( WargRider()); }
//    void buildCatapult() { p->vc.push_back( Catapult()); }
//    void buildUrugHai() { p->vu.push_back( UrugHai()); }
//};
//
//class GoblinArmyBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildInfantryCreature() { p->vi.push_back( InfantryCreature()); }
//    void buildArcher() { p->va.push_back( Archer()); }
//    void buildMechanisme() { p->vm.push_back( Mechanisme()); }
//};
//
//class GiantWormBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildGiantWorm() { p->vg.push_back( GinatWorm()); }
//};
//
//class NazgulBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildNazgul() { p->vn.push_back( Nazgul()); }
//};
//
//class KrebainBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildKrebain() { p->vk.push_back( Krebain()); }
//};
//
//class MankindArmyBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildInfantryCreature() { p->vi.push_back( InfantryCreature()); }
//    void buildArcher() { p->va.push_back( Archer()); }
//    void buildMechanisme() { p->vm.push_back( Mechanisme()); }
//    void buildManKing() {p->vmk.push_back( ManKing()); }
//};
//
//class ElfArmyBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildInfantryCreature() { p->vi.push_back( InfantryCreature()); }
//    void buildArcher() { p->va.push_back( Archer()); }
//};
//
//class DwarfArmyBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildInfantryCreature() { p->vi.push_back( InfantryCreature()); }
//    void buildArcher() { p->va.push_back( Archer()); }
//};
//
//class EnthBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildEnth() { p->ven.push_back( Enth()); }
//};
//
//class EagleBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildEagle() { p->vea.push_back( Eagle()); }
//};
//
//class DeadSoulBuilder: public ArmyBuilder
//{
//public:
//    void createArmy() { p = new Army; }
//    void buildDeadSoul() { p->vd.push_back( DeadSoul()); }
//};
//
//class Side
//{
//public:
//    vector<InfantryCreature> vi;
//    vector<Archer>      va;
//    vector<WargRider>    vw;
//    vector<Catapult>    vc;
//    vector<UrugHai>    vu;
//    vector<DeadSoul> vd;
//    vector<Mechanisme> vm;
//    vector<GinatWorm> vg;
//    vector<Nazgul> vn;
//    vector<Krebain> vk;
//    vector<Eagle> vea;
//    vector<Enth> ven;
//    vector<ManKing> vmk;
//    void info() {
//        int i;
//        for(i=0; i<vi.size(); ++i)  vi[i].info();
//        for(i=0; i<va.size(); ++i)  va[i].info();
//        for(i=0; i<vw.size(); ++i)  vw[i].info();
//        for(i=0; i<vc.size(); ++i)  vc[i].info();
//        for(i=0; i<vu.size(); ++i)  vu[i].info();
//        for(i=0; i<vd.size(); ++i)  vd[i].info();
//        for(i=0; i<vm.size(); ++i)  vm[i].info();
//        for(i=0; i<vg.size(); ++i)  vg[i].info();
//        for(i=0; i<vn.size(); ++i)  vn[i].info();
//        for(i=0; i<vk.size(); ++i)  vk[i].info();
//        for(i=0; i<vea.size(); ++i)  vea[i].info();
//        for(i=0; i<ven.size(); ++i)  ven[i].info();
//        for(i=0; i<vmk.size(); ++i)  vmk[i].info();
//    }
//};
//
//class SideBuilder
//{
//protected:
//    Side* o;
//public:
//    SideBuilder(): o(0) {}
//    virtual ~SideBuilder() {}
//    virtual void createArmy() {}
//    virtual void buildInfantryCreature() {}
//    virtual void buildArcher() {}
//    virtual void buildWargRider() {}
//    virtual void buildCatapult() {}
//    virtual void buildUrugHai() {}
//    virtual void buildEnth() {}
//    virtual void buildEagle() {}
//    virtual void buildGiantWorm() {}
//    virtual void buildKrebain() {}
//    virtual void buildDeadSoul() {}
//    virtual void buildNazgul() {}
//    virtual void buildMechanisme() {}
//    virtual void buildManKing() {}
//    virtual Side* getArmy() { return o; }
//};
//
//
//
//// Класс-распорядитель, поэтапно создающий армию той или иной стороны.
//// Именно здесь определен алгоритм построения армии.
//class Director
//{
//public:
//    Army* createArmy( ArmyBuilder & builder )
//    {
//        builder.createArmy();
//        builder.buildInfantryCreature();
//        builder.buildArcher();
//        builder.buildNazgul();
//        builder.buildCatapult();
//        builder.buildEagle();
//        builder.buildEnth();
//        builder.buildWargRider();
//        builder.buildGiantWorm();
//        builder.buildManKing();
//        builder.buildMechanisme();
//        builder.buildKrebain();
//        builder.buildDeadSoul();
//        return( builder.getArmy());
//    }
//};
//
//
//int start()
//{
//    Director dir;
//    OrcArmyBuilder oa_builder;
//    MankindArmyBuilder ma_builder;
//
//    Army * ra = dir.createArmy( oa_builder);
//    Army * ca = dir.createArmy( ma_builder);
//    cout << "Orcs' Army:" << endl;
//    ra->info();
//    cout << "\nMankind Army:" << endl;
//    ca->info();
//
//    return 0;
//}
//
