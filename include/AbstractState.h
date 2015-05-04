#ifndef __ABSTRACTSTATE_H__
#define __ABSTRACTSTATE_H__

#include "Machine.h"

namespace rog {
    class Machine;
    class AbstractState {
        protected:
            Machine * machine;
        public:
            AbstractState(Machine * _machine);
            virtual void loop(void);
    };
} /* rog */

#endif /* __ABSTRACTSTATE_H__ */
