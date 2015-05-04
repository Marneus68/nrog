#ifndef __WORLDMANAGER_H__
#define __WORLDMANAGER_H__

#include <vector>

#include "World.h"

namespace rog {
    class WorldManager {
        protected:
            std::vector<World> worlds;
        public:
            WorldManager (void);
            void updateWorldsList(void);
            void addWorld(World& w);
            void deleteWorld(void);
    };
} /* rog */

#endif /* __WORLDMANAGER_H__ */
