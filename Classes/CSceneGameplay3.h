#pragma once
#include "CSceneGameplay.h"

class CSceneGameplay3 : public CSceneGameplay
{
public:
	static CSceneGameplay3* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneGameplay3)
};

