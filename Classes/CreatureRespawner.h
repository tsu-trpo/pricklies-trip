#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CreatureRespawner: public Node {
public:
    explicit CreatureRespawner(Node &creatureParent);
    
    void update(float delta);

private:
    const int timeToMove = 2;
    float currentTime = 0;
    Node &spawnPoint;
};
