#pragma once
#include "CEnemy.h"

class CEnemyRock : public CEnemy
{
public:
	static CEnemyRock* createMonster();
	virtual bool init();
	CREATE_FUNC(CEnemyRock);

	// các hành động của quái
	virtual void hit();

};

