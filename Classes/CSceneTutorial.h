#pragma once
#include "CSceneGameplay.h"

class CSceneTutorial : public CSceneGameplay
{
public:
	cocos2d::Sprite* _imgTutorial;

	static CSceneTutorial* createScene();
	virtual bool init();
	virtual bool initBackground();
	virtual void showTutorial();

	CREATE_FUNC(CSceneTutorial);

};

