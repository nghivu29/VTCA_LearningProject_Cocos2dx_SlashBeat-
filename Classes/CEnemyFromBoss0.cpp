#include "CEnemyFromBoss0.h"

#include "common.h"

USING_NS_CC;

CEnemyFromBoss0 * CEnemyFromBoss0::createSkill()
{
	return CEnemyFromBoss0::create();
}

bool CEnemyFromBoss0::init()
{
	if (!(CEnemy::init()))
		return false;
	setScale(0.2f);
	setTexture("res/actor/enemy/boss/skill0.png");
	_type = EEnemyType::SOFT;
	return true;
}

void CEnemyFromBoss0::hit()
{
	stopAllActions();
	runAction(MoveTo::create(0.3f, _owner->getPosition()-Vec2(50, 70)));
	runAction(Sequence::create
	(
		FadeOut::create(0.8f),
		FadeOut::create(1),
		nullptr
	));
	if (_owner->getHp() > 0)
	{
		_owner->runAction
		(
			Sequence::create
			(
				DelayTime::create(0.3f),
				_owner->_animatesHit.at(0), 
				CallFunc::create(CC_CALLBACK_0(CEnemyFromBoss0::hitBoss, this)),
				nullptr
			)
		);
	}
}

void CEnemyFromBoss0::hitBoss()
{
	_owner->setHp(_owner->getHp() - 1);
}

void CEnemyFromBoss0::setOwner(CActor * owner)
{
	_owner = owner;
}


