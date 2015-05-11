#include "Race.h"

namespace rog {
    Race::Race (void) :
        name("DEFAULT RACE"),
        description("DEFAULT RACE"),
        _str(50),
        _int(50),
        _dex(50),
        _end(50),
        _cha(50),
        _per(50) {}

    Race::Race (std::string & _name, std::string & _description, int a, int b, int c, int d, int e, int f) :
        name(_name),
        description(_description),
        _str(a),
        _int(b),
        _dex(c),
        _end(d),
        _cha(e),
        _per(f) {}

    Race::Race (Race & _race) {
        name = _race.name;
        description = _race.description;
        _str = _race._str;
        _int = _race._int;
        _dex = _race._dex;
        _end = _race._end;
        _cha = _race._cha;
        _per = _race._per;
    }

    Race::~Race (void) {}

    Race & Race::operator=(Race & _race) {
        name = _race.name;
        description = _race.description;
        _str = _race._str;
        _int = _race._int;
        _dex = _race._dex;
        _end = _race._end;
        _cha = _race._cha;
        _per = _race._per;
        return _race;
    }

    std::string & Race::getName(void) { return name; }
    std::string & Race::getDescription(void) { return description; }

    int Race::getSTR(void) { return _str; }
    int Race::getINT(void) { return _int; }
    int Race::getDEX(void) { return _dex; }
    int Race::getEND(void) { return _end; }
    int Race::getCHA(void) { return _cha; }
    int Race::getPER(void) { return _per; }

} /* rog */
