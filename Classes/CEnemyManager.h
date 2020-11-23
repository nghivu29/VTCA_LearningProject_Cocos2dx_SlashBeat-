#pragma once
#include "CMusic.h"
#include "CActor.h"

class CEnemyManager
{
private:
	CMusic* _music;
	CActor* _target;

public:
	virtual void updateEnemies(float dt);
	void setMusic(CMusic* music);
	void setTarget(CActor* target);
	CEnemyManager(CMusic* music, CActor* target);
};

