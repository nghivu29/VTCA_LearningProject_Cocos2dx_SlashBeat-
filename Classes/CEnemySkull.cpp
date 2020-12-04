#include "CEnemySkull.h"
#include "common.h"
USING_NS_CC;

CEnemySkull * CEnemySkull::createMonster()
{
	return CEnemySkull::create();
}

bool CEnemySkull::init()
{
	if (!CEnemySphericalMonter::init())
		return false;

	_type = EEnemyType::HARD;
	setScale(0.1f);
	
	return true;
}

bool CEnemySkull::initHit()
{
	_animatesHit = helpCreateAnimates(SKULLMONSTER_HIT_FRAME_NAME_FORMAT, SKULLMONSTER_HIT_NUMBER, SKULLMONSTER_HIT_FRAME_NUMBER);
	return true;
}

bool CEnemySkull::initIdle1()
{
	_animatesIdle1 = helpCreateAnimates(SKULLMONSTER_IDLE_FRAME_NAME_FORMAT, SKULLMONSTER_IDLE_NUMBER, SKULLMONSTER_IDLE_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemySkull::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(SKULLMONSTER_PATH))
		return true;
	cache->addSpriteFramesWithFile(SKULLMONSTER_PATH);
	return true;
}