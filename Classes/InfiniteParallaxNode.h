#pragma once
#include "cocos2d.h"

class InfiniteParallaxNode : public cocos2d::ParallaxNode
{
public:
	static InfiniteParallaxNode* create(); // Tạo InfiniteParallaxNode
	void updatePosition(); // Update lại vị trí
};

