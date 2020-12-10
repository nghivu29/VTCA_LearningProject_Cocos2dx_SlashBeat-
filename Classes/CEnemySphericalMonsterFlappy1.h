#pragma once
#include "CEnemySphericalMonster.h"

class CEnemySphericalMonsterFlappy1 : public CEnemySphericalMonster
{
public:
	static CEnemySphericalMonsterFlappy1* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemySphericalMonsterFlappy1);

	virtual bool initHit();
	virtual bool initIdle1();

	virtual bool loadResource();
};

