#include "TextSourcer.h"

#include "constants.h"

#include <iostream>
#include <typeinfo>  
#include <sstream>
#include <fstream>

extern "C" {
#include <sys/types.h>
#include <fnmatch.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <pwd.h>
#include <ftw.h>
}

namespace rog {
    std::string TextSourcer::homeDir = "";
    std::string TextSourcer::localFilesDir = "";

    std::string TextSourcer::sdescnf = SDESC_NF;

    std::map<std::string, std::string> TextSourcer::sdescs = {};

    int ftw_sdesc_callback(const char *fpath, const struct stat *sb, int typeflag) {
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
                    TextSourcer::sdescs.insert(std::pair<std::string, std::string>(key, value));
                }
            }
        }
    }

    void TextSourcer::feedStaticDescriptions(void) {
        ftw("raw", ftw_sdesc_callback, 5);
    }

    std::string & TextSourcer::getStaticDescription(char * key) {
       std::string s(key);
       return getStaticDescription(s);
    }

    std::string & TextSourcer::getStaticDescription(const char * key) {
       std::string s(key);
       return getStaticDescription(s);
    }

    std::string & TextSourcer::getStaticDescription(std::string & key) {
        if (sdescs.empty()) {
            feedStaticDescriptions();
        }
        if (sdescs.count(key))
            return sdescs.at(key);
        return sdescnf;
    }

    std::string TextSourcer::expandString(std::string & str, std::map<std::string, std::string> & repmap) {
        std::string ret("");
        return ret;
    }

    std::string & TextSourcer::getHomeDir(void) {
        if (homeDir.empty()) {
            auto envHome = getenv("HOME");
            if (NULL != envHome) {
                homeDir = getpwuid(getuid())->pw_dir; 
            } else {
                homeDir = envHome;
            }
        }
        return homeDir;
    }

    std::string & TextSourcer::getLocalFilesDir(void) {
        if (localFilesDir.empty()) {
            std::string rep = "~/";
            std::string ret(LOCAL_FILES_DIR);
            std::string home = getHomeDir() + "/";
            size_t index = 0;
            index = ret.find(rep.c_str(), index);
            ret.replace(index, rep.size(), home.c_str());
            localFilesDir = ret;
        }
        return localFilesDir;
    }

} /* rog */

