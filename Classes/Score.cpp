#include "Score.h"
#include "ScreenConsts.h"

Score::Score()
{
    scheduleUpdate();

    const int fontSize = 30;

    scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", fontSize);
    scoreTextLabel->setColor(Color3B::WHITE);

    Size textLabelSize = scoreTextLabel->getContentSize();
    Vec2 offset(textLabelSize.width / 1.8, -textLabelSize.height / 2.0);

    scoreTextLabel->setPosition(getLeftUpCorner() + offset);
    addChild(scoreTextLabel, -1);


    scoreLabel = Label::createWithTTF(std::to_string((size_t)score), "fonts/8458.ttf", fontSize);
    scoreLabel->setColor(Color3B::WHITE);

    Size scoreSize = scoreLabel->getContentSize();
    Vec2 scoreOffset(scoreSize.width / 2.0 + textLabelSize.width , -scoreSize.height / 2.0);

    scoreLabel->setAnchorPoint(Vec2(0, 0.5));
    scoreLabel->setPosition(getLeftUpCorner() + scoreOffset);
    addChild(scoreLabel, -1);
}

void Score::update(float delta)
{
    score += delta * scoreMultiplier;
    scoreLabel->setString(std::to_string((size_t)score));
}
