#include "CSceneGameplay2.h"

USING_NS_CC;

CSceneGameplay2 * CSceneGameplay2::createScene()
{
	return CSceneGameplay2::create();
}

bool CSceneGameplay2::init()
{
	_x = 4;
	_bgSpeed = 20;
	_heroRunSpeed = 0;
	_musicID = 2;

	return CSceneGameplay::init();
}
