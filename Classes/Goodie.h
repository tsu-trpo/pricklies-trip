#pragma once

#include "Creature.h"

class Goodie: public Creature {
public:
    Goodie();

    static Goodie * create();
    void onContact() override;
};

