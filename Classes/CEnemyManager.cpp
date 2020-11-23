#include "CEnemyManager.h"
#include "CEnemySphericalMonter.h"

USING_NS_CC;

int lastMeasure = -1;

void CEnemyManager::updateEnemies(float dt)
{
	bool hasNode = _music->hasNote();
	if (hasNode && _music->getMeasureCurrent() != lastMeasure)
	{	
		auto enemy = CEnemySphericalMonter::createMonster();
		enemy->setPosition(2000, _target->getPosition().y);
		enemy->setMusic(_music);
		enemy->setTarget(_target);
		Director::getInstance()->getRunningScene()->addChild(enemy, -1);
		enemy->idle1();
		if (_target)
		{
			enemy->runAction
			(
				Sequence::create
				(
					MoveTo::create(_music->getFramePerBeat() / 60, _target->getPosition()-Vec2(0, 20)),
					MoveBy::create(1.0f, Vec2(-800, 0)),
					nullptr
				)
			);
		}
	}
	lastMeasure = _music->getMeasureCurrent();
}

void CEnemyManager::setMusic(CMusic * music)
{
	_music = music;
}

void CEnemyManager::setTarget(CActor * target)
{
	_target = target;
}

CEnemyManager::CEnemyManager(CMusic * music, CActor* target)
{
	setMusic(music);
	setTarget(target);
}
