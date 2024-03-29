﻿#pragma once
#include "CAnimateActor.h"

enum EActorStatus
{
	NONE,
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
	WALK2,
	JUMPUP,
	JUMPDOWN
};

class CActor : public cocos2d::Sprite, public CAnimateActor
{
	// các thuộc tính
protected:
	EActorStatus _status;
	int _hp;

	int lastStatus = -1;

public:
	// combo
	int _combo = 0;

	// diem tich tu
	int _accumulation1 = 2;

	// diem tieu diet quai
	int _score = 0;

	// các phương thức
public:
	~CActor();
	virtual bool init();
	virtual bool loadResource();

	// các hành động của nhân vật
	virtual void dead();
	virtual void hit();
	virtual void idle1();
	virtual void idle2();
	virtual void run1();
	virtual void run2();
	virtual void stun();
	virtual void attack1();
	virtual void attack2();
	virtual void jumpUP();
	virtual void jumpDown();
	virtual void walk1();
	virtual void walk2();

	// cac script
	virtual void script1();

	// cac setter va getter
	void setHp(int hp);
	void setStatus(EActorStatus status);
	int getHp();
	EActorStatus getStatus();
};

