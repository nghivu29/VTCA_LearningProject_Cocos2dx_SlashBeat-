#include "CSceneMainmenu.h"
#include "CLayerSelectScreenPlay.h"
#include "common.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;


CSceneMainmenu * CSceneMainmenu::createScene()
{
	return CSceneMainmenu::create();
}

bool CSceneMainmenu::init()
{
	if (!Scene::init())
		return false;

	setName("SceneMainmenu");
	initMenu();
	initBg();

	AudioEngine::play2d("res/audio/music/Welshly Arms-Legendary.mp3", true);

	return true;
}

void CSceneMainmenu::startGame(cocos2d::Ref *)
{
	AudioEngine::stopAll();
	Director::getInstance()->pushScene(CLayerSelectScreenPlay::createScene());
	log("START GAME");
}

void CSceneMainmenu::exit(cocos2d::Ref *)
{
	log("EXIT");
	Director::getInstance()->end();
}

bool CSceneMainmenu::initBg()
{
	// img
	auto bg = Sprite::create("res/bg/bg02.jpg");
	bg->setPosition(origin);
	bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	bg->setScale(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	addChild(bg, -2);

	// effect
	auto effect = ParticleSun::create();
	effect->setGravity(Vec2(200, 200));
	effect->setTotalParticles(100);
	effect->setStartSize(50);
	effect->setEndSize(50);
	effect->setPosVar(Vec2(visibleSize.width, visibleSize.height));
	effect->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	effect->setPosition(origin);
	addChild(effect, -1);

	return true;
}

bool CSceneMainmenu::initMenu()
{
	_itemPlayGame = MenuItemImage::create(
		"ui/button1.png",
		"ui/button8.png",
		CC_CALLBACK_1(CSceneMainmenu::startGame, this));
	
	_itemExitGame = MenuItemImage::create(
		"ui/button3.png",
		"ui/button10.png",
		CC_CALLBACK_1(CSceneMainmenu::exit, this));

	_itemPlayGame->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	_itemExitGame->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);

	_itemPlayGame->setScale(BTN_PLAYGAME_RATIO);
	_itemExitGame->setScale(BTN_PLAYGAME_RATIO);

	_itemPlayGame->setPosition(0, 0);
	_itemExitGame->setPosition(_itemPlayGame->getPosition() - Vec2(0, _itemPlayGame->getContentSize().height * _itemPlayGame->getScale() + 20));

	Vector<MenuItem*> vector;
	vector.pushBack(_itemPlayGame);
	vector.pushBack(_itemExitGame);
	_menu = Menu::createWithArray(vector);
	_menu->retain();
	_menu->setPosition(origin.x + visibleSize.width * 0.75, origin.y + visibleSize.height * 0.8);
	addChild(_menu);
	return true;
}
