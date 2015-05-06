#include "NcursesHelpers.h"

#include <map>
#include <vector>

namespace rog {
    void NcursesHelpers::writeCenteredString(WINDOW *window, std::string str, int y, int x) {
        mvwprintw(window, y, x-(str.size()/2), str.c_str());
    }

    void NcursesHelpers::decorateWindow(WINDOW *window) {
        decorateWindow(window, DecorationStyle::LINE);
    }

    void NcursesHelpers::decorateWindow(WINDOW *window, DecorationStyle style) {
        std::map<DecorationStyle, std::vector<std::string> > styles = {
            { DecorationStyle::NONE, {"",  "", "", "", "", ""}},
            { DecorationStyle::LINE, {"┌", "└", "┐", "┘", "│", "─"}},
            { DecorationStyle::FAT_LINE, {"┏", "┗", "┓", "┛", "┃", "━"}},
            { DecorationStyle::DOUBLE_LINE, {"╔", "╚", "╗", "╝", "║", "═"}},
            { DecorationStyle::DOTTED, {"┌", "└", "┐", "┘", "┊", "┈"}},
            { DecorationStyle::FAT_DOTTED, {"┏", "┗", "┓", "┛", "┋", "┉"}},
            { DecorationStyle::STRIKED, {"┌", "└", "┐", "┘", "┆", "┄"}},
            { DecorationStyle::FAT_STRIKED, {"┏", "┗", "┓", "┛", "┇", "┅"}},
            { DecorationStyle::LONG_STRIKED, {"┌", "└", "┐", "┘", "╎", "╌"}},
            { DecorationStyle::FAT_LONG_STRIKED, {"┏", "┗", "┓", "┛", "╏", "╍"}}
        };
        int x, y, i;

        getmaxyx(window, y, x);

        mvwprintw(window, 0, 0, styles[style][0].c_str());
        mvwprintw(window, y - 1, 0, styles[style][1].c_str());
        mvwprintw(window, 0, x - 1, styles[style][2].c_str());
        mvwprintw(window, y - 1, x - 1, styles[style][3].c_str());
    
        for (i = 1; i < (y - 1); i++) {
            mvwprintw(window, i, 0, styles[style][4].c_str());
            mvwprintw(window, i, x - 1, styles[style][4].c_str());
        }
        
        for (i = 1; i < (x - 1); i++) {
            mvwprintw(window, 0, i, styles[style][5].c_str());
            mvwprintw(window, y - 1, i, styles[style][5].c_str());
        }

        wrefresh(window);
    }
} /* rog */
