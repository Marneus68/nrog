#include "PathHelpers.h"

#include "constants.h"

extern "C" {
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
}

namespace rog {
    std::string PathHelpers::homeDir = "";
    std::string PathHelpers::localFilesDir = "";

    std::string & PathHelpers::getHomeDir(void) {
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

    std::string & PathHelpers::getLocalFilesDir(void) {
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

