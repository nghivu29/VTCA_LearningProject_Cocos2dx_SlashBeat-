﻿#pragma once
#include "CActor.h"
#include "CObjDependOnMusic.h"

class CHero : public CActor, public CObjDependOnMusic
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


public:
	virtual bool initWin32Ctrl();
	virtual bool initAndroidCtrl();

	virtual void runTeleEffect();
	virtual void runAfterTeleEffect();

public:
	virtual void hit();

	virtual void comboEffect1();
	void atk1();
	void atk2();
	void atk4();
	void atk5();
};

