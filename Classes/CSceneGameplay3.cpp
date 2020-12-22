#include "CSceneGameplay3.h"

USING_NS_CC;

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


	auto effect = ParticleSun::create();
	effect->setGravity(Vec2(-200, 200));
	effect->setTotalParticles(100);
	effect->setStartSize(50);
	effect->setEndSize(50);
	effect->setPosVar(Vec2(visibleSize.width, visibleSize.height));
	//effect->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	effect->setPosition(origin);
	addChild(effect, -1);

	return true;
}

