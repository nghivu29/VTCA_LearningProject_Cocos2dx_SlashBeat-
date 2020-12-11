#pragma once
#include "cocos2d.h"

/*
CAnimateActor của các nhân vật ứng với EActorStauts của các nhân vật đó
Đối với Hero: thứ tự của 1 animate trong mảng ứng với thứ tự của EMusicStatus
*/
class CAnimateActor
{
public:
	cocos2d::Vector<cocos2d::Animate*> _animatesDead;
	cocos2d::Vector<cocos2d::Animate*> _animatesHit;
	cocos2d::Vector<cocos2d::Animate*> _animatesIdle1;
	cocos2d::Vector<cocos2d::Animate*> _animatesIdle2;
	cocos2d::Vector<cocos2d::Animate*> _animatesRun1;
	cocos2d::Vector<cocos2d::Animate*> _animatesRun2;
	cocos2d::Vector<cocos2d::Animate*> _animatesStun;
	cocos2d::Vector<cocos2d::Animate*> _animatesAttack1;
	cocos2d::Vector<cocos2d::Animate*> _animatesAttack2;
	cocos2d::Vector<cocos2d::Animate*> _animatesWalk1;
	cocos2d::Vector<cocos2d::Animate*> _animatesWalk2;

protected:
	// các hàm định nghĩa
	virtual bool initAnimate();
	virtual bool initDead();
	virtual bool initHit();
	virtual bool initIdle1();
	virtual bool initIdle2();
	virtual bool initRun1();
	virtual bool initRun2();
	virtual bool initStun();
	virtual bool initAttack1();
	virtual bool initAttack2();
	virtual bool initWalk1();
	virtual bool initWalk2();

public:
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
	virtual void walk1();
	virtual void walk2();

	// giúp tạo animate
	static cocos2d::Animate* helpCreateAnimates(const char* frameNameFormat, int frameNumber, float delay = 0.02f);
	static cocos2d::Animate* helpCreateAnimates(const char* frameNameFormat, int fromFrame, int toFrame, float delay = 0.02f);
	static bool helpLoadResourceAimates(const char* filePathFormat, int size);
};

