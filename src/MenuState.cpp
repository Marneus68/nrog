#include "MenuState.h"

#include <ncurses.h>

#include "NewGameState.h"
#include "QuitState.h"

#include "NcursesHelpers.h"

namespace rog {
    MenuState::MenuState(Machine * _machine) : AbstractState(_machine) {
        menuItems = {
            "[n] New Game     ",
            "[l] Load Game    ",
            "[c] Configuration",
            "[a] About        ",
            "[q] Quit         "
        };

        menuItemActions = {
            {'n', [=](){machine->changeState(new NewGameState(machine));}},
            {'q', [=](){machine->changeState(new QuitState(machine));}}
        };
    }

    void MenuState::loop(void) {
        int ch, i=0;

        getmaxyx(stdscr, window_y, window_x);

        //wclear(stdscr);

        for(auto it = menuItems.begin(); it != menuItems.end(); it++) {
            NcursesHelpers::writeCenteredString(*it, window_y/2+i, window_x/2); 
            i++;
        }

        NcursesHelpers::writeCenteredString("2015", window_y-1, window_x/2);

        if ((ch = getch())) {
            for(auto it = menuItemActions.begin(); it != menuItemActions.end(); it++) {
                if (ch == it->first) {
                    it->second();
                }
            }
        }
    }
} /* rog */

