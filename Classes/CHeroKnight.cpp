#include "CHeroKnight.h"
#include "AudioEngine.h"
#include "common.h"
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

	setScale(KNIGHT_RATIO_H);
	_hp = 10;

	SpriteFrameCache::getInstance()->destroyInstance();

	return true;
}

void CHeroKnight::dead()
{
	CHero::dead();
	stopAllActions();
	runAction(Sequence::create
	(
		CallFunc::create
		(
			[this]() 
			{
				auto dir = Director::getInstance();
				auto origin = dir->getVisibleOrigin();
				auto visibleSize = dir->getVisibleSize();
				auto scene = dir->getRunningScene();
				scene->pauseSchedulerAndActions();
				experimental::AudioEngine::stopAll();

				auto sp = Sprite::create("ui/button_rock_greystar1.png");
				sp->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
				sp->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height);
				sp->setScale(0.5f);
				scene->addChild(sp, 10);

				scene->getChildByName("LayerOption")->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

			}
		),
		_animatesDead.at(0),
		nullptr
	));
}

void CHeroKnight::hit()
{
	CHero::hit();
	stopAllActions();
	runAction(Sequence::create(_animatesHit.at(0), CallFunc::create(CC_CALLBACK_0(CHeroKnight::run2, this)), nullptr));
	_accumulation1--;
}

void CHeroKnight::idle1()
{
}

void CHeroKnight::idle2()
{
	CHero::idle2();
	stopAllActions();
	runAction(RepeatForever::create(_animatesIdle2.at(0)));
}

void CHeroKnight::run1()
{
		
}

void CHeroKnight::run2()
{
	CHero::run2();
	stopAllActions();
	runAction(RepeatForever::create(_animatesRun2.at(0)));
}

void CHeroKnight::stun()
{
}

void CHeroKnight::attack1()
{
	log("Hero: %f", _music->_songPositionInBeats);
	CHero::attack1();
	stopAllActions();
	runAction(Sequence::create(_animatesAttack1.at(0), CallFunc::create(CC_CALLBACK_0(CHeroKnight::run2,this)), nullptr));
}

void CHeroKnight::attack2()
{
	log("Hero: %f", _music->_songPositionInBeats);
	CHero::attack2();
	stopAllActions();
	runAction(Sequence::create(_animatesAttack2.at(0), CallFunc::create(CC_CALLBACK_0(CHeroKnight::run2, this)), nullptr));

}

void CHeroKnight::walk1()
{
}

void CHeroKnight::walk2()
{
}

bool CHeroKnight::initDead()
{
	_animatesDead.pushBack(helpCreateAnimates(KNIGHT_DEAD_0_FRAME_NAME_FORMAT, KNIGHT_DEAD_FRAME_NUMBER, 0.05f));
	return true;
}

bool CHeroKnight::initHit()
{
	_animatesHit.pushBack(helpCreateAnimates(KNIGHT_HIT_0_FRAME_NAME_FORMAT, KNIGHT_HIT_FRAME_NUMBER));
	return true;
}

bool CHeroKnight::initIdle1()
{
	return false;
}

bool CHeroKnight::initIdle2()
{
	_animatesIdle2.pushBack(helpCreateAnimates(KNIGHT_IDLE2_0_FRAME_NAME_FORMAT, KNIGHT_IDLE2_FRAME_NUMBER));
	return true;
}

bool CHeroKnight::initRun1()
{
	return false;
}

bool CHeroKnight::initRun2()
{
	_animatesRun2.pushBack(helpCreateAnimates(KNIGHT_RUN2_0_FRAME_NAME_FORMAT, KNIGHT_RUN2_FRAME_NUMBER, 0.018f));
	return true;
}

bool CHeroKnight::initStun()
{
	return false;
}

bool CHeroKnight::initAttack1()
{
	_animatesAttack1.pushBack(helpCreateAnimates(KNIGHT_ATTACK1_0_FRAME_NAME_FORMAT, KNIGHT_ATTACK1_FRAME_NUMBER, 0.007f));
	return true;
}

bool CHeroKnight::initAttack2()
{
	_animatesAttack2.pushBack(helpCreateAnimates(KNIGHT_ATTACK2_0_FRAME_NAME_FORMAT, KNIGHT_ATTACK2_FRAME_NUMBER, 0.007f));
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

	// load resource animation dead
	CAnimateActor::helpLoadResourceAimates(KNIGHT_DEAD_PATH_FORMAT, KNIGHT_DEAD_NUMBER);


	return true;
}
