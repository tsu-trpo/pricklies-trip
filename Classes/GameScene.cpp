#include <string>
#include "GameScene.h"
#include "Score.h"
#include "CreatureRespawner.h"
#include "BackgroundController.h"
#include "Hero.h"

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
    
    BackgroundController *backgroundController = new BackgroundController(*this);
    addChild(backgroundController, -1);
    
    CreatureRespawner *respawner = new CreatureRespawner(*this);
    addChild(respawner, 0);
   
    Hero* hedgehog = Hero::create();
    addChild(hedgehog, 1);

    return true;
}
