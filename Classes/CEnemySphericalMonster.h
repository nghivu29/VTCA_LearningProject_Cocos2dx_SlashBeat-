#pragma once
#include "CEnemy.h"

class CEnemySphericalMonster : public CEnemy
{
public:
	static CEnemySphericalMonster* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemySphericalMonster);

	// các hành động của quái
	virtual void dead();
	virtual void hit();
	virtual void idle1();
	virtual void idle2();
	virtual void run1();
	virtual void run2();
	virtual void stun();
	virtual void attack1();
	virtual void attack2();
	virtual void walk1();
	virtual void walk2();

	// loadresouce hero
	virtual bool loadResource();

protected:
	// định nghĩa các hành động của quái
	virtual bool initDead();
	virtual bool initHit();
	virtual bool initIdle1();
	virtual bool initIdle2();
	virtual bool initRun1();
	virtual bool initRun2();
	virtual bool initStun();
	virtual bool initAttack1();
	virtual bool initAttack2();
	virtual bool initWalk1();
	virtual bool initWalk2();
};

