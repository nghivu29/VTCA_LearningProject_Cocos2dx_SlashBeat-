 #include "CEnemyManager.h"
#include "CEnemySphericalMonter.h"
#include "CEnemyRock.h"
#include "common.h"

USING_NS_CC;

int lastMeasure = -1;

void CEnemyManager::updateEnemies(float dt)
{
	int hasNode = _music->hasNote();
	if (hasNode > 0 && hasNode < 10 && _music->getMeasureCurrent() != lastMeasure)
	{	
		auto enemy = CEnemyManager::createMonster(hasNode, _target);

		enemy->setTarget(_target);
		enemy->setMusic(_music);
		//enemy->setPosition(2000, _target->getPosition().y);
		Director::getInstance()->getRunningScene()->addChild(enemy, -1);
		enemy->idle1();
		if (_target)
		{
			enemy->runAction
			(
				Sequence::create
				(
					MoveTo::create(_music->getFramePerBeat() / 60, Vec2(_target->getPosition().x-20, enemy->getPosition().y)),
					MoveBy::create(1.0f, Vec2(-800, 0)),
					nullptr
				)
			);
		}
	}
	lastMeasure = _music->getMeasureCurrent();
}



CEnemy * CEnemyManager::createMonster(int enemyName, CActor* target)
{
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	CEnemy* enemy;

	switch (enemyName)
	{
	case EEnemy::ROCK_MONSTER_1:
		enemy = CEnemyRock::createMonster();
		enemy->setName(EEnemy::ROCK_MONSTER_1);
		enemy->setPosition(1500, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::ROCK_MONSTER_2:
		enemy = CEnemyRock::createMonster();
		enemy->setName(EEnemy::ROCK_MONSTER_2);
		enemy->setPosition(1500, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_1:
		enemy = CEnemySphericalMonter::createMonster();
		enemy->setName(EEnemy::ROCK_MONSTER_1);
		enemy->setPosition(1500, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_2:
		enemy = CEnemySphericalMonter::createMonster();
		enemy->setName(EEnemy::ROCK_MONSTER_2);
		enemy->setPosition(1500, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	}
	return enemy;
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
