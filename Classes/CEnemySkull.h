#pragma once
#include "CEnemySphericalMonter.h"

class CEnemySkull : public CEnemySphericalMonter
{
public:
	static CEnemySkull* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemySkull);

	virtual bool initHit();
	virtual bool initIdle1();

	virtual bool loadResource();
};

