#ifndef __TEXTSOURCER_H__
#define __TEXTSOURCER_H__

#include <string>

namespace rog {
    class TextSourcer {
        public:
            static std::string SourceText(std::string file, int index);
    };
} /* rog */

#endif /* __TEXTSOURCER_H__ */
