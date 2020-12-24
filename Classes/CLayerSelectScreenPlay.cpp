#include "CLayerSelectScreenPlay.h"
#include "CSceneGameplay.h"
#include "CSceneGameplay2.h"
#include "CSceneGameplay3.h"

// xoa di sau khi test xong
#include "CEnemyBoss.h"


USING_NS_CC;

cocos2d::Scene * CLayerSelectScreenPlay::createScene()
{
	auto scene = Scene::create();
	auto layer = CLayerSelectScreenPlay::create();
	scene->addChild(layer);
	return scene;
}

bool CLayerSelectScreenPlay::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto number1Item = MenuItemImage::create(
		"ui/mybutton1.png",
		"ui/mybutton1_selected.png",
		CC_CALLBACK_1(CLayerSelectScreenPlay::gotoScreen1Callback, this));

	auto number2Item = MenuItemImage::create(
		"ui/mybutton2.png",
		"ui/mybutton2_selected.png",
		CC_CALLBACK_1(CLayerSelectScreenPlay::gotoScreen2Callback, this));

	auto number3Item = MenuItemImage::create(
		"ui/mybutton3.png",
		"ui/mybutton3_selected.png",
		CC_CALLBACK_1(CLayerSelectScreenPlay::gotoScreen3Callback, this));

	auto backItem = MenuItemImage::create(
		"ui/mybutton_back_1.png",
		"ui/mybutton_back_0.png",
		CC_CALLBACK_1(CLayerSelectScreenPlay::backSceneCallback, this));

	backItem->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);

	number1Item->setPosition(origin.x + visibleSize.width / 6 * 2, origin.y + visibleSize.height / 6 * 4);
	number2Item->setPosition(origin.x + visibleSize.width / 6 * 3, origin.y + visibleSize.height / 6 * 4);
	number3Item->setPosition(origin.x + visibleSize.width / 6 * 4, origin.y + visibleSize.height / 6 * 4);
	backItem->setPosition(origin.x + visibleSize.width, origin.y + visibleSize.height);

	float ratioX = visibleSize.width / number1Item->getContentSize().width;
	float ratioY = visibleSize.height / number1Item->getContentSize().height;
	number1Item->setScale(ratioX*0.2);
	number2Item->setScale(ratioX*0.2);
	number3Item->setScale(ratioX*0.2);
	backItem->setScale(ratioX*0.5, ratioX*0.3);

	auto menu = Menu::create(number1Item, number2Item, number3Item, backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	

	// test boss;
	auto boss = CEnemyBoss::createBoss();
	boss->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	boss->retain();
	boss->setFlipX(false);
	boss->setPosition(origin.x + 300, origin.y + 100);
	boss->unscheduleUpdate();
	addChild(boss, 5);
	boss->idle1();


	initBg();

	return true;
}

void CLayerSelectScreenPlay::gotoScreen1Callback(cocos2d::Ref * pSender)
{
	Director::getInstance()->pushScene(CSceneGameplay::createScene());
}

void CLayerSelectScreenPlay::gotoScreen2Callback(cocos2d::Ref * pSender)
{
	Director::getInstance()->pushScene(CSceneGameplay2::createScene());
}

void CLayerSelectScreenPlay::gotoScreen3Callback(cocos2d::Ref * pSender)
{
	Director::getInstance()->pushScene(CSceneGameplay3::createScene());
}

void CLayerSelectScreenPlay::backSceneCallback(cocos2d::Ref * pSender)
{
	Director::getInstance()->popScene();
}

bool CLayerSelectScreenPlay::initBg()
{
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("res/bg/bg01.png");
	bg->setPosition(origin);
	bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	bg->setScale(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);

	addChild(bg, -1);
	return true;
}
