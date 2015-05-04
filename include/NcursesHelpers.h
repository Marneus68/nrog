#ifndef __NCURSESHELPERS_H__
#define __NCURSESHELPERS_H__

#include <string>

#include <ncurses.h>

namespace rog {
    enum class DecorationStyle : int {
        NONE = 0,
        LINE,
        FAT_LINE,
        DOUBLE_LINE,
        DOTTED,
        FAT_DOTTED,
        STRIKED,
        FAT_STRIKED,
        LONG_STRIKED,
        FAT_LONG_STRIKED
    };

    class NcursesHelpers {
        public:
            static void writeCenteredString(std::string str, int y, int x);
            static void decorateWindow(WINDOW *window);
            static void decorateWindow(WINDOW *window, DecorationStyle style);
    };
} /* rog */

#endif /* __NCURSESHELPERS_H__ */
