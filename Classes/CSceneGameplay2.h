#pragma once
#include "CSceneGameplay.h"

class CSceneGameplay2 : public CSceneGameplay
{
public:
	static CSceneGameplay2* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneGameplay2)
};

