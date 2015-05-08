#ifndef __TEXTSOURCER_H__
#define __TEXTSOURCER_H__

#include <map>
#include <string>

/* sdesc = static descriptions */

namespace rog {
    class TextSourcer {
        private:
            static std::string homeDir;
            static std::string localFilesDir;

            static std::string sdescnf;

        public:
            static std::map<std::string, std::string> sdescs;

            static void feedStaticDescriptions(void);

            static std::string & getStaticDescription(char * key);
            static std::string & getStaticDescription(const char * key);
            static std::string & getStaticDescription(std::string & key);

            static std::string expandString(std::string & str, std::map<std::string, std::string> & repmap);

            static std::string & getHomeDir(void);
            static std::string & getLocalFilesDir(void);
    };
} /* rog */

#endif /* __TEXTSOURCER_H__ */
