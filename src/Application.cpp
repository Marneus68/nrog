#include "Application.h"

#include "MenuState.h"

#include <locale.h>
#include <ncurses.h>

namespace rog {
    Application::Application(void) {
        setlocale(LC_CTYPE,"");
        initscr();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(FALSE);

        raw();

        running = true;
        state = new MenuState(this);
    }

    Application::~Application(void) {
        endwin(); 
    }

    void Application::run(void) {
        while (running) {
            state->loop();
        }
    }
} /* rog */
