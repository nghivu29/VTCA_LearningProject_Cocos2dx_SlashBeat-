#pragma once
#include "cocos2d.h"

/*
Chua su dung duoc
*/

class CSceneLoading : public cocos2d::Scene
{
public:
	static CSceneLoading* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneLoading);
};

