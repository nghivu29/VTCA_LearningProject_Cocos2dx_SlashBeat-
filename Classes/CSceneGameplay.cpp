#include "CSceneGameplay.h"
#include "CHeroKnight.h"

USING_NS_CC;

CSceneGameplay * CSceneGameplay::createScene()
{
	return CSceneGameplay::create();
}

bool CSceneGameplay::init()
{
	if (!Scene::init())
	{
		return false;
	}

	if (!initHero())
	{
		return false;
	}

	// test music
	_music = CMusicTest::create();
	addChild(_music);
	_music->retain();
	_music->playMusic();
	scheduleUpdate();

	// code de test animation
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode k, cocos2d::Event*) {
		switch (k)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_1:
			_hero->idle2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_2:
			_hero->run2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_3:
			_hero->attack2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_4:
			_hero->attack1();
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

/*
* Các tài nguyên được tải
*	- tài nguyên nhân vật knight
*/
bool CSceneGameplay::loadResource()
{
	return true;
}

void CSceneGameplay::update(float delta)
{
	if (_music->hasNote())
	{
		log("%d-%d===============================================",_music->getBeatCurrent(), _music->getMeasureCurrent());
	}
}

bool CSceneGameplay::initHero()
{
	_hero = CHeroKnight::createKnight();
	_hero->setPosition(200, 200);
	addChild(_hero);
	_hero->retain();

	return true;
}
