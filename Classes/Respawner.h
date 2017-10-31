#pragma once
#include "cocos2d.h"
#include "Creature.h"

USING_NS_CC;

class Respawner: public Node {
public:
    Respawner();
    Respawner(Scene * gameScene);
    void update(float delta);

private:
    const int timeToMove = 2;
    float currentTime;
    Scene * scene;
};