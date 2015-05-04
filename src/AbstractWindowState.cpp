#include "AbstractWindowState.h"

namespace rog {
    AbstractWindowState::AbstractWindowState(Machine * _machine, int h, int w, int y, int x) : AbstractState(_machine) {
        window = newwin(h, w, y, x);

    }

    AbstractWindowState::~AbstractWindowState(void) {
        delwin(window);
    }
} /* rog */
