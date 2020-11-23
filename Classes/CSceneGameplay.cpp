#include "CSceneGameplay.h"
#include "CHeroKnight.h"
#include "CEnemySphericalMonter.h"
#include "CMusic_Soldiers.h"

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

	initLayerOption();
	initBtnPause();

	//// test enemy
	//auto enemy = CEnemySphericalMonter::createMonster();
	//enemy->retain();
	//enemy->setPosition(500, 150);
	//addChild(enemy);
	////enemy->hit();
	//enemy->idle1();

	// test music
	_music = CMusic_Soldiers::create();
	addChild(_music);
	_music->retain();
	_music->playMusic();
	scheduleUpdate();

	// để sau khi định nghĩa xong _music
	initEnemyMananager();

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
	_hero->setPosition(300, 70);
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
	_enemyManager = new CEnemyManager(_music, _hero);
	return true;
}

bool CSceneGameplay::initBtnPause()
{
 	auto itemPause = MenuItemFont::create("Pause", CC_CALLBACK_1(CSceneGameplay::pauseGame, this));

	Vector<MenuItem*> vector;
	vector.pushBack(itemPause);
	_menuCtrl = Menu::createWithArray(vector);
	_menuCtrl->setColor(Color3B::BLACK);
	_menuCtrl->retain();
	_menuCtrl->setPosition(origin.x + visibleSize.width - itemPause->getContentSize().width, origin.y + visibleSize.height - itemPause->getContentSize().height);
	addChild(_menuCtrl);
	return true;
}

bool CSceneGameplay::initLayerOption()
{
	_layerOption = CLayerOption::createLayer();
	_layerOption->setPosition(-5000, 0);
	addChild(_layerOption, 5);
	_layerOption->retain();
	return true;
}

void CSceneGameplay::pauseGame(cocos2d::Ref *)
{
	_layerOption->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
	Director::getInstance()->pause();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}
