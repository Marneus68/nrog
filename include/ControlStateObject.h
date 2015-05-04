#ifndef __CONTROLSTATEOBJECT_H__
#define __CONTROLSTATEOBJECT_H__

namespace rog {
    class ControlStateObject {
        public:
            ControlStateObject (void);
            ControlStateObject (ControlStateObject& cso);
            virtual ~ControlStateObject (void);
    
            ControlStateObject &operator=(ControlStateObject& cso);
    };
} /* rog */

#endif /* __CONTROLSTATEOBJECT_H__ */
