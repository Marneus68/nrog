#ifndef __RAWSOURCER_H__
#define __RAWSOURCER_H__

#include <map>
#include <string>

/* sdesc = static descriptions */

namespace rog {
    class RawSourcer {
        protected:
            static std::string sdescnf;

        public:
            static std::map<std::string, std::string> sdescs;

            static void feedMaps(void);

            static std::string & getStaticDescription(char * key);
            static std::string & getStaticDescription(const char * key);
            static std::string & getStaticDescription(std::string & key);

            static std::string expandString(std::string & str, std::map<std::string, std::string> & repmap);
    };
} /* rog */

#endif /* __RAWSOURCER_H__ */
