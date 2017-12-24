#include "CreatureRespawner.h"
#include "Creature.h"

CreatureRespawner::CreatureRespawner(Node &creatureParent): currentTime{0}, 
                                                            spawnPoint{creatureParent} 
{
    scheduleUpdate();
}

CreatureRespawner* CreatureRespawner::create(Node &creatureParent)
{
    CreatureRespawner* respawner = new CreatureRespawner(creatureParent);
    respawner->autorelease();

    return respawner;
}

void CreatureRespawner::update(float delta)
{
    currentTime += delta;
    
    if (currentTime > timeToMove) {
        currentTime = 0;
        Creature *creature = Creature::create();
        Size creatureSize = creature->getSize();
        creature->setAnchorPoint(Vec2(0.5, 0.5));

        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size visibleSize = Director::getInstance()->getVisibleSize();

        const float relativeHeight = 0.3;
        Point position(origin.x + visibleSize.width + creatureSize.width,
                       origin.y + visibleSize.height * relativeHeight);

        creature->setPosition(position);
        spawnPoint.addChild(creature);
    }
    
    return;
}
