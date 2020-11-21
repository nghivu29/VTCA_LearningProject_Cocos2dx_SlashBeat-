#include "CSceneGameplay.h"
#include "CHeroKnight.h"
#include "CEnemySphericalMonter.h"

USING_NS_CC;

CSceneGameplay * CSceneGameplay::createScene()
{
	return CSceneGameplay::create();
}

bool CSceneGameplay::init()
{
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	if (!Scene::init())
	{
		return false;
	}

	if (!(initBackground() && initHero()))
	{
		return false;
	}

	//// test enemy
	//auto enemy = CEnemySphericalMonter::createMonster();
	//enemy->retain();
	//enemy->setPosition(500, 150);
	//addChild(enemy);
	////enemy->hit();
	//enemy->idle1();

	// test music
	_music = CMusicTest::create();
	addChild(_music);
	_music->retain();
	_music->playMusic();
	scheduleUpdate();

	// để sau khi định nghĩa xong _music
	initEnemyMananager();

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
	_enemyManager->updateEnemies(delta);
	

	//log("%d", _music->getFrameCurrent());
	/*if (_music->hasNote())
	{
		switch (_music->getMeasureCurrent())
		{
		case 0:
			log("%d-%d===================================================", _music->getBeatCurrent(), _music->getMeasureCurrent());
			break;
		case 1:
			log("%d-%d======================", _music->getBeatCurrent(), _music->getMeasureCurrent());
			break;
		case 2:
			log("%d-%d===========================", _music->getBeatCurrent(), _music->getMeasureCurrent());
			break;
		case 3:
			log("%d-%d=========================", _music->getBeatCurrent(), _music->getMeasureCurrent());
			break;

		}
	}*/


}

bool CSceneGameplay::initHero()
{
	_hero = CHeroKnight::createKnight();
	_hero->setPosition(200, 150);
	addChild(_hero);
	_hero->retain();
	return true;
}

bool CSceneGameplay::initBackground()
{
	auto bg = Sprite::create(BACKGROUND_PATH);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	auto ratioWidth = visibleSize.width / bg->getContentSize().width;
	auto ratioHeght = visibleSize.height / bg->getContentSize().height;
	bg->setScaleX(ratioWidth);
	bg->setScaleY(ratioHeght);
	this->addChild(bg, -10);
	return true;
}

bool CSceneGameplay::initEnemyMananager()
{
	_enemyManager = new CEnemyManager(_music);
	return true;
}
