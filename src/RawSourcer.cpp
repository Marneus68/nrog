#include "RawSourcer.h"

#include "constants.h"

#include <iostream>
#include <typeinfo>  
#include <algorithm>  

extern "C" {
#include <fnmatch.h>
#include <libgen.h>
#include <ftw.h>
}

namespace rog {
    static const char * ffilter = "*.raw";

    std::string RawSourcer::sdescnf = SDESC_NF;

    std::map<std::string, std::string> RawSourcer::sdescs;
    std::map<std::string, Race> RawSourcer::races;

    std::map<std::string, std::function<void(std::string)> > RawSourcer::parseactions = {
        { "STATIC_DESCRIPTION", [&](std::string fpath) {
                std::string line;
                std::ifstream infile(fpath);
                int il = 0;
                while (std::getline(infile, line)) {
                    if (0 == il) {
                        il++;
                        continue;
                    }
                    std::string key, value;
                    std::stringstream ss(line);
                    ss >> key;
                    ss >> std::ws;
                    std::getline(ss, value);
                    RawSourcer::sdescs.insert(std::pair<std::string, std::string>(key, value));
                }
            }
        },
        { "RACE", [&](std::string fpath) {
                Race race;
                std::string name = "";
                std::string line;
                std::ifstream infile(fpath);
                int il = 0;
                while (std::getline(infile, line)) {
                    if (0 == il) {
                        il++;
                        continue;
                    }
                    std::string key, value; 
                    std::stringstream ss(line);
                    ss >> key;
                    ss >> std::ws;
                    std::getline(ss, value);
                    if (!key.compare("NAME")) {
                        race.setName(value);
                        name = value;
                    } else if (!key.compare("DESCRIPTION")) {
                        race.setDescription(value);
                    } else if (!key.compare("STR")) {
                        race.setSTR(std::stoi(value));
                    } else if (!key.compare("INT")) {
                        race.setINT(std::stoi(value));
                    } else if (!key.compare("DEX")) {
                        race.setDEX(std::stoi(value));
                    } else if (!key.compare("END")) {
                        race.setEND(std::stoi(value));
                    } else if (!key.compare("CHA")) {
                        race.setCHA(std::stoi(value));
                    } else if (!key.compare("PER")) {
                        race.setPER(std::stoi(value));
                    }
                }
                races[name] = race;
            }
        }
    };

    int ftw_callback(const char *fpath, const struct stat *sb, int typeflag) {
        if (FTW_F == typeflag) {
            if (fnmatch(ffilter, basename((char*)fpath), FNM_CASEFOLD) == 0) {
                std::string line;
                std::ifstream infile(fpath);
                std::string filekey = "";

                if (std::getline(infile, line)) {
                    std::stringstream sskf(line);
                    std::getline(sskf, filekey);
                }

                if (RawSourcer::parseactions.count(filekey))
                    RawSourcer::parseactions.at(filekey)(fpath);
            }
        }
        return 0;
    }

    void RawSourcer::feedMaps(void) {
        ftw("raw", ftw_callback, 5);
    }

    
    std::map<std::string, std::string> & RawSourcer::getStaticDescriptions(void) {
        return sdescs;
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

    std::map<std::string, Race> & RawSourcer::getRaces(void) {
        return races;
    }

    std::string RawSourcer::expandString(std::string & str, std::map<std::string, std::string> & repmap) {
        std::string ret("");
        return ret;
    }

} /* rog */

