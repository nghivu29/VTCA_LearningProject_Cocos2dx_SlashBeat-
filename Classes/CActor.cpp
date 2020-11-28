#include "CActor.h"

USING_NS_CC;

bool CActor::init()
{
	if (!Sprite::init())
		return false;
	if (!(loadResource() && CAnimateActor::initAnimate()))
		return false;
	return true;
}

bool CActor::loadResource()
{
	return true;
}

void CActor::dead()
{
	_status = DEAD;
}

void CActor::hit()
{
	_status = HIT;
}

void CActor::idle1()
{
	_status = IDLE1;
}

void CActor::idle2()
{
	_status = IDLE2;
}

void CActor::run1()
{
	_status = RUN1;
}

void CActor::run2()
{
	_status = RUN2;
}

void CActor::stun()
{
	_status = STUN;
}

void CActor::attack1()
{
	_status = ATTACK1;
}

void CActor::attack2()
{
	_status = ATTACK2;
}

void CActor::jumpUP()
{
}

void CActor::jumpDown()
{
}

void CActor::walk1()
{
	_status = WALK1;
}

void CActor::walk2()
{
	_status = WALK2;
}

void CActor::setHp(int hp)
{
	_hp = hp;
}

void CActor::setStatus(EActorStatus status)
{
	_status = status;
}

int CActor::getHp()
{
	return _hp;
}

EActorStatus CActor::getStatus()
{
	return _status;
}


