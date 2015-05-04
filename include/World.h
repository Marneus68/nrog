#ifndef __WORLD_H__
#define __WORLD_H__

#include <string>

namespace rog {
    enum class WorldSize {
        SMALL,
        MEDIUM,
        BIG
    };
    enum class WorldHistorySize {
        SHORT,
        MEDIUM,
        LONG
    };
    class World {
        protected:
            std::string name;
        public:
            World (void);
            World (World& w);
            virtual ~World (void);
    
            World &operator=(World& w);

            void deleteWorld(void);
            void writeWorld(void);
    };
} /* rog */

#endif /* __WORLD_H__ */
