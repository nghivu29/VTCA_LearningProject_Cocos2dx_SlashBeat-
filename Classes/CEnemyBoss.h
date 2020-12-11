#pragma once
#include "CEnemy.h"
class CEnemyBoss : public CEnemy
{
public:
	static CEnemyBoss* createBoss();
	virtual bool init();
	CREATE_FUNC(CEnemyBoss);

	virtual void dead();
	virtual void hit();
	virtual void idle1();
	virtual void run1();
	virtual void attack1();
	virtual void attack2();

	virtual bool initDead();
	virtual bool initHit();
	virtual bool initIdle1();
	virtual bool initRun1();
	virtual bool initAttack1();
	virtual bool initAttack2();

	virtual bool loadResource();

};

