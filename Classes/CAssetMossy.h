#pragma once
#include "cocos2d.h"

class CAssetMossy : public cocos2d::Sprite
{
public:
	static CAssetMossy* createMossy();
	virtual bool init();
	CREATE_FUNC(CAssetMossy);
	virtual void update(float dt);
	virtual bool loadData();

	static CAssetMossy* createMossy(const char* i);
};

