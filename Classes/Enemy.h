#include "Creature.h"

class Enemy: public Creature {
public:
    
    Enemy();
    
    static Enemy * create();
    
    bool onContact(PhysicsContact &contact) override;
private:
    EventListenerPhysicsContact *contactListener = nullptr;
};
