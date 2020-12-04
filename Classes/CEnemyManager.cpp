 #include "CEnemyManager.h"
#include "CEnemySphericalMonter.h"
#include "CEnemyRock.h"
#include "CEnemySphericalMonterFlappy1.h"
#include "CEnemySkull.h"
#include "common.h"

USING_NS_CC;


void CEnemyManager::updateEnemies(float dt)
{
	int hasNode = _music->hasNote();
	if (hasNode > 0  && _music->getMeasureCurrent() != lastMeasure)
	{	
		auto enemy = createMonster(hasNode, _target);

		enemy->setTarget(_target);
		enemy->setMusic(_music);
		//enemy->setPosition(2000, _target->getPosition().y);
		Director::getInstance()->getRunningScene()->addChild(enemy, -1);
		enemy->idle1();
		if (_target)
		{
			auto detal = 0; // -_target->getContentSize().width*_target->getScale()*0.2 : 0;
			auto time = _music->getFramePerBeat() / (60 / (_music->getBeatDelay() - 1));
			enemy->runAction
			(
				Sequence::create
				(
					MoveTo::create(time, Vec2(_target->getPosition().x + detal, enemy->getPosition().y)),
					MoveBy::create(time, Vec2(-_music->getDistance(), 0)),
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
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::ROCK_MONSTER_2:
		enemy = CEnemyRock::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_1:
		enemy = CEnemySphericalMonter::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_2:
		enemy = CEnemySphericalMonter::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_FLAPPY_1:
		enemy = CEnemySphericalMonterFlappy1::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_FLAPPY_2:
		enemy = CEnemySphericalMonterFlappy1::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SKULL_MONSTER_1:
		enemy = CEnemySkull::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SKULL_MONSTER_2:
		enemy = CEnemySkull::createMonster();
		enemy->setPosition(_music->getDistance(), origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
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
