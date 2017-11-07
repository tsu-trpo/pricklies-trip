#include "Score.h"
#include "ScreenConsts.h"

Score::Score()
{
    scheduleUpdate();

    scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", 30);
    scoreTextLabel->setColor(Color3B::WHITE);

    Size contentSize = scoreTextLabel->getContentSize();
    Vec2 offset(contentSize.width / 1.8, -contentSize.height / 2.0);

    scoreTextLabel->setPosition(getLeftUpCorner() + offset);
    this->addChild(scoreTextLabel, -1);


    scoreLabel = Label::createWithTTF(std::to_string((size_t)score), "fonts/8458.ttf", 30);
    scoreLabel->setColor(Color3B::WHITE);

    Size scoreSize = scoreLabel->getContentSize();
    Vec2 offsetScore(scoreSize.width / 2.0 + contentSize.width , -scoreSize.height / 2.0);

    scoreLabel->setAnchorPoint(Vec2(0, 0.5));
    scoreLabel->setPosition(getLeftUpCorner() + offsetScore);
    this->addChild(scoreLabel, -1);
}

void Score::update(float delta)
{
    score += delta * scoreMultiplier;
    scoreLabel->setString(std::to_string((size_t)score));

}
