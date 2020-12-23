#include "CFire.h"
#include "common.h"

USING_NS_CC;

CFire * CFire::createFire()
{
	return CFire::create();
}

CFire * CFire::createFire(float lifeTime)
{
	auto fire = CFire::create();
	fire->_lifeTime = lifeTime;
	return fire;

}

bool CFire::init()
{
	if (!CEnemy::init())
		return false;

	_enemyName = EEnemy::FIRE_1;
	_lifeTime = 0.5f;
	 
	_effect = ParticleFire::create();
	_effect->setPosition(origin.x + visible.width / 2, origin.y);
	_effect->setDuration(ParticleSystem::DURATION_INFINITY);
	_effect->setPosVar(Vec2(visible.width / 2, 0));
	
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	{
		_effect->setTotalParticles(1500);
		_effect->setEmissionRate(650);
		_effect->setLife(2.7);
	}
	else
	{
		_effect->setTotalParticles(500);
		_effect->setEmissionRate(200);
		_effect->setLife(1.5);
	}


	addChild(_effect);
	//burn();

	_dragon = Sprite::create();
	_dragon->setPosition(-1000, 150);
	_dragon->setScale(DRAGON_RATIO);
	addChild(_dragon);
	run1();

	return true;
}

void CFire::update(float dt)
{
	if (_targetActor->getHp() > 0)
	{
		if ((_enemyName == EEnemy::FIRE_2 && _targetActor->getPosition().y > origin.x + visible.height*GROUND1_POS_Y_RATIO + 20) || 
			(_enemyName == EEnemy::FIRE_1 && _targetActor->getPosition().y < origin.x + visible.height*GROUND1_POS_Y_RATIO + 20))
		{
			count++;
			if (count >= 30)
			{
				_targetActor->hit();
				count = 0;
			}
		}
	}


}

void CFire::run1()
{
	CEnemy::run1();
	_dragon->runAction(_animatesRun1.at(0));
	_dragon->runAction(MoveBy::create(6, Vec2(4000, 0)));
}

void CFire::attack1()
{
	scheduleUpdate();
	runAction(Sequence::create(FadeIn::create(0.5f), DelayTime::create(_lifeTime - 0.5f), RemoveSelf::create(), nullptr));
}

bool CFire::initRun1()
{
	_animatesRun1.pushBack(helpCreateAnimates(DRAGON_RUN1_FRAME_NAME_FORMAT, 1, DRAGON_RUN1_FRAME_NUMBER, 1.0f));
	_animatesRun1.at(0)->getAnimation()->setLoops(5);
	return true;
}

bool CFire::loadResource()
{
	auto cache = SpriteFrameCache::getInstance();
	if (!cache->isSpriteFramesWithFileLoaded(DRAGON_PATH))
	{
		cache->addSpriteFramesWithFile(DRAGON_PATH);
	}
	return true;
}
