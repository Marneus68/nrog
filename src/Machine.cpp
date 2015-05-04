#include "Machine.h"

namespace rog {
    Machine::Machine() {

    }
    
    Machine::Machine(const Machine & _machine) {
        state = _machine.state;
    }

    Machine::~Machine() {
        delete state;
    }

    Machine & Machine::operator=(Machine & _machine) {
        state = _machine.state;
        return *this;
    }

    void Machine::changeState(AbstractState * _state) {
        state = _state;
    }
} /* rog */

