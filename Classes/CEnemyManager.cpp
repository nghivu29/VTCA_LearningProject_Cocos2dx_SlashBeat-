 #include "CEnemyManager.h"
#include "CEnemySphericalMonster.h"
#include "CEnemyRock.h"
#include "CEnemySphericalMonsterFlappy1.h"
#include "CEnemySkull.h"
#include "CEnemyBoss.h"
#include "CEnemyFromBoss0.h"
#include "common.h"

USING_NS_CC;


void CEnemyManager::updateEnemies(float dt)
{
	CEnemy* enemy = nullptr;


	int beat = (int)_music->_songPositionInBeats;
	if (beat != h_mostRecentBeat)
	{
		enemy = createMonster(_music->whichNote(), _target);
	}
	h_mostRecentBeat = beat;


	if (enemy)
	{
		enemy->idle1();
		enemy->setTarget(_target);
		enemy->setMusic(_music);
		auto posEnd = Vec2(_target->getPosition().x - _distanceEnemyRun, enemy->getPosition().y) - Vec2(_detalRange, 0);
		auto posTarget  = Vec2(_target->getPosition().x, enemy->getPosition().y) + Vec2(_detalRange, 0);

		if (enemy->getName() == EEnemy::BOSS0)
		{
			_boss = enemy;
			bossScript1(enemy);
			Director::getInstance()->getRunningScene()->addChild(enemy, 10);
		}
		else if (enemy->getName() > EEnemy::BOSS0)
		{
			enemy->setPosition(_boss->getPosition());
			enemy->runAction
			(
				Sequence::create
				(
					MoveTo::create(_timeEnemyRun, _target->getPosition()),
					CallFunc::create(CC_CALLBACK_0(CEnemyManager::logSongPosition, this)),
					MoveTo::create(_timeEnemyRun, Vec2(posEnd.x, helpChaseTarget(_target->getPosition().y))),
					nullptr
				)
			);
			Director::getInstance()->getRunningScene()->addChild(enemy, 10);
		}
		else
		{
			enemy->runAction
			(
				Sequence::create
				(
					MoveTo::create(_timeEnemyRun, posTarget),
					CallFunc::create(CC_CALLBACK_0(CEnemyManager::logSongPosition, this)),
					MoveTo::create(_timeEnemyRun, posEnd),
					nullptr
				)
			);
		Director::getInstance()->getRunningScene()->addChild(enemy, 1);
		}
	}
}



CEnemy * CEnemyManager::createMonster(int enemyName, CActor* target)
{
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	CEnemy* enemy = nullptr;

	auto posStart = _target->getPosition().x + _distanceEnemyRun;

	switch (enemyName)
	{
	case EEnemy::ROCK_MONSTER_1:
		enemy = CEnemyRock::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::ROCK_MONSTER_2:
		enemy = CEnemyRock::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_1:
		enemy = CEnemySphericalMonster::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_2:
		enemy = CEnemySphericalMonster::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_FLAPPY_1:
		enemy = CEnemySphericalMonsterFlappy1::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SPHERICAL_MONSTER_FLAPPY_2:
		enemy = CEnemySphericalMonsterFlappy1::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::SKULL_MONSTER_1:
		enemy = CEnemySkull::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND1_POS_Y_RATIO);
		break;
	case EEnemy::SKULL_MONSTER_2:
		enemy = CEnemySkull::createMonster();
		enemy->setPosition(posStart, origin.y + visibleSize.height* GROUND2_POS_Y_RATIO);
		break;
	case EEnemy::BOSS0:
		enemy = CEnemyBoss::createBoss();
		enemy->setPosition(posStart, origin.y + visibleSize.height* 0.5f);
		break;
	case EEnemy::ENEMY_FROM_BOSS0:
		if (_boss->getHp() > 0)
		{
			auto a = CEnemyFromBoss0::createSkill();
			a->setOwner(_boss);
			enemy = a;
		}
		break;
	}
	if (enemy)
	{
		enemy->setName((EEnemy)enemyName);
	}
	return enemy;
}

bool CEnemyManager::init()
{
	//cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	_distanceEnemyRun = visibleSize.width;
	_timeEnemyRun = _music->_secPerBeat*x;

	return true;
}

void CEnemyManager::bossScript1(CEnemy* enemy)
{
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto pos = enemy->getPosition();

	enemy->run1();

	enemy->runAction
	(
		Sequence::create
		(
			MoveTo::create(4.0f, Vec2(origin.x + visibleSize.width*0.8, origin.y + visibleSize.height*0.5)),
			DelayTime::create(10.0f),
			MoveTo::create(4.0f, pos),
			DelayTime::create(40.0f),
			MoveTo::create(4.0f, Vec2(origin.x + visibleSize.width*0.8, origin.y + visibleSize.height*0.5)),
			DelayTime::create(20.0f),
			MoveTo::create(4.0f, Vec2(origin.x + visibleSize.width*0.5, origin.y + visibleSize.height*0.5)),
			DelayTime::create(10.0f),
			MoveTo::create(4.0f, Vec2(origin.x + visibleSize.width*0.3, origin.y + visibleSize.height*0.5)),
			nullptr
		)
	);

	
}


void CEnemyManager::setMusic(CMusic * music)
{
	_music = music;
}

void CEnemyManager::setTarget(CActor * target)
{
	_target = target;
}

void CEnemyManager::setDetalRange(float dt)
{
	_detalRange = dt;
}

void CEnemyManager::setX(int x)
{
	this->x = x;
}

float CEnemyManager::getDetalRange()
{
	return _detalRange;
}



CEnemyManager::CEnemyManager(CMusic * music, CActor* target)
{
	setMusic(music);
	setTarget(target);
}

void CEnemyManager::logSongPosition()
{
	log("Enemy: %f", _music->getCurrentTime());
}

float CEnemyManager::helpChaseTarget(float targetPosY)
{
	Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	if (targetPosY > origin.y + visibleSize.height* GROUND1_POS_Y_RATIO+20)
	{
		return origin.y + visibleSize.height* GROUND1_POS_Y_RATIO;
	}
	return origin.y + visibleSize.height* GROUND2_POS_Y_RATIO;
}
