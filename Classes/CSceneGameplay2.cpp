#include "CSceneGameplay2.h"

USING_NS_CC;

CSceneGameplay2 * CSceneGameplay2::createScene()
{
	return CSceneGameplay2::create();
}

bool CSceneGameplay2::init()
{
	_x = 8;
	_bgSpeed = 0;
	_heroRunSpeed = 0.5f;
	_musicID = 1;

	if (!CSceneGameplay::init())
		return false;

	setTag(2);
	_enemyManager->_fireLifeTime = 10.0f;

	return true;
}
