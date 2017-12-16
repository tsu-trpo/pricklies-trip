#include "HelloWorldScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Vector<MenuItem*> MenuItems;
    
    auto startItem = MenuItemImage::create("Button/playButton.png",
                                           "Button/playButton.png",
                                           CC_CALLBACK_1(HelloWorld::goToGameScene, this));
    startItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                origin.y + startItem->getContentSize().height / 2 + 100));
    MenuItems.pushBack(startItem);
    
    auto closeItem = MenuItemImage::create("Button/exitButton.png",
                                           "Button/exitButton.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2 - 10,
                                origin.y + closeItem->getContentSize().height / 2 + 10));
    MenuItems.pushBack(closeItem);
    
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto background = Sprite::create("Background/background.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                 visibleSize.height / 2 + origin.y));
    this->addChild(background, 0);

    return true;
}

void HelloWorld::menuCloseCallback(Ref *pSender)
{
    Director::getInstance()->end();
}

void HelloWorld::goToGameScene(Ref *sender)
{
    const float transitionTime = 0.5;
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(transitionTime, scene));
}

