#include "Damageable.h"

namespace rog {
    Damageable::Damageable(void) : Damageable(0, 0, false, false) {}
    Damageable::Damageable(int thr) : Damageable(0, thr, false, false) {}
    Damageable::Damageable(int val, int thr) : Damageable(0, 0, false, false) {}
    Damageable::Damageable(int val, int thr, bool inv) : Damageable(0, 0, false, false) {}
    Damageable::Damageable(int val, int thr, bool inv, bool imm) {
        hp = val;
        invuln = inv;
        immortal = imm;
    }

    bool Damageable::hit(int val) {
        hp-=val;
        return isDead();
    }

    bool Damageable::heal(int val) {
        hp+=val;
        return isDead();
    }

    bool Damageable::isAlive(void) {
        if (hp > threshold)
            return true;
        return false;
    }

    bool Damageable::isDead(void) {
        if (hp <= threshold)
            return true;
        return false;
    }
} /* rog */

