#ifndef __NEWGAMESTATE_H__
#define __NEWGAMESTATE_H__

#include <ncurses.h>

#include "AbstractState.h"

namespace rog {
    class NewGameState : public AbstractState{
        protected:
            WINDOW * listWindow;
            WINDOW * detailWindow;
            WINDOW * navWindow;

        public:
            NewGameState (Machine * _machine);
            virtual ~NewGameState(void);
            virtual void loop(void); 
    };
} /* rog */

#endif /* __NEWGAMESTATE_H__ */
