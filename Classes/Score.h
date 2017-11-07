#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Score: public Node {
public:
    Score();
    void update(float delta);

private:
    double score = 0;
    unsigned int scoreMultiplier = 1; 
    cocos2d::Label *scoreLabel = nullptr;
    cocos2d::Label *scoreTextLabel = nullptr;
};
