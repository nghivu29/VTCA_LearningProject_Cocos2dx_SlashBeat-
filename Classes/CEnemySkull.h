#pragma once
#include "CEnemySphericalMonster.h"

class CEnemySkull : public CEnemySphericalMonster
{
public:
	static CEnemySkull* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemySkull);

	virtual bool initHit();
	virtual bool initIdle1();

	virtual bool loadResource();
};

