#include "CHeroKnight.h"
#include "proj.win32/resource.h"
USING_NS_CC;

CHeroKnight * CHeroKnight::createKnight()
{
	return CHeroKnight::create();
}

bool CHeroKnight::init()
{
	if (!(CHero::init() && CAnimateActor::initAnimate()))
	{
		return false;
	}
	setScale(0.3f);
	return true;
}

void CHeroKnight::dead()
{
}

void CHeroKnight::hit()
{
	stopAllActions();
	runAction(_animatesHit[0]);
}

void CHeroKnight::idle1()
{
}

void CHeroKnight::idle2()
{
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle2[0]));
}

void CHeroKnight::run1()
{
	
}

void CHeroKnight::run2()
{
	stopAllActions();
	runAction(RepeatForever::create(_animatesRun2[0]));
}

void CHeroKnight::stun()
{
}

void CHeroKnight::attack1()
{
	stopAllActions();
	runAction(_animatesAttack1[0]);
}

void CHeroKnight::attack2()
{
	stopAllActions();
	runAction(_animatesAttack2[0]);
}

void CHeroKnight::walk1()
{
}

void CHeroKnight::walk2()
{
}

bool CHeroKnight::initDead()
{
	return false;
}

bool CHeroKnight::initHit()
{
	_animatesHit = helpCreateAnimates(KNIGHT_HIT_PATH_FORMAT, KNIGHT_HIT_0_FRAME_NAME_FORMAT, KNIGHT_HIT_NUMBER, KNIGHT_HIT_FRAME_NUMBER);
	return true;
}

bool CHeroKnight::initIdle1()
{
	return false;
}

bool CHeroKnight::initIdle2()
{
	_animatesIdle2 = helpCreateAnimates(KNIGHT_IDLE2_PATH_FORMAT, KNIGHT_IDLE2_0_FRAME_NAME_FORMAT, KNIGHT_IDLE2_NUMBER, KNIGHT_IDLE2_FRAME_NUMBER);
	return true;
}

bool CHeroKnight::initRun1()
{
	return false;
}

bool CHeroKnight::initRun2()
{
	return false;
}

bool CHeroKnight::initStun()
{
	_animatesRun2 = helpCreateAnimates(KNIGHT_RUN2_PATH_FORMAT, KNIGHT_RUN2_0_FRAME_NAME_FORMAT, KNIGHT_RUN2_NUMBER, KNIGHT_RUN2_FRAME_NUMBER);
	return true;
}

bool CHeroKnight::initAttack1()
{
	_animatesAttack1 = helpCreateAnimates(KNIGHT_ATTACK1_PATH_FORMAT, KNIGHT_ATTACK1_0_FRAME_NAME_FORMAT, KNIGHT_ATTACK1_NUMBER, KNIGHT_ATTACK1_FRAME_NUMBER);
	return true;
}

bool CHeroKnight::initAttack2()
{
	_animatesAttack2 = helpCreateAnimates(KNIGHT_ATTACK2_PATH_FORMAT, KNIGHT_ATTACK2_0_FRAME_NAME_FORMAT, KNIGHT_ATTACK2_NUMBER, KNIGHT_ATTACK2_FRAME_NUMBER);
	return true;
}

bool CHeroKnight::initWalk1()
{
	return false;
}

bool CHeroKnight::initWalk2()
{
	return false;
}

bool CHeroKnight::loadResource()
{
	// load resource animation idle2
	CAnimateActor::helpLoadResourceAimates(KNIGHT_IDLE2_PATH_FORMAT, KNIGHT_IDLE2_NUMBER);
	
	// load resource animation run2
	CAnimateActor::helpLoadResourceAimates(KNIGHT_RUN2_PATH_FORMAT, KNIGHT_RUN2_NUMBER);

	// load resource animation hit
	CAnimateActor::helpLoadResourceAimates(KNIGHT_HIT_PATH_FORMAT, KNIGHT_HIT_NUMBER);

	// load resource animation attack1
	CAnimateActor::helpLoadResourceAimates(KNIGHT_ATTACK1_PATH_FORMAT, KNIGHT_ATTACK1_NUMBER);

	// load resource animation attack1
	CAnimateActor::helpLoadResourceAimates(KNIGHT_ATTACK2_PATH_FORMAT, KNIGHT_ATTACK2_NUMBER);

	return true;
}
