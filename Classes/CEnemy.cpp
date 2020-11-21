#include "CEnemy.h"

USING_NS_CC;

bool CEnemy::init()
{
	if (!CActor::init())
		return false;
	scheduleUpdate();
	return true;
}

bool CEnemy::loadResource()
{
	return true;
}


void CEnemy::update(float dt)
 {
	if (getPosition().x <= 250)
	{
		_status = EActorStatus::HIT;
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
		default:
			break;
		}
	}
	lastStatus = _status;
}
