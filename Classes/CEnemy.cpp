#include "CEnemy.h"

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
	float e_x = getPosition().x;
	float e_w = getContentSize().width;
	float h_x = _targetActor->getPosition().x;
	float h_w = _targetActor->getContentSize().width;

	if (getBoundingBox().intersectsRect(_targetActor->getBoundingBox())) 
	{
		if (e_x > h_x-h_x/2)
		{
			if (_targetActor->getStatus() == EActorStatus::ATTACK1 || _targetActor->getStatus() == EActorStatus::ATTACK2) 
			{
				_status = EActorStatus::HIT;
			}
		}
		else
		{
			_status = EActorStatus::ATTACK1;
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
}

void CEnemy::setTarget(CActor * targetActor)
{
	_targetActor = targetActor;
}
