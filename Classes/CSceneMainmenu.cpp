#include "CSceneMainmenu.h"
#include "CSceneGameplay.h"

USING_NS_CC;

CSceneMainmenu * CSceneMainmenu::createScene()
{
	return CSceneMainmenu::create();
}

bool CSceneMainmenu::init()
{
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	_itemPauseGame = MenuItemFont::create("Start Game", CC_CALLBACK_1(CSceneMainmenu::startGame, this));
	_itemExitGame = MenuItemFont::create("Exit", CC_CALLBACK_1(CSceneMainmenu::exit, this));
	_itemExitGame->setPosition(_itemPauseGame->getPosition() - Vec2(0, _itemPauseGame->getContentSize().height));

	Vector<MenuItem*> vector;
	vector.pushBack(_itemPauseGame);
	vector.pushBack(_itemExitGame);
	_menu = Menu::createWithArray(vector);
	_menu->retain();
	_menu->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(_menu);

	return true;
}

void CSceneMainmenu::startGame(cocos2d::Ref *)
{
	Director::getInstance()->pushScene(CSceneGameplay::create());
	log("START GAME");
}

void CSceneMainmenu::exit(cocos2d::Ref *)
{
	log("EXIT");
	Director::getInstance()->end();
}
