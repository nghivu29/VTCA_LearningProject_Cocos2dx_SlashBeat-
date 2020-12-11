#include "CAnimateActor.h"
	#include "common.h"

USING_NS_CC;

bool CAnimateActor::initAnimate()
{
	initDead();
	initHit();
	initIdle1();initIdle2();
	initRun1();initRun2();
	initStun();
	initAttack1();initAttack2();
	initWalk1(); initWalk2();
	return true;
}

bool CAnimateActor::initDead()
{
	return true;
}

bool CAnimateActor::initHit()
{
	return true;
}

bool CAnimateActor::initIdle1()
{
	return true;
}

bool CAnimateActor::initIdle2()
{
	return true;
}

bool CAnimateActor::initRun1()
{
	return true;
}

bool CAnimateActor::initRun2()
{
	return true;
}

bool CAnimateActor::initStun()
{
	return true;
}

bool CAnimateActor::initAttack1()
{
	return true;
}

bool CAnimateActor::initAttack2()
{
	return true;
}

bool CAnimateActor::initWalk1()
{
	return true;
}

bool CAnimateActor::initWalk2()
{
	return true;
}

void CAnimateActor::dead()
{
}

void CAnimateActor::hit()
{
}

void CAnimateActor::idle1()
{
}

void CAnimateActor::idle2()
{
}

void CAnimateActor::run1()
{
}

void CAnimateActor::run2()
{
}

void CAnimateActor::stun()
{
}

void CAnimateActor::attack1()
{
}

void CAnimateActor::attack2()
{
}

void CAnimateActor::walk1()
{
}

void CAnimateActor::walk2()
{
}

/*
* Tạo mảng các con trỏ Animate
* @param filePathFormart là đường dẫn của file%d.plist
* @param frameNameFormat tên của các FrameSprite theo định dạng name%d.png
* @size độ dài mảng
* @frameNumber số lượng frame trong file.plist
* @delay là thời gian giữa các SpriteFrame
*/
cocos2d::Animate* CAnimateActor::helpCreateAnimates(const char* frameNameFormat, int frameNumber, float delay)
{
	return helpCreateAnimates(frameNameFormat, 0, frameNumber - 1, delay);
}

cocos2d::Animate * CAnimateActor::helpCreateAnimates(const char * frameNameFormat, int fromFrame, int toFrame, float delay)
{
	auto cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> vector;
	for (size_t j = fromFrame; j <= toFrame; j++)
	{
		vector.pushBack
		(
			cache->getSpriteFrameByName
			(
				StringUtils::format(frameNameFormat, j)
			)
		);
	}
	auto animate = Animate::create(Animation::createWithSpriteFrames(vector, delay));
	//animate->getAnimation()->setRestoreOriginalFrame(true);
	animate->retain();
	return animate;
}

bool CAnimateActor::helpLoadResourceAimates(const char * filePathFormat, int size)
{
	auto cache = SpriteFrameCache::getInstance();
	for (size_t i = 0; i < size; i++)
	{
		if (cache->isSpriteFramesWithFileLoaded(StringUtils::format(filePathFormat, i))) break;
		else cache->addSpriteFramesWithFile(StringUtils::format(filePathFormat, i));
	}
	return true;
}
