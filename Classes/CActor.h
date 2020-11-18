#pragma once
#include "CAnimateActor.h"

enum EActorStatus
{
	DEAD,
	HIT,
	IDLE1,
	IDLE2,
	RUN1,
	RUN2,
	STUN,
	ATTACK1,
	ATTACK2,
	WALK1,
	WALK2
};

class CActor : public cocos2d::Sprite, public CAnimateActor
{
	// các thuộc tính
protected:
	EActorStatus _status;
	int _hp;

	// các phương thức
public:
	virtual bool init();
	virtual bool loadResource();

};

