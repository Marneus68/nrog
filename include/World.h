#ifndef __WORLD_H__
#define __WORLD_H__

#include <string>

namespace rog {
    enum class WorldSize {
        SMALL,
        MEDIUM,
        BIG
    };
    enum class WorldGeometry {
        INSULAR,
        CONTINENTAL
    };
    enum class WorldHistoryLength {
        SHORT,
        MEDIUM,
        LONG
    };
    enum class WorldKind {
        DEFAULT,
        HIGH_FANTASY,
        HARD_FANTASY,
        AFTER_THE_FALL
    };
    enum class WorldAtmosphere {
        DEFAULT,
        FAIRY_TALE,
        GRIMDARK
    };
    class World {
        protected:
            std::string name;
            std::string path;

            WorldSize           worldSize;
            WorldHistoryLength  worldHistoryLength;
            WorldKind           worldKind;
            WorldAtmosphere     worldAtmosphere;
        public:
            World (std::string _path);
            World (World& w);
            virtual ~World (void);
    
            World &operator=(World& w);

            void deleteWorld(void);
            void writeWorld(void);
    };
} /* rog */

#endif /* __WORLD_H__ */
