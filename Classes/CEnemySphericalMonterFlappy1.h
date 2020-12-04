#pragma once
#include "CEnemySphericalMonter.h"

class CEnemySphericalMonterFlappy1 : public CEnemySphericalMonter
{
public:
	static CEnemySphericalMonterFlappy1* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemySphericalMonterFlappy1);

	virtual bool initHit();
	virtual bool initIdle1();

	virtual bool loadResource();
};

