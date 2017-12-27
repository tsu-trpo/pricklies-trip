#include "Hero.h"
#include "Input.h"
#include "Events.h"
#include "Creature.h"

USING_NS_CC;

Hero::Hero()
{
    initWithFile("Creatures/Hedgehog/hedge_c_1.png");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    setPosition(Vec2(visibleSize.width / 4.0, visibleSize.height / 2.6));
    setScale(0.8);
    
    int pointsNumber = 6; // the number of polygon vertices
    Point points[pointsNumber] = {Point(130, 60), 
                                  Point(160, -35), 
                                  Point(100, -70), 
                                  Point(30, -85), 
                                  Point(-100, -75), 
                                  Point(-150, -50)};

    setPhysicsBody(PhysicsBody::createPolygon(points, pointsNumber));
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);
    _physicsBody->setName(std::string("hero"));

    contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Hero::onContact, this); 
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);    

    RunState* running = new RunState(*this);
    setState(running);
}

Hero* Hero::create()
{
    Hero* hero = new Hero();
    hero->autorelease();

    return hero;
}

void Hero::setState(HeroState* state)
{
    heroState.reset(state);
    heroState->setAnimation();
}

void Hero::onEnter()
{
    Sprite::onEnter();
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}

void Hero::onKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) {    
        heroState->handleInput(Input::JUMP_PRESS);
    }
}

bool Hero::onContact(PhysicsContact &contact) 
{
    PhysicsShape *shape = contact.getShapeA();
    std::string name = "hero";

    if (shape->getBody()->getName() == name) {
        shape = contact.getShapeB();
    }

    auto creature = dynamic_cast<Creature *>(shape->getBody()->getNode());
    creature->onContact();

    return true;
}

