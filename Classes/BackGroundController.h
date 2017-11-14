#pragma once

#include "cocos2d.h"

USING_NS_CC;

class BackGroundController: public Node {
public:
    explicit BackGroundController(Node &backgroundParent);

private:
    Node &startPoint;
};

