#include "Creature.h"

class Enemy: public Creature {
public:
    Enemy();
    
    static Enemy * create();
    void  onContact() override;
};

