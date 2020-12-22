#include "CEnemyBoss.h"
#include "CEnemyFromBoss0.h"
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
	_enemyName = EEnemy::BOSS0;
	setFlipX(true);
	setScale(BOSS_RATIO_H);
	setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	_hp = 20;

	return true;
}

void CEnemyBoss::dead()
{
	CEnemy::dead();
	stopAllActions();
	runAction(RepeatForever::create(_animatesDead.at(0)));
	runAction(Sequence::create(DelayTime::create(2.0), FadeOut::create(3), nullptr));
}

void CEnemyBoss::hit()
{
}

void CEnemyBoss::idle1()
{
	CEnemy::idle1();
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle1.at(0)));
}

void CEnemyBoss::run1()
{
	CEnemy::run1();
	stopAllActions();
	runAction(RepeatForever::create(_animatesRun1.at(0)));
}

void CEnemyBoss::attack1()
{
	auto a = CEnemyFromBoss0::createSkill();
	a->setOwner(this);
	a->setTarget(_targetActor);
	a->attack1();
}

void CEnemyBoss::attack2()
{
	CEnemy::attack2();
	stopAllActions();
	runAction( Sequence::create
	(
		_animatesAttack2.at(0),
		_animatesAttack2.at(1),
		_animatesAttack2.at(2),
		nullptr
	));
}

bool CEnemyBoss::initDead()
{
	_animatesDead.pushBack(helpCreateAnimates(BOSS_DEAD_FRAME_NAME_FORMAT, BOSS_DEAD_FRAME_NUMBER, 0.25f));
	return true;
}

bool CEnemyBoss::initHit()
{
	_animatesHit.pushBack(helpCreateAnimates(BOSS_HIT_FRAME_NAME_FORMAT, BOSS_HIT_FRAME_NUMBER, 0.1f));
	return true;
}

bool CEnemyBoss::initIdle1()
{
	_animatesIdle1.pushBack(helpCreateAnimates(BOSS_IDLE_FRAME_NAME_FORMAT, BOSS_IDLE_FRAME_NUMBER, 0.2f));
	return true;
}

bool CEnemyBoss::initRun1()
{
	_animatesRun1.pushBack(helpCreateAnimates(BOSS_RUN_FRAME_NAME_FORMAT, BOSS_RUN_FRAME_NUMBER, 0.2f));
	return true;
}

bool CEnemyBoss::initAttack1()
{
	return false;
}

bool CEnemyBoss::initAttack2()
{
	_animatesAttack2.pushBack(helpCreateAnimates(BOSS_ATTACK2_FRAME_NAME_FORMAT, 0, 4, 0.2f));
	_animatesAttack2.pushBack(helpCreateAnimates(BOSS_ATTACK2_FRAME_NAME_FORMAT, 5, 13, 0.2f));
	_animatesAttack2.pushBack(helpCreateAnimates(BOSS_ATTACK2_FRAME_NAME_FORMAT, 14, 30, 0.2f));
	_animatesAttack2.at(1)->getAnimation()->setLoops(10);
	return true;
}

bool CEnemyBoss::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(BOSS0_PATH))
		return true;
	cache->addSpriteFramesWithFile(BOSS0_PATH);
	return true;
}

void CEnemyBoss::update(float dt)
{
	CEnemy::update(dt);
	if (_hp <= 0)
	{
		dead();
		unscheduleUpdate();
	}

	/*if (getPosition().x < _targetActor->getPosition().x)
	{*/
		if (_targetActor->_accumulation1 <= 0 && _targetActor->getStatus() != DEAD)
		{
			attack1();
			_targetActor->_accumulation1 = 2;

		}
	//}
}


