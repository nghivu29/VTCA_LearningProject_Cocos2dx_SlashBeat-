#pragma once
#include "CMusic.h"

class CEnemyManager
{
private:
	CMusic* _music;

public:
	virtual void updateEnemies(float dt);
	void setMusic(CMusic* music);
	CEnemyManager(CMusic* music);
};

