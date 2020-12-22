#include "CEnemySphericalMonsterFlappy1.h"
#include "common.h"

USING_NS_CC;

CEnemySphericalMonsterFlappy1 * CEnemySphericalMonsterFlappy1::createMonster()
{
	return CEnemySphericalMonsterFlappy1::create();
}

bool CEnemySphericalMonsterFlappy1::init()
{
	if (!CEnemySphericalMonster::init())
		return false;
	
	setScale(SPHERICAL_MONTER_FLAPPY1_RATIO_H);
	this->setFlipX(true);

	return true;
}

bool CEnemySphericalMonsterFlappy1::initHit()
{
	_animatesHit.pushBack(helpCreateAnimates(SPHERICALMONTER_FLAPPY1_HIT_FRAME_NAME_FORMAT, SPHERICALMONTER_FLAPPY1_HIT_FRAME_NUMBER));
	return true;
}

bool CEnemySphericalMonsterFlappy1::initIdle1()
{
	_animatesIdle1.pushBack(helpCreateAnimates(SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NAME_FORMAT, SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NUMBER, 0.2f));
	return true;
}

bool CEnemySphericalMonsterFlappy1::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(SPHERICALMONTER_FLAPPY1_PATH))
		return true;
	cache->addSpriteFramesWithFile(SPHERICALMONTER_FLAPPY1_PATH);
	return true;
}
