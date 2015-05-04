#ifndef __QUITSTATE_H__
#define __QUITSTATE_H__

#include <ncurses.h>

#include "AbstractState.h"

namespace rog {
    class QuitState : public AbstractState {
        protected:
            WINDOW * quitWindow;
        public:
            QuitState (Machine * _machine);
            virtual ~QuitState(void);
            virtual void loop(void);
    };
} /* rog */

#endif /* __QUITSTATE_H__ */

