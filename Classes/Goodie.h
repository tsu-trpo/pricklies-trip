#include "Creature.h"

class Goodie: public Creature {
public:
    Goodie();

    static Goodie * create();

    bool onContact(PhysicsContact &contact) override;
private:
    EventListenerPhysicsContact *contactListener = nullptr;
};
