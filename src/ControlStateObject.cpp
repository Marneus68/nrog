#include "ControlStateObject.h"

namespace rog {
    ControlStateObject::ControlStateObject(void) {

    }

    ControlStateObject::ControlStateObject(ControlStateObject& cso) {
        
    }

    ControlStateObject::~ControlStateObject(void) {

    }

    ControlStateObject & ControlStateObject::operator=(ControlStateObject& cso) {
        return cso; 
    }
} /* rog */
