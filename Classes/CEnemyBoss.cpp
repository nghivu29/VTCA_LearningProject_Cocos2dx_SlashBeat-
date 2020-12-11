#include "CEnemyBoss.h"
#include "common.h"

USING_NS_CC;

CEnemyBoss * CEnemyBoss::createBoss()
{
	return CEnemyBoss::create();
}

bool CEnemyBoss::init()
{
	if (!CEnemy::init())
	{
		return false;
	}

	return true;
}

void CEnemyBoss::dead()
{
}

void CEnemyBoss::hit()
{
}

void CEnemyBoss::idle1()
{
	CEnemy::idle1();
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle1[0]));
}

void CEnemyBoss::run1()
{
	CEnemy::run1();
	stopAllActions();
	runAction(RepeatForever::create(_animatesRun1[0]));
}

void CEnemyBoss::attack1()
{

}

void CEnemyBoss::attack2()
{
	//_animatesAttack2 = helpCreateAnimates();
}

bool CEnemyBoss::initDead()
{
	_animatesDead = helpCreateAnimates(BOSS_DEAD_FRAME_NAME_FORMAT, BOSS_DEAD_NUMBER, BOSS_DEAD_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemyBoss::initHit()
{
	_animatesHit = helpCreateAnimates(BOSS_HIT_FRAME_NAME_FORMAT, BOSS_HIT_NUMBER, BOSS_HIT_FRAME_NUMBER, 0.1f);
	return true;
}

bool CEnemyBoss::initIdle1()
{
	_animatesIdle1 = helpCreateAnimates(BOSS_IDLE_FRAME_NAME_FORMAT, BOSS_IDLE_NUMBER, BOSS_IDLE_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemyBoss::initRun1()
{
	_animatesRun1 = helpCreateAnimates(BOSS_RUN_FRAME_NAME_FORMAT, BOSS_RUN_NUMBER, BOSS_RUN_FRAME_NUMBER, 0.2f);
	return true;
}

bool CEnemyBoss::initAttack1()
{
	return false;
}

bool CEnemyBoss::initAttack2()
{
	return false;
}

bool CEnemyBoss::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(BOSS0_PATH))
		return true;
	cache->addSpriteFramesWithFile(BOSS0_PATH);
	return true;
}
