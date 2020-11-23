#include "CHero.h"
#include "proj.win32/resource.h"

USING_NS_CC;

CHero * CHero::createHero()
{
	return CHero::create();
}

bool CHero::init()
{
	if (!CActor::init())
		return false;
	setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	initWin32Ctrl();
	return true;
}

bool CHero::loadResource()
{
	return true;
}

bool CHero::initWin32Ctrl()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode k, cocos2d::Event*) {
		switch (k)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_1:
			idle2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_2:
			run2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_3:
			attack2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_4:
			attack1();
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}




