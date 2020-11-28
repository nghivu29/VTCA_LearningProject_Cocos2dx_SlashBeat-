#include "CEnemySphericalMonter.h"
#include "common.h"

USING_NS_CC;

CEnemySphericalMonter * CEnemySphericalMonter::createMonster()
{
	return CEnemySphericalMonter::create();
}

bool CEnemySphericalMonter::init()
{
	if (! (CEnemy::init() && CAnimateActor::initAnimate()))
		return false;
	setScale(SPHERICAL_MONTER_RATIO_H);
	_type = EEnemyType::SOFT;
	SpriteFrameCache::getInstance()->destroyInstance();
	return true;
}

void CEnemySphericalMonter::dead()
{
}

void CEnemySphericalMonter::hit()
{
	stopAllActions();
	runAction(MoveBy::create(0.5, Vec2(1000, 1000)));
	runAction(Sequence::create(_animatesHit[0], FadeOut::create(0.5f), nullptr));
}

void CEnemySphericalMonter::idle1()
{
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle1[0]));
}

void CEnemySphericalMonter::idle2()
{
}

void CEnemySphericalMonter::run1()
{
}

void CEnemySphericalMonter::run2()
{
}

void CEnemySphericalMonter::stun()
{
}

void CEnemySphericalMonter::attack1()
{
}

void CEnemySphericalMonter::attack2()
{
}

void CEnemySphericalMonter::walk1()
{
}

void CEnemySphericalMonter::walk2()
{
}

bool CEnemySphericalMonter::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(SPHERICALMONTER_PATH))
		return true;
	cache->addSpriteFramesWithFile(SPHERICALMONTER_PATH);
	return true;
}

bool CEnemySphericalMonter::initDead()
{
	return false;
}

bool CEnemySphericalMonter::initHit()
{
	_animatesHit = helpCreateAnimates(SPHERICALMONTER_HIT_FRAME_NAME_FORMAT, SPHERICALMONTER_HIT_NUMBER, SPHERICALMONTER_HIT_FRAME_NUMBER);
	return true;
}

bool CEnemySphericalMonter::initIdle1()
{
	_animatesIdle1 = helpCreateAnimates(SPHERICALMONTER_IDLE_FRAME_NAME_FORMAT, SPHERICALMONTER_IDLE_NUMBER, SPHERICALMONTER_IDLE_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemySphericalMonter::initIdle2()
{
	return false;
}

bool CEnemySphericalMonter::initRun1()
{
	return false;
}

bool CEnemySphericalMonter::initRun2()
{
	return false;
}

bool CEnemySphericalMonter::initStun()
{
	return false;
}

bool CEnemySphericalMonter::initAttack1()
{
	return false;
}

bool CEnemySphericalMonter::initAttack2()
{
	return false;
}

bool CEnemySphericalMonter::initWalk1()
{
	return false;
}

bool CEnemySphericalMonter::initWalk2()
{
	return false;
}
