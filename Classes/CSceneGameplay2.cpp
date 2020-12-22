#include "CSceneGameplay2.h"

USING_NS_CC;

CSceneGameplay2 * CSceneGameplay2::createScene()
{
	return CSceneGameplay2::create();
}

bool CSceneGameplay2::init()
{
	_x = 8;
	_bgSpeed = 10.0f;
	_heroRunSpeed = 0.5f;
	_musicID = 1;

	if (!CSceneGameplay::init())
		return false;

	setTag(2);
	_enemyManager->_fireLifeTime = 10.0f;

	// effect
	auto effect = ParticleRain::create();
	effect->setAngle(-100);
	effect->setGravity(Vec2(-200, -100));
	effect->setSpeed(500);
	effect->setTotalParticles(200);
	effect->setStartSize(10);
	effect->setEndSize(10);
	//effect->setPosVar(Vec2(visibleSize.width, visibleSize.height));
	//effect->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
	//effect->setPosition(origin + Vec2(visibleSize.width, visibleSize.height));
	addChild(effect, 10);

	return true;
}
