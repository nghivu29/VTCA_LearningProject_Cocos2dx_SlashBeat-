#pragma once
#include "CMusic.h"
#include "CEnemy.h"

class CEnemyManager
{
private:
	CMusic* _music;
	CActor* _target;



public:
	virtual void updateEnemies(float dt);
	static CEnemy* createMonster(int enemyName, CActor* target);
	void setMusic(CMusic* music);
	void setTarget(CActor* target);
	CEnemyManager(CMusic* music, CActor* target);
};

