#include "CEnemyRock.h"
#include "common.h"

USING_NS_CC;

CEnemyRock * CEnemyRock::createMonster()
{
	return CEnemyRock::create();
}

bool CEnemyRock::init()
{
	if (!(CEnemy::init()))
		return false;
	setScale(ROCK_MONSTER_RATIO_H);
	setTexture(ROCKMONSTER_PATH);
	_type = EEnemyType::HARD;
	return true;
}

void CEnemyRock::hit()
{
	stopAllActions();
	CEnemy::hit();
	runAction(MoveBy::create(1.0f, Vec2(1000, 710)));
	runAction(FadeOut::create(0.8f));
}

