#include "CSceneSplash.h"
#include "CSceneMainmenu.h"
#include "common.h"

USING_NS_CC;

cocos2d::Scene * CSceneSplash::createScene()
{
	return CSceneSplash::create();
}

bool CSceneSplash::init()
{
	if (!Scene::init())
		return false;

	initIntro();
	gotoSceneByTouch(nullptr);

	return true;
}

bool CSceneSplash::initIntro()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto title = Label::create(GAME_TITLE, FONT_MARKERFELT_PATH, GAME_TITLE_SIZE);
	title->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	title->setOpacity(0);
	addChild(title);
	title->runAction(Sequence::create(DelayTime::create(2.5f), FadeIn::create(1.0f), nullptr));

	auto helloCocos = Sprite::create("HelloWorld.png");
	helloCocos->setOpacity(0);
	helloCocos->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(helloCocos);
	helloCocos->runAction(Sequence::create(FadeIn::create(1.0f), DelayTime::create(0.5f), FadeOut::create(1.0f), nullptr));

	auto lbMakeBy = Label::create("make by", FONT_MARKERFELT_PATH, 50);
	lbMakeBy->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	lbMakeBy->setOpacity(0);
	lbMakeBy->setPosition(helloCocos->getPosition() + Vec2(0, helloCocos->getContentSize().height / 2 + 20));
	addChild(lbMakeBy);
	lbMakeBy->runAction(Sequence::create(FadeIn::create(1.0f), DelayTime::create(0.5f), FadeOut::create(1.0f), nullptr));
	return true;
}

void CSceneSplash::gotoSceneByTouch(cocos2d::Scene * scene)
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch*, Event*)
	{
		Director::getInstance()->replaceScene(CSceneMainmenu::createScene());
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


