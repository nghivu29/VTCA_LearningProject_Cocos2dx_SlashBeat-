#include "CEnemy.h"
#include "common.h"

USING_NS_CC;

bool CEnemy::init()
{
	if (!CActor::init())
		return false;
	setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	scheduleUpdate();
	return true;
}

bool CEnemy::loadResource()
{
	return true;
}


void CEnemy::update(float dt)
 {


	if (_targetActor->getStatus() == DEAD)
	{
		stopAllActions();
		return;
	}


	float e_x = getPosition().x;
	float e_w = getContentSize().width*getScale();
	float h_x = _targetActor->getPosition().x;
	float h_w = _targetActor->getContentSize().width*_targetActor->getScale();

	auto e = getBoundingBox();
	auto h = _targetActor->getBoundingBox();

	if (getBoundingBox().intersectsRect(_targetActor->getBoundingBox())) 
	{
		if (e_x > h_x- h_w * (1.0f / 3.0f))
		{
			if 
				(
					(_targetActor->getStatus() == EActorStatus::ATTACK1 && _type == EEnemyType::SOFT) || 
					(_targetActor->getStatus() == EActorStatus::ATTACK2 && _type == EEnemyType::HARD)
				) 
			{
				_status = EActorStatus::HIT;
			}
		}
		else if (e_x > h_x - h_w * (2.0f/3.0f))
		{
			_status = EActorStatus::ATTACK1;
		}
		else
		{
			_status = EActorStatus::IDLE1;

		}
	}	
	else
	{
		_status = EActorStatus::IDLE1;
	}


	if (_status != lastStatus)
	{
		switch (_status)
		{
		case HIT:
			hit();
			_targetActor->_score++;
			_targetActor->_combo++;
			break;
		case IDLE1:
			break;
		case ATTACK1:
			_targetActor->hit();
			break;
		default:
			break;
		}
	}
	lastStatus = _status;

	if (getPosition().y > 700 || getPosition().x < -200) {
		this->unscheduleUpdate();
		this->removeFromParent();
		//this->release();
		//this->autorelease();
		return;
	}
}

void CEnemy::hit()
{
	if (_targetActor->_combo >= COMBO1_NUMBER)
	{
		switch (_enemyName)
		{
		case NOPE:
		case SPHERICAL_MONSTER_1:
		case SPHERICAL_MONSTER_2:
		case SPHERICAL_MONSTER_FLAPPY_1:
		case SPHERICAL_MONSTER_FLAPPY_2:
		case BOSS0:
		case ENEMY_FROM_BOSS0:
			_effect = ParticleSystemQuad::create("effect/particle_texture.plist");
			break;
		case ROCK_MONSTER_1:
		case ROCK_MONSTER_2:
		case SKULL_MONSTER_1:
		case SKULL_MONSTER_2:
			_effect = ParticleSystemQuad::create("effect/particle_texture1.plist");
		default:
			break;
		}
		_effect->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
		_effect->setPosition(0, 0);

		if (_targetActor->_combo >= COMBO2_NUMBER) _effect->setScale(1 / this->getScale());
		else _effect->setScale((1/this->getScale()) * 0.4f);
		
		addChild(_effect, 5);
	}
}

void CEnemy::setTarget(CActor * targetActor)
{
	_targetActor = targetActor;
}

void CEnemy::setType(EEnemyType type)
{
	_type = type;
}

void CEnemy::setName(EEnemy name)
{
	_enemyName = name;
}

EEnemy CEnemy::getName()
{
	return _enemyName;
}

EEnemyType CEnemy::getType()
{
	return _type;
}
