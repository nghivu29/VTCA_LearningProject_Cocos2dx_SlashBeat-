#include "CLayerSelectScreenPlay.h"
#include "CSceneGameplay.h"
#include "CSceneGameplay2.h"

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

	number1Item->setPosition(origin.x + visibleSize.width / 6 * 2, origin.y + visibleSize.height / 6 * 4);
	number2Item->setPosition(origin.x + visibleSize.width / 6 * 3, origin.y + visibleSize.height / 6 * 4);

	float ratioX = visibleSize.width / number1Item->getContentSize().width;
	float ratioY = visibleSize.height / number1Item->getContentSize().height;
	number1Item->setScale(ratioX*0.2);
	number2Item->setScale(ratioX*0.2);

	auto menu = Menu::create(number1Item, number2Item, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	auto menuFrame = Sprite::create("ui/frame.png");
	ratioX = visibleSize.width / menuFrame->getContentSize().width;
	ratioY = visibleSize.height / menuFrame->getContentSize().height;
	menuFrame->setScale(ratioX*0.8, ratioY*0.9);
	menuFrame->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(menuFrame, 0);
	
	/*auto bg = LayerColor::create(Color4B::WHITE);
	this->addChild(bg, -1);*/


	// test boss;
	auto boss = CEnemyBoss::createBoss();
	boss->retain();
	boss->unscheduleUpdate();
	addChild(boss, 5);
	boss->run1();

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
