#include "CEnemySphericalMonster.h"
#include "common.h"

USING_NS_CC;

CEnemySphericalMonster * CEnemySphericalMonster::createMonster()
{
	return CEnemySphericalMonster::create();
}

bool CEnemySphericalMonster::init()
{
	if (! (CEnemy::init() && CAnimateActor::initAnimate()))
		return false;
	setScale(SPHERICAL_MONTER_RATIO_H);
	_type = EEnemyType::SOFT;
	SpriteFrameCache::getInstance()->destroyInstance();
	return true;
}

void CEnemySphericalMonster::dead()
{
}

void CEnemySphericalMonster::hit()
{
	stopAllActions();
	CEnemy::hit();
	runAction(MoveBy::create(0.8f, Vec2(1000, 1000)));
	runAction(Sequence::create(_animatesHit.at(0), FadeOut::create(0.5f), nullptr));
}

void CEnemySphericalMonster::idle1()
{
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle1.at(0)));
}

void CEnemySphericalMonster::idle2()
{
}

void CEnemySphericalMonster::run1()
{
}

void CEnemySphericalMonster::run2()
{
}

void CEnemySphericalMonster::stun()
{
}

void CEnemySphericalMonster::attack1()
{
}

void CEnemySphericalMonster::attack2()
{
}

void CEnemySphericalMonster::walk1()
{
}

void CEnemySphericalMonster::walk2()
{
}

bool CEnemySphericalMonster::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(SPHERICALMONTER_PATH))
		return true;
	cache->addSpriteFramesWithFile(SPHERICALMONTER_PATH);
	return true;
}

bool CEnemySphericalMonster::initDead()
{
	return false;
}

bool CEnemySphericalMonster::initHit()
{
	_animatesHit.pushBack(helpCreateAnimates(SPHERICALMONTER_HIT_FRAME_NAME_FORMAT, SPHERICALMONTER_HIT_FRAME_NUMBER));
	return true;
}

bool CEnemySphericalMonster::initIdle1()
{
	_animatesIdle1.pushBack(helpCreateAnimates(SPHERICALMONTER_IDLE_FRAME_NAME_FORMAT, SPHERICALMONTER_IDLE_FRAME_NUMBER, 0.2f));
	return true;
}

bool CEnemySphericalMonster::initIdle2()
{
	return false;
}

bool CEnemySphericalMonster::initRun1()
{
	return false;
}

bool CEnemySphericalMonster::initRun2()
{
	return false;
}

bool CEnemySphericalMonster::initStun()
{
	return false;
}

bool CEnemySphericalMonster::initAttack1()
{
	return false;
}

bool CEnemySphericalMonster::initAttack2()
{
	return false;
}

bool CEnemySphericalMonster::initWalk1()
{
	return false;
}

bool CEnemySphericalMonster::initWalk2()
{
	return false;
}
