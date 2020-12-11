#pragma once
#include "cocos2d.h"
#include "CEnemy.h"


class CEnemyFromBoss0 : public CEnemy
{
private:
	CActor* _owner;

public:

	static CEnemyFromBoss0* createSkill();
	virtual bool init();
	CREATE_FUNC(CEnemyFromBoss0);

	virtual void hit();
	virtual void hitBoss();

	//setter
	void setOwner(CActor* owner);
};

