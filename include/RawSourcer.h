#ifndef __RAWSOURCER_H__
#define __RAWSOURCER_H__

#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>

#include "Race.h"

/* sdesc = static descriptions */

namespace rog {
    class RawSourcer {
        protected:
            static std::string sdescnf;

        public:
            static std::map<std::string, std::function<void(std::string)> > parseactions;
            static std::map<std::string, std::string> sdescs;
            static std::map<std::string, Race> races;

            static void feedMaps(void);

            static std::map<std::string, std::string> & getStaticDescriptions(void);
            static std::string & getStaticDescription(char * key);
            static std::string & getStaticDescription(const char * key);
            static std::string & getStaticDescription(std::string & key);

            static std::map<std::string, Race> & getRaces(void);

            static std::string expandString(std::string & str, std::map<std::string, std::string> & repmap);
    };
} /* rog */

#endif /* __RAWSOURCER_H__ */

