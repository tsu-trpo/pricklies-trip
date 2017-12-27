#include "CreatureRespawner.h"
#include "Creature.h"
#include "Goodie.h"
#include "Enemy.h"

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
        int value = random(0, 10);
        Creature *creature;
        if (value & 1) {
            creature = Goodie::create();
        } else {
            creature = Enemy::create();
        }
        Size creatureSize = creature->getSize();
        creature->setAnchorPoint(Vec2(0.5, 0.5));

        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        Size visibleSize = Director::getInstance()->getVisibleSize();

        const float relativeHeight = 0.33;
        Point position(origin.x + visibleSize.width + creatureSize.width,
                       origin.y + visibleSize.height * relativeHeight);

        creature->setPosition(position);
        spawnPoint.addChild(creature);
    }
    
    return;
}
