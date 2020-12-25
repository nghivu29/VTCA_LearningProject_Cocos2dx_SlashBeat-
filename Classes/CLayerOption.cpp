#include "CLayerOption.h"
#include "CSceneGameplay.h"
#include "CSceneGameplay2.h"
#include "CSceneGameplay3.h"
#include "CSceneTutorial.h"
#include "AudioEngine.h"
#include "common.h"

USING_NS_CC;

CLayerOption * CLayerOption::createLayer()
{
	return CLayerOption::create();
}

bool CLayerOption::init()
{
	if (!Layer::init())
		return false;
	
	//auto itemContinue = MenuItemFont::create("Continue", CC_CALLBACK_1(CLayerOption::playContinue, this));
	//itemContinue->setPosition(0, 0);
	//auto itemBack = MenuItemFont::create("Back to main menu", CC_CALLBACK_1(CLayerOption::backScene, this));
	//itemBack->setPosition(itemContinue->getPosition() - Vec2(0, itemContinue->getContentSize().height));
	//auto itemAgain = MenuItemFont::create("Again", CC_CALLBACK_1(CLayerOption::playAgain, this));
	//itemAgain->setPosition(itemBack->getPosition() - Vec2(0, itemBack->getContentSize().height));

	auto itemContinue = MenuItemImage::create(
		"ui/mybutton_resume_1.png",
		"ui/mybutton_resume_0.png",
		CC_CALLBACK_1(CLayerOption::playContinue, this));

	auto itemBack = MenuItemImage::create(
		"ui/mybutton_selectscene_1.png",
		"ui/mybutton_selectscene_0.png",
		CC_CALLBACK_1(CLayerOption::backScene, this));

	auto itemAgain = MenuItemImage::create(
		"ui/mybutton_retry_1.png",
		"ui/mybutton_retry_0.png",
		CC_CALLBACK_1(CLayerOption::playAgain, this));

	itemContinue->setScale(BTN_PAUSEGAME_RATIO);
	itemBack->setScale(BTN_PAUSEGAME_RATIO);
	itemAgain->setScale(BTN_PAUSEGAME_RATIO);

	itemContinue->setPosition(0, 0);
	itemBack->setPosition(itemContinue->getPosition() - Vec2(itemContinue->getContentSize().width * itemContinue->getScale() + 20, 0));
	itemAgain->setPosition(itemContinue->getPosition() + Vec2(itemContinue->getContentSize().width * itemContinue->getScale() + 20, 0));

	/*itemContinue->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	itemBack->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	itemAgain->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);*/



	Vector<MenuItem*> vector;
	vector.pushBack(itemContinue);
	vector.pushBack(itemBack);
	vector.pushBack(itemAgain);
	_menu = Menu::createWithArray(vector);
	_menu->setPosition(0, 0);
	_menu->retain();
	addChild(_menu);

	return true;
}

void CLayerOption::playContinue(cocos2d::Ref *)
{
	Director::getInstance()->resume();
	experimental::AudioEngine::resume(_musicID);
	setPosition(-5000, 0);
}

void CLayerOption::backScene(cocos2d::Ref *)
{
	experimental::AudioEngine::stopAll();
	Director::getInstance()->popScene();
	Director::getInstance()->resume();
}

void CLayerOption::playAgain(cocos2d::Ref *)
{
	experimental::AudioEngine::stopAll();
	auto scene = Director::getInstance()->getRunningScene();
	switch (scene->getTag())
	{
	case 0:
		Director::getInstance()->replaceScene(CSceneTutorial::createScene());
		break;
	case 1:
		Director::getInstance()->replaceScene(CSceneGameplay::createScene());
		break;
	case 2:
		Director::getInstance()->replaceScene(CSceneGameplay2::createScene());
		break;
	case 3:
		Director::getInstance()->replaceScene(CSceneGameplay3::createScene());
		break;
	}
	Director::getInstance()->resume();
}

void CLayerOption::setMusicID(int id)
{
	_musicID = id;
}
