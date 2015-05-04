#include "QuitState.h"

#include <string>

#include "NcursesHelpers.h"

#include "MenuState.h"

namespace rog {
    QuitState::QuitState(Machine * _machine) : AbstractState(_machine) {
        std::string quitString = "Are you sure you want to quit? [Y/n]";
        int window_y,
            window_x,
            width = quitString.size()+4;
        getmaxyx(stdscr, window_y, window_x);
        quitWindow = newwin(3, width, window_y/2-1, window_x/2-width/2);
        mvwprintw(quitWindow, 1, 2, quitString.c_str());
        
        NcursesHelpers::decorateWindow(quitWindow, DecorationStyle::DOUBLE_LINE); 
    }

    QuitState::~QuitState(void) {
        delwin(quitWindow);
    }

    void QuitState::loop(void) {
        int ch;
        if (ch = getch()) {
            switch(ch) {
                case 'y':
                case 'Y':
                    machine->running = false;
                    break;
                case 'n':
                case 'N':
                    wclear(stdscr);
                    machine->changeState(new MenuState(machine));
                    break;
            }
        }
    }
} /* rog */

