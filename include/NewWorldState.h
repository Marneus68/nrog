#ifndef __NEWWORLDSTATE_H__
#define __NEWWORLDSTATE_H__

#include <ncurses.h>

#include <string>

#include "AbstractState.h"

namespace rog {
    class NewWorldState : public AbstractState {
        protected:
            int window_x, 
                window_y;
            WINDOW * mainWindow;
            WINDOW * navWindow;
            std::string navString;

        public:
            NewWorldState (Machine * _machine);
            virtual ~NewWorldState(void);
            virtual void loop(void);

            void draw(void);
    };
} /* rog */

#endif /* __NEWWORLDSTATE_H__ */

