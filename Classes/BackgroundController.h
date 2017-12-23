#pragma once

#include "cocos2d.h"

USING_NS_CC;

class BackgroundController: public Node {
public:
    explicit BackgroundController(Node &backgroundParent);
    static BackgroundController* create(Node &backgroundParent);

private:
    Node &startPoint;
};
