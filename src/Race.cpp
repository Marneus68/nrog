#include "Race.h"

namespace rog {
    Race::Race (void) :
        name("DEFAULT RACE"),
        description("DEFAULT RACE"),
        _str(0),
        _int(0),
        _dex(0),
        _end(0),
        _cha(0),
        _per(0) {}

    Race::Race (std::string & _name, std::string & _description, int a, int b, int c, int d, int e, int f) :
        name(_name),
        description(_description),
        _str(a),
        _int(b),
        _dex(c),
        _end(d),
        _cha(e),
        _per(f) {}

    Race::Race (const Race & _race) {
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

    std::string Race::toString(void) {
        std::string str; 
        str = name + " " + 
                std::to_string(_str) + ":" +
                std::to_string(_int) + ":" +
                std::to_string(_dex) + ":" +
                std::to_string(_end) + ":" +
                std::to_string(_cha) + ":" +
                std::to_string(_per);
        return str;
    }

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

    void Race::setName(std::string & _name) { name = _name; }
    void Race::setDescription(std::string & _desc) { description = _desc; }

    void Race::setSTR(int val) { _str = val; }
    void Race::setINT(int val) { _int = val; }
    void Race::setDEX(int val) { _dex = val; }
    void Race::setEND(int val) { _end = val; }
    void Race::setCHA(int val) { _cha = val; }
    void Race::setPER(int val) { _per = val; }
} /* rog */

