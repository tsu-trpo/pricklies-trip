#include <string>
#include "GameScene.h"
#include "Score.h"

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
    addChild(score,0);

    scheduleUpdate();

    return true;
}
