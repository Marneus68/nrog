#include "NewWorldState.h"

#include <map>
#include <string>
#include <algorithm>

#include "RawSourcer.h"
#include "PathHelpers.h"
#include "NcursesHelpers.h"
#include "NewGameState.h"

namespace rog {
    NewWorldState::NewWorldState(Machine * _machine) : AbstractState(_machine) {
        navString = "[q] Back  [g] Generate Name  [i] Input Name  [G] GENERATE";
        draw();
    }

    NewWorldState::~NewWorldState(void) {
        delwin(navWindow);
    }

    void NewWorldState::loop(void) {
        int ch;
        if ((ch = getch())) {
            switch(ch) {
                case 'q':
                    //wclear(stdscr);
                    machine->changeState(new NewGameState(machine));
                    break;
                case 'g':
                    break;
                case 'i': {
                    getmaxyx(stdscr, window_y, window_x);

                    WINDOW * inputWindow;
                    int w = window_x/3,
                        h = 3;
                    inputWindow = newwin(h, w, window_y/2-h/2, window_x/2-w/2);
                    NcursesHelpers::decorateWindow(inputWindow, DecorationStyle::DOUBLE_LINE);
                    NcursesHelpers::writeCenteredString(inputWindow, "Input a name:", 0, w/2);
                    char str[1024];
                    echo();
                    mvwgetnstr(inputWindow, 1, 2, str, w-2);
                    noecho();

                    wclear(inputWindow);
                    delwin(inputWindow);
                    refresh();
                    draw();

                    break;
                }
                case 'G':
                    break;
            }
        }
    }

    void NewWorldState::draw(void) {
        clear();
        refresh();
        getmaxyx(stdscr, window_y, window_x);
        mainWindow = newwin(window_y-3, window_x, 0, 0);
        navWindow = newwin(3, window_x, window_y-3, 0);
        mvwprintw(navWindow, 1, 2, navString.c_str());
        NcursesHelpers::decorateWindow(navWindow, DecorationStyle::DOUBLE_LINE);
        NcursesHelpers::decorateWindow(mainWindow, DecorationStyle::LINE);

        NcursesHelpers::writeCenteredString(mainWindow, "Creating a new world", 0, window_x/2);
        
        mvwprintw(mainWindow, 2, 2, PathHelpers::getHomeDir().c_str());
        mvwprintw(mainWindow, 3, 2, PathHelpers::getLocalFilesDir().c_str());
        mvwprintw(mainWindow, 4, 2, RawSourcer::getStaticDescription("WorldSize").c_str());
        mvwprintw(mainWindow, 5, 2, RawSourcer::getStaticDescription("WorldHistoryLength").c_str());
        mvwprintw(mainWindow, 6, 2, RawSourcer::getStaticDescription("lkjfhsdlkjfh").c_str());

        mvwprintw(mainWindow, 7, 2, std::to_string(RawSourcer::getRaces().size()).c_str());

        int ccc = 8;
        for(auto p : RawSourcer::getRaces()) {
            mvwprintw(mainWindow, ccc, 2, p.second.toString().c_str());
            ccc++;
        }

        wrefresh(mainWindow);
        wrefresh(navWindow);
        refresh();
    }
} /* rog */

