#include "Respawner.h"

Respawner::Respawner(Node &gameNode):currentTime{0}, node{gameNode} 
{
    scheduleUpdate();
}

void Respawner::update(float delta)
{
    currentTime += delta;
    
    if (currentTime > timeToMove) {
        currentTime = 0;
        Creature *creature = new Creature;
        Size creatureSize = creature->getSize();
        creature->setAnchorPoint(Vec2(0.5, 0.5));

        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size visibleSize = Director::getInstance()->getVisibleSize();

        const float relativeHeight = 0.3;
        Point position(origin.x + visibleSize.width + creatureSize.width,
                       origin.y + visibleSize.height * relativeHeight);

        creature->setPosition(position);
        node.addChild(creature);
    }
    
    return;
}

