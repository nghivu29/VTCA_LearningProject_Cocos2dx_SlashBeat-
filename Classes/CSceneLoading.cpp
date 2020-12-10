#include "CSceneLoading.h"
#include "ui/CocosGUI.h"
#include "CSceneGameplay.h"


USING_NS_CC;

CSceneLoading * CSceneLoading::createScene()
{
	return CSceneLoading::create();
}

bool CSceneLoading::init()
{
	if (!Scene::init())
		return false;

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visible = Director::getInstance()->getVisibleSize();

	auto loadingBar = ui::LoadingBar::create("loading_bar.png");
	loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingBar->setPosition(Vec2(origin.x+visible.width/2, origin.y+visible.height/2));
	loadingBar->setPercent(50);

	std::string path = "res/bg/forest/Parallax Forest Background - Blue/parallax_forest_bg.plist";
	auto cache = SpriteFrameCache::getInstance();
	if (!cache->isSpriteFramesWithFileLoaded(path))
		cache->addSpriteFramesWithFile(path);

	loadingBar->setPercent(100);

	auto listener = EventListenerMouse::create();
	listener->onMouseUp = [&](EventMouse* event) {
		Director::getInstance()->replaceScene(CSceneGameplay::createScene());
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	/*auto sp1 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/01_Mist.png");
	cache->addSpriteFrame(sp1->getSpriteFrame(), "bg_forest_01_Mist.png");
	loadingBar->setPercent(10);

	auto sp2 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/02_Bushes.png");
	cache->addSpriteFrame(sp2->getSpriteFrame(), "bg_forest_02_Bushes.png");
	loadingBar->setPercent(20);


	auto sp3 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/03_Particles.png");
	cache->addSpriteFrame(sp3->getSpriteFrame(), "bg_forest_03_Particles.png");
	loadingBar->setPercent(30);


	auto sp4 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/04_Forest.png");
	cache->addSpriteFrame(sp4->getSpriteFrame(), "bg_forest_04_Forest.png");
	loadingBar->setPercent(40);


	auto sp5 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/05_Particles.png");
	cache->addSpriteFrame(sp5->getSpriteFrame(), "bg_forest_05_Particles.png");
	loadingBar->setPercent(50);


	auto sp6 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/06_Forest.png");
	cache->addSpriteFrame(sp6->getSpriteFrame(), "bg_forest_06_Forest.png");
	loadingBar->setPercent(60);


	auto sp7 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/07_Forest.png");
	cache->addSpriteFrame(sp7->getSpriteFrame(), "bg_forest_07_Forest.png");
	loadingBar->setPercent(70);


	auto sp8 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/08_Forest.png");
	cache->addSpriteFrame(sp8->getSpriteFrame(), "bg_forest_08_Forest.png");
	loadingBar->setPercent(75);


	auto sp9 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/09_Forest.png");
	cache->addSpriteFrame(sp9->getSpriteFrame(), "bg_forest_09_Forest.png");
	loadingBar->setPercent(80);


	auto sp10 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/10_Sky.png");
	cache->addSpriteFrame(sp10->getSpriteFrame(), "bg_forest_10_Sky.png");
	loadingBar->setPercent(85);


	auto sp11 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/mossy.png");
	cache->addSpriteFrame(sp11->getSpriteFrame(), "bg_forest_mossy01.png");
	loadingBar->setPercent(90);


	auto sp12 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/mossy02.png");
	cache->addSpriteFrame(sp12->getSpriteFrame(), "bg_forest_mossy02.png");
	loadingBar->setPercent(95);


	auto sp13 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/mossy03.png");
	cache->addSpriteFrame(sp13->getSpriteFrame(), "bg_forest_mossy03.png");
	loadingBar->setPercent(98);


	auto sp14 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/mossy04.png");
	cache->addSpriteFrame(sp14->getSpriteFrame(), "bg_forest_mossy04.png");
	loadingBar->setPercent(99);


	auto sp15 = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/mossy05.png");
	cache->addSpriteFrame(sp15->getSpriteFrame(), "bg_forest_mossy05.png");
	loadingBar->setPercent(100);*/

	this->addChild(loadingBar);

	return true;
}
