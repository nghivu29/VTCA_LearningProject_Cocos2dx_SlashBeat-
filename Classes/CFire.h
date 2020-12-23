#pragma once
#include "cocos2d.h"
#include "CEnemy.h"

class CFire : public CEnemy
{
public:
	int _lane;;
	cocos2d::Sprite* _dragon;

private:
	const cocos2d::Size visible = cocos2d::Director::getInstance()->getVisibleSize();
	const cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	int count = 0;

public:
	static CFire* createFire();
	static CFire* createFire(float lifeTime);
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(CFire);

	virtual void run1();

	virtual void attack1();

	virtual bool initRun1();

	virtual bool loadResource();

};

