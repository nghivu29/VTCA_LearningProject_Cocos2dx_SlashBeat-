#include "CHero.h"
#include "common.h"

USING_NS_CC;

#define HERO_POS_UP Vec2(HERO_POS_X, GROUND2_POS_Y_RATIO*Director::getInstance()->getVisibleSize().height)
#define HERO_POS_DOWN Vec2(HERO_POS_X, GROUND1_POS_Y_RATIO*Director::getInstance()->getVisibleSize().height)

CHero * CHero::createHero()
{
	return CHero::create();
}

bool CHero::init()
{
	if (!CActor::init())
		return false;

	setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	
	initCtrl();
	scheduleUpdate();

	return true;
}

bool CHero::loadResource()
{
	return true;
}

void CHero::update(float dt)
{
	if (getPosition().y > HERO_POS_DOWN.y)
	{
		_frameFly++;
		if (_frameFly == 90)
		{
			setPosition(HERO_POS_DOWN);
			_frameFly = 0;
		}
	}
}

bool CHero::initWin32Ctrl()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode k, cocos2d::Event*) {
		switch (k)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_7:
			idle2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_8:
			run2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_2:
			setPosition(HERO_POS_DOWN);
			attack1();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_1:
			setPosition(HERO_POS_DOWN);
			attack2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_5:
			_frameFly = 0;
			setPosition(HERO_POS_UP);
			attack1();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_4:
			_frameFly = 0;
			setPosition(HERO_POS_UP);
			attack2();
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}


bool CHero::initAndroidCtrl()
{
	center_scene = Vec2
	(
		Director::getInstance()->getVisibleOrigin().x + Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleOrigin().y + Director::getInstance()->getVisibleSize().height / 2
	);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* t, Event*)
	{

		if (t->getLocation().y > center_scene.y)
		{
			_frameFly = 0;
			if (t->getLocation().x > center_scene.x)
			{
				setPosition(HERO_POS_UP);
				attack1();
			}
			else
			{
				setPosition(HERO_POS_UP);
				attack2();
			}
		}
		else
		{
			if (t->getLocation().x > center_scene.x)
			{
				setPosition(HERO_POS_DOWN);
				attack1();
			}
			else
			{
				setPosition(HERO_POS_DOWN);
				attack2();
			}
		}


		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool CHero::initCtrl()
{
	switch (CC_TARGET_PLATFORM)
	{
	case CC_PLATFORM_ANDROID:
		initAndroidCtrl();
		break;
	case CC_PLATFORM_WIN32:
		initWin32Ctrl();
		break;
	}
	return true;
}




