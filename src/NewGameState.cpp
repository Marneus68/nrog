#include "NewGameState.h"

#include "MenuState.h"

#include "NcursesHelpers.h"

namespace rog {
    NewGameState::NewGameState(Machine * _machine) : AbstractState(_machine) {
        std::string navString = "[q] Back  [n] New  [x] Delete";

        int window_x,
            window_y;

        getmaxyx(stdscr, window_y, window_x);

        navWindow = newwin(3, window_x, window_y-3, 0);
        listWindow = newwin(window_y-3 ,window_x*0.3, 0, 0);
        detailWindow = newwin(window_y-3, window_x*0.7, 0, window_x*0.3);

        mvwprintw(navWindow, 1, 2, navString.c_str());

        NcursesHelpers::decorateWindow(navWindow, DecorationStyle::DOUBLE_LINE);
        NcursesHelpers::decorateWindow(listWindow, DecorationStyle::LINE);
        NcursesHelpers::decorateWindow(detailWindow, DecorationStyle::LINE);
    }

    NewGameState::~NewGameState(void) {
        delwin(listWindow);
        delwin(detailWindow);
        delwin(navWindow);
    }

    void NewGameState::loop(void) {
        int ch;
        if ((ch = getch())) {
            switch(ch) {
                case 'q':
                    wclear(stdscr);
                    machine->changeState(new MenuState(machine));
                    break;
                case 'n':
                    break;
                case 'x':
                    break;
            }
        }
    }
} /* rog */
