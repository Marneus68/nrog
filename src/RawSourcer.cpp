#include "RawSourcer.h"

#include "constants.h"

#include <iostream>
#include <typeinfo>  
#include <sstream>
#include <fstream>

extern "C" {
#include <fnmatch.h>
#include <libgen.h>
#include <ftw.h>
}

namespace rog {
    std::string RawSourcer::sdescnf = SDESC_NF;

    std::map<std::string, std::string> RawSourcer::sdescs;

    int ftw_callback(const char *fpath, const struct stat *sb, int typeflag) {
        if (FTW_F == typeflag) {
            std::string fname = basename((char*)fpath);

            if ("desc.raw" == fname) {
                std::string line;
                std::ifstream infile(fpath);

                while (std::getline(infile, line)) {
                    std::string key,
                                value;
                    std::stringstream ss(line);
                    ss >> key;
                    ss >> std::ws;
                    std::getline(ss, value);
                    RawSourcer::sdescs.insert(std::pair<std::string, std::string>(key, value));
                }
            }
        }
        return 0;
    }

    void RawSourcer::feedMaps(void) {
        ftw("raw", ftw_callback, 5);
    }

    std::string & RawSourcer::getStaticDescription(char * key) {
       std::string s(key);
       return getStaticDescription(s);
    }

    std::string & RawSourcer::getStaticDescription(const char * key) {
       std::string s(key);
       return getStaticDescription(s);
    }

    std::string & RawSourcer::getStaticDescription(std::string & key) {
        if (sdescs.empty()) {
            feedMaps();
        }
        if (sdescs.count(key))
            return sdescs.at(key);
        return sdescnf;
    }

    std::string RawSourcer::expandString(std::string & str, std::map<std::string, std::string> & repmap) {
        std::string ret("");
        return ret;
    }

} /* rog */

