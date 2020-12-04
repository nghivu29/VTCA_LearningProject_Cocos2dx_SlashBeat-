#include "CSceneGameplay.h"
#include "CHeroKnight.h"
#include "CEnemySphericalMonter.h"
#include "CMusic_Soldiers.h"
#include "CEnemyRock.h"

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

	// lable test
	_test = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 50);
	_test->setColor(Color3B::RED);
	_test->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100);
	addChild(_test, 10);

	// test music
	_music = CMusic_Soldiers::create();
//	_music = CMusicTest::create();
	addChild(_music);
	_music->retain();
	_music->playMusic();
	scheduleUpdate();

	// để sau khi định nghĩa xong _music
	initEnemyMananager();

	// test enemy rock 
	/*auto rock = CEnemyRock::createEnemy();
	rock->setPosition(500, 200);
	addChild(rock);*/


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

	// update backgound
	Point scrollDecrement = Point(25, 0); // Tốc độ Scroll, càng lớn cuộn càng nhanh
	_backgroundElements->setPosition(_backgroundElements->getPosition() - scrollDecrement);
	_backgroundElements->updatePosition();
	_frontgroundElements->setPosition(_frontgroundElements->getPosition() - scrollDecrement);
	_frontgroundElements->updatePosition();

	//test
	_test->setString(StringUtils::format("%d", _music->getBeatCurrent()));
}

bool CSceneGameplay::initHero()
{
	_hero = CHeroKnight::createKnight();
	_hero->setPosition(origin + Vec2(HERO_POS_X, visibleSize.height*GROUND1_POS_Y_RATIO));
	addChild(_hero, 0);
	_hero->retain();
	_hero->run2();
	return true;
}

bool CSceneGameplay::initBackground()
{

	/*auto bg = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/10_Sky.png");
	auto middle_layer = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/09_Forest.png");
	auto top_layer = Sprite::create("res/bg/forest/Parallax Forest Background - Blue/08_Forest.png");
	*/

	// Ảnh Background

	// Tạo 1 đối tượng Parallax
	_backgroundElements = InfiniteParallaxNode::create();
	_backgroundElements->setPosition(origin.x, origin.y);

	_frontgroundElements = InfiniteParallaxNode::create();
	_frontgroundElements->setPosition(origin.x, origin.y);
	
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/10_Sky.png", 0, Vec2(0.05, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/09_Forest.png", 1, Vec2(0.1, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/08_Forest.png", 2, Vec2(0.2, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/07_Forest.png", 3, Vec2(0.3, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/06_Forest.png", 4, Vec2(0.4, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/05_Particles.png", 5, Vec2(0.5, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/04_Forest.png", 6, Vec2(0.6, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/03_Particles.png", 1, Vec2(0.7, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/02_Bushes.png", 2, Vec2(0.8, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/01_Mist.png", 3, Vec2(0.9, 1));
	
	addChild(_backgroundElements, -5);
	addChild(_frontgroundElements, 5);

	scheduleUpdate();

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

void CSceneGameplay::helpInitParallaxLayer(InfiniteParallaxNode* parallax, const std::string & fileName, int z, cocos2d::Vec2 ratio, float distance)
{
	for (size_t i = 0; i < 2; i++)
	{
		auto sp = Sprite::create(fileName);
		sp->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		sp->setScale(visibleSize.width / sp->getContentSize().width, visibleSize.height / sp->getContentSize().height);
		parallax->addChild(sp, z, ratio, Vec2(sp->getContentSize().width*sp->getScaleX()*i + distance,0));
	}
}

