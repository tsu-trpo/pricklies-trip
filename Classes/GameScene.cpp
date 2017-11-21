#include <string>
#include "GameScene.h"
#include "Score.h"
#include "CreatureRespawner.h"
#include "BackGroundController.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }

    Score *score = new Score();
    addChild(score, 0);
    
    BackGroundController *backController = new BackGroundController(*this);
    addChild(backController, -1);
    
    CreatureRespawner *respawner = new CreatureRespawner(*this);
    addChild(respawner, 0);
    
    return true;
}
