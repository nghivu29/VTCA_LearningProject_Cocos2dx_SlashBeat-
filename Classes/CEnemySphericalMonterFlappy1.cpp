#include "CEnemySphericalMonterFlappy1.h"
#include "common.h"

USING_NS_CC;

CEnemySphericalMonterFlappy1 * CEnemySphericalMonterFlappy1::createMonster()
{
	return CEnemySphericalMonterFlappy1::create();
}

bool CEnemySphericalMonterFlappy1::init()
{
	if (!CEnemySphericalMonter::init())
		return false;
	
	setScale(0.1f);
	this->setFlipX(true);

	return true;
}

bool CEnemySphericalMonterFlappy1::initHit()
{
	_animatesHit = helpCreateAnimates(SPHERICALMONTER_FLAPPY1_HIT_FRAME_NAME_FORMAT, SPHERICALMONTER_FLAPPY1_HIT_NUMBER, SPHERICALMONTER_FLAPPY1_HIT_FRAME_NUMBER);
	return true;
}

bool CEnemySphericalMonterFlappy1::initIdle1()
{
	_animatesIdle1 = helpCreateAnimates(SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NAME_FORMAT, SPHERICALMONTER_FLAPPY1_IDLE_NUMBER, SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemySphericalMonterFlappy1::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(SPHERICALMONTER_FLAPPY1_PATH))
		return true;
	cache->addSpriteFramesWithFile(SPHERICALMONTER_FLAPPY1_PATH);
	return true;
}
