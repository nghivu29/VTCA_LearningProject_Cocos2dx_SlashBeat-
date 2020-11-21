#include "CLayerOption.h"
#include "SimpleAudioEngine.h"
#include "CSceneGameplay.h"

USING_NS_CC;

CLayerOption * CLayerOption::createLayer()
{
	return CLayerOption::create();
}

bool CLayerOption::init()
{
	if (!Layer::init())
		return false;

	auto itemContinue = MenuItemFont::create("Continue", CC_CALLBACK_1(CLayerOption::playContinue, this));
	itemContinue->setPosition(0, 0);
	auto itemBack = MenuItemFont::create("Back to main menu", CC_CALLBACK_1(CLayerOption::backScene, this));
	itemBack->setPosition(itemContinue->getPosition() - Vec2(0, itemContinue->getContentSize().height));
	auto itemAgain = MenuItemFont::create("Again", CC_CALLBACK_1(CLayerOption::playAgain, this));
	itemAgain->setPosition(itemBack->getPosition() - Vec2(0, itemBack->getContentSize().height));

	Vector<MenuItem*> vector;
	vector.pushBack(itemContinue);
	vector.pushBack(itemBack);
	vector.pushBack(itemAgain);
	_menu = Menu::createWithArray(vector);
	_menu->setPosition(0, 0);
	_menu->setColor(Color3B::BLACK);
	_menu->retain();
	addChild(_menu);

	return true;
}

void CLayerOption::playContinue(cocos2d::Ref *)
{
	Director::getInstance()->resume();
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	setPosition(-5000, 0);
}

void CLayerOption::backScene(cocos2d::Ref *)
{
	Director::getInstance()->popScene();
	Director::getInstance()->resume();
}

void CLayerOption::playAgain(cocos2d::Ref *)
{
	Director::getInstance()->replaceScene(CSceneGameplay::createScene());
	Director::getInstance()->resume();
}
