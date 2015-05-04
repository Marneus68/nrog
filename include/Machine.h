#ifndef __MACHINE_H__
#define __MACHINE_H__

#include "AbstractState.h"

namespace rog {
    class AbstractState;
    class Machine {
        protected:
            AbstractState * state;

        public:
            bool running;

            Machine ();
            Machine (const Machine & _machine);
            virtual ~Machine ();

            Machine &operator=(Machine & _machine);

            void changeState(AbstractState * _state);
    };
} /* rog */

#endif /* __MACHINE_H__ */
