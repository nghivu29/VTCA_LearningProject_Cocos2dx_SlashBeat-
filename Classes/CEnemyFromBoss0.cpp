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
	setScale(SKILL1_BOSS_RATIO_H);
	setTexture("res/actor/enemy/boss/skill0.png");
	_type = EEnemyType::SOFT;
	return true;
}

void CEnemyFromBoss0::hit()
{
	stopAllActions();
	runAction(MoveTo::create(0.3f, _owner->getPosition()));
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

void CEnemyFromBoss0::attack1()
{
	auto size = _targetActor->getContentSize();
	auto scale = _targetActor->getScale();
	Director::getInstance()->getRunningScene()->addChild(this, 10);
	runAction
	(
		Sequence::create
		(
			MoveTo::create(0.5f, _targetActor->getPosition() + Vec2(-size.width*scale, 0)),
			FadeOut::create(0.2f),
			RemoveSelf::create(),
			nullptr
		)
	);
}

void CEnemyFromBoss0::hitBoss()
{
	_owner->setHp(_owner->getHp() - 1);
}

void CEnemyFromBoss0::setOwner(CActor * owner)
{
	_owner = owner;
	Vec2 random = Vec2(RandomHelper::random_int(-100, 50), RandomHelper::random_int(-70, 70));
	setPosition(owner->getPosition()+Vec2(-100, 200) + random);
}


