#ifndef __ABSTRACTWINDOWSTATE_H__
#define __ABSTRACTWINDOWSTATE_H__

#include <ncurses.h>

#include "AbstractState.h"

namespace rog {
    class AbstractWindowState : public AbstractState {
        protected:
            WINDOW * window;
        public:
            AbstractWindowState(Machine * _machine, int h, int w, int y, int x);
            virtual ~AbstractWindowState(void);
    };
} /* rog */

#endif /* __ABSTRACTWINDOWSTATE_H__ */
