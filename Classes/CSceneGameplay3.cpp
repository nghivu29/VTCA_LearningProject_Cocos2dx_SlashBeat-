#include "CSceneGameplay3.h"

CSceneGameplay3 * CSceneGameplay3::createScene()
{
	return CSceneGameplay3::create();
}

bool CSceneGameplay3::init()
{
	_x = 8;
	_bgSpeed = 17.0f;
	_heroRunSpeed = 0.5f;
	_musicID = 3;

	if (!CSceneGameplay::init())
		return false;

	setTag(3);
	_enemyManager->_fireLifeTime = 5.0f;

	return true;
}

