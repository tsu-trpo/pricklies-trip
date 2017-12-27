#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CreatureRespawner: public Node {
public:
    explicit CreatureRespawner(Node &creatureParent);
    static CreatureRespawner* create(Node &creatureParent);
    
    void update(float delta);

private:
    const float timeToMove = 2.5;
    float currentTime = 0;
    Node &spawnPoint;
};
