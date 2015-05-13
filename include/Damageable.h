#ifndef __DAMAGEABLE_H__
#define __DAMAGEABLE_H__

namespace rog {
    class Damageable {
        protected:
            bool invuln;
            bool immortal;
            int hp;
            int threshold;
    
        public:
            Damageable(void);
            Damageable(int thr);
            Damageable(int val, int thr);
            Damageable(int val, int thr, bool inv);
            Damageable(int val, int thr, bool inv, bool imm);
            
            bool hit(int val);
            bool heal(int val);
            
            bool isAlive(void);
            bool isDead(void);
    };
} /* rog */

#endif /* __DAMAGEABLE_H__ */

