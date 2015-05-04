#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "AbstractState.h"
#include "ControlStateObject.h"

namespace rog {
    class Application : public Machine {
        public:
            ControlStateObject cso;

            Application (void);
            virtual ~Application (void);
            void run(void);
    };
} /* rog */

#endif /* __APPLICATION_H__ */
