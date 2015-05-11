#ifndef __PATHHELPERS_H__
#define __PATHHELPERS_H__

#include <string>

namespace rog {
    class PathHelpers {
        protected:
            static std::string homeDir;
            static std::string localFilesDir;

        public:
            static std::string & getHomeDir(void);
            static std::string & getLocalFilesDir(void);
    };
} /* rog */

#endif /* __PATHHELPERS_H__ */

