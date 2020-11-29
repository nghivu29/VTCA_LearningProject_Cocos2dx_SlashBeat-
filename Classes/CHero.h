#pragma once
#include "CActor.h"

class CHero : public CActor
{
	// cac thuoc tinh
protected:
	int _frameFly = 0;

private:
	cocos2d::Vec2 center_scene;

	// các phương thức
public:
	static CHero* createHero();
	virtual bool init();
	CREATE_FUNC(CHero);

	// loadresouce hero
	virtual bool loadResource();

	// update hero
	virtual void update(float dt);


protected:
	virtual bool initWin32Ctrl();
	virtual bool initAndroidCtrl();
	virtual bool initCtrl();
};

