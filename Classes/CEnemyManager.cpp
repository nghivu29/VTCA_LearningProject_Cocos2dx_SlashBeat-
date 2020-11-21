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
		enemy->setPosition(1000, 150);
		Director::getInstance()->getRunningScene()->addChild(enemy, -1);
		enemy->idle1();
		enemy->runAction(MoveTo::create(_music->getFramePerBeat()/60, Vec2(200, 150)));
	}
	lastMeasure = _music->getMeasureCurrent();
}

void CEnemyManager::setMusic(CMusic * music)
{
	_music = music;
}

CEnemyManager::CEnemyManager(CMusic * music)
{
	setMusic(music);
}
