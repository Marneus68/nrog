#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <functional>

#include "AbstractState.h"

namespace rog {
    class MenuState;
    typedef std::map<char, std::function<void()> > MenuItemActions;
    typedef std::vector<std::string> MenuItems;
    class MenuState : public AbstractState {
        public:
            MenuItems menuItems;
            MenuItemActions menuItemActions;
            int index = 0,
                window_x,
                window_y;

            MenuState (Machine * _machine);
            virtual void loop(void);
    };
} /* rog */

#endif /* __MENUSTATE_H__ */
