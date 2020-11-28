#pragma once
#include "CActor.h"

class CHero : public CActor
{
	cocos2d::Vec2 center_scene;

	// các phương thức
public:
	static CHero* createHero();
	virtual bool init();
	CREATE_FUNC(CHero);

	// loadresouce hero
	virtual bool loadResource();

private:
	virtual bool initWin32Ctrl();
	virtual bool initAndroidCtrl();
	virtual bool initCtrl();
};

