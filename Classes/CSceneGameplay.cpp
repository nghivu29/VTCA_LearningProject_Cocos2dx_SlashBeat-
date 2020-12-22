#include "CSceneGameplay.h"
#include "CHeroKnight.h"
#include "CEnemySphericalMonster.h"
#include "CEnemyRock.h"
#include "CAssetMossy.h"
#include "CMusicBlacksmithSForge.h"
#include "CMusicTest.h"
#include "CMusicThroughTheFireAndFlames.h"
#include "CMusicUnity.h"
#include "ui/CocosGUI.h"

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
	setTag(1);

	initLayerOption();
	initBtnPause();

	// lable test
	_test = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 50);
	_test->setColor(Color3B::RED);
	_test->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100);
	addChild(_test, 10);

	initMusic();
	scheduleUpdate();

	if (!(initBackground() && initHero()))
	{
		return false;
	}

	// để sau khi định nghĩa xong _music
	initEnemyMananager();

	// cho hero chay
	_hero->_animatesRun2.at(0)->setDuration(_heroRunSpeed);

	// khoi tao hp cua hero
	initHpBar();

	initHeroCtr();

	return true;
}

/*
* Các tài nguyên được tải
*	
*/
bool CSceneGameplay::loadResource()
{
	return true;
}

void CSceneGameplay::update(float delta)
{
	//dieu kien ket thuc mang choi
	if (_music->_isDone)
	{
		_test->setString("Win");
		showScore();
		pauseGame(this);
		unscheduleUpdate();
		return;
	}

	// update diem so
	_test->setString(StringUtils::format("%d/%d", _hero->_score, _enemyManager->_countMonster));

	// update ke thu
	_enemyManager->updateEnemies(delta);

	// update backgound
	Point scrollDecrement = Point(_bgSpeed, 0); // Tốc độ Scroll, càng lớn cuộn càng nhanh
	_backgroundElements->setPosition(_backgroundElements->getPosition() - scrollDecrement);
	_backgroundElements->updatePosition();
	_frontgroundElements->setPosition(_frontgroundElements->getPosition() - scrollDecrement);
	_frontgroundElements->updatePosition();


	if (!_isPlayMusic)
	{
		_music->StartMusic();
		_isPlayMusic = true;
		_layerOption->setMusicID(_music->_audioID);
	}

	//update hero hp
	updateHp(delta);


	//log 
	/*log("pos: %f", _music->_songPosition);
	log("pre: %f", _music->pre_songPosition);*/

}


bool CSceneGameplay::initMusic()
{
	// test music
//_music = CMusic_Soldiers::create();
	switch (_musicID)
	{
	case EMusic::TEST:
		_music = CMusicTest::createMusic();
		break;
	case EMusic::BLACKSMITH_S_FORGE:
		_music = CMusicBlacksmithSForge::createMusic();
		break;
	case EMusic::THROUGHTHEFIREANDFLAMES:
		_music = CMusicThroughTheFireAndFlames::createMusic();
		break;
	case EMusic::UNITY:
		_music = CMusicUnity::createMusic();
		break;
	default:
		_music = CMusicTest::createMusic();
		break;
	}
	_music->retain();
	addChild(_music);
	return true;
}

bool CSceneGameplay::initHero()
{
	_hero = CHeroKnight::createKnight();
	_hero->setPosition(origin + Vec2(HERO_POS_X, visibleSize.height*GROUND1_POS_Y_RATIO));
	_hero->setMusic(_music);
	addChild(_hero, 0);
	_hero->retain();
	_hero->run2();
	return true;
}

bool CSceneGameplay::initBackground()
{
	// Ảnh Background

	// Tạo 1 đối tượng Parallax
	_backgroundElements = InfiniteParallaxNode::create();
	_backgroundElements->setPosition(origin.x, origin.y);

	_frontgroundElements = InfiniteParallaxNode::create();
	_frontgroundElements->setPosition(origin.x, origin.y);
	
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/10_Sky.png", 0, Vec2(0.07, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/09_Forest.png", 1, Vec2(0.1, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/08_Forest.png", 2, Vec2(0.15, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/07_Forest.png", 3, Vec2(0.2, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/06_Forest.png", 4, Vec2(0.3, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/05_Particles.png", 5, Vec2(0.35, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/04_Forest.png", 6, Vec2(0.45, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/mossy04.png", 5, Vec2(0.4, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/forest/Parallax Forest Background - Blue/mossy05.png", 3, Vec2(0.25, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/03_Particles.png", 1, Vec2(0.7, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/02_Bushes.png", 4, Vec2(0.9, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/01_Mist.png", 5, Vec2(0.9, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/mossy.png", 1, Vec2(0.6, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/mossy02.png", 3, Vec2(0.6, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/forest/Parallax Forest Background - Blue/mossy03.png", 0, Vec2(0.6, 1));
	
	addChild(_backgroundElements, -5);
	addChild(_frontgroundElements, 5);

	scheduleUpdate();

	return true;
}

bool CSceneGameplay::initEnemyMananager()
{
	_enemyManager = new CEnemyManager(_music, _hero);
	_enemyManager->setX(_x);
	_enemyManager->init();
	return true;
}

bool CSceneGameplay::initBtnPause()
{
 	auto itemPause = MenuItemImage::create(
		"ui/mybutton_pause_1.png",
		"ui/mybutton_pause_0.png",
		CC_CALLBACK_1(CSceneGameplay::pauseGame, this));
	itemPause->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
	itemPause->setScale(BTN_PAUSEGAME_RATIO);

	Vector<MenuItem*> vector;
	vector.pushBack(itemPause);
	_menuCtrl = Menu::createWithArray(vector);
	_menuCtrl->retain();
	_menuCtrl->setPosition(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 20);
	addChild(_menuCtrl);
	return true;
}

bool CSceneGameplay::initLayerOption()
{
	_layerOption = CLayerOption::createLayer();
	_layerOption->setName("LayerOption");
	_layerOption->setPosition(-5000, 0);
	addChild(_layerOption, 20);
	_layerOption->retain();
	return true;
}

bool CSceneGameplay::initHpBar()
{
	Vec2 pos = Vec2(origin.x + 5, origin.y + visibleSize.height);
	for (size_t i = 0; i < 10; i++)
	{
		auto hp = Sprite::create("ui/mybutton_heart_0.png");
		hp->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		hp->setPosition(pos);
		hp->setScale(HP_ICON_RATIO);
		pos += Vec2(hp->getContentSize().width*0.5f+1.0f, 0);
		hp->retain();
		addChild(hp, 6);
		_hpBar.pushBack(hp);
	}
	return true;
}

bool CSceneGameplay::initHeroCtr()
{
	switch (CC_TARGET_PLATFORM)
	{
	case CC_PLATFORM_ANDROID:
	case CC_PLATFORM_IOS:
		initHeroAndroidCtr();
		break;
	case CC_PLATFORM_WIN32:
		initHeroWin32Ctr();
		break;
	}
	return true;
}

bool CSceneGameplay::initHeroWin32Ctr()
{
	return _hero->initWin32Ctrl();
}

bool CSceneGameplay::initHeroAndroidCtr()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto line1 = origin.y + visibleSize.height*0.15;
	auto line2 = origin.y + visibleSize.height*0.4;

	auto itemAtk1 = ui::Button::create("ui/btn_atk/btn_atk_01.png", "ui/btn_atk/btn_atk_01.png", "ui/btn_atk/btn_atk_01.png");
	itemAtk1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN: 
			_hero->atk1();
			break;
		}
	});

	auto itemAtk2 = ui::Button::create("ui/btn_atk/btn_atk_02.png", "ui/btn_atk/btn_atk_02.png", "ui/btn_atk/btn_atk_02.png");
	itemAtk2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			_hero->atk2();
			break;
		}
		});

	auto itemAtk4 = ui::Button::create("ui/btn_atk/btn_atk_04.png", "ui/btn_atk/btn_atk_04.png", "ui/btn_atk/btn_atk_04.png");
	itemAtk4->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			_hero->atk4();
			break;
		}
	});

	auto itemAtk5 = ui::Button::create("ui/btn_atk/btn_atk_05.png", "ui/btn_atk/btn_atk_05.png", "ui/btn_atk/btn_atk_05.png");
	itemAtk5->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			_hero->atk5();
			break;
		}
	});

	itemAtk1->setPosition(origin + Vec2(visibleSize.width*0.15, line1));
	itemAtk2->setPosition(origin + Vec2(visibleSize.width*0.85, line1));
	itemAtk4->setPosition(origin + Vec2(visibleSize.width*0.05, line2));
	itemAtk5->setPosition(origin + Vec2(visibleSize.width*0.95, line2));

	itemAtk1->setScale(3);
	itemAtk2->setScale(3);
	itemAtk4->setScale(3);
	itemAtk5->setScale(3);

	itemAtk1->setOpacity(100);
	itemAtk2->setOpacity(100);
	itemAtk4->setOpacity(100);
	itemAtk5->setOpacity(100);


	addChild(itemAtk1, 10);
	addChild(itemAtk2, 10);
	addChild(itemAtk4, 10);
	addChild(itemAtk5, 10);

	return true;
}

void CSceneGameplay::updateHp(float dt)
{
	int hp = _hero->getHp();
	if (hp >= 0 && hp < 10 && pre_Hp != hp)
	{
		_hpBar.at(hp)->setTexture("ui/mybutton_heart_1.png");
		pre_Hp = hp;
	}
}

void CSceneGameplay::pauseGame(cocos2d::Ref *)
{
	if (!_music->_isDone) _music->pause();
	_layerOption->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
	Director::getInstance()->pause();
}

void CSceneGameplay::showScore()
{
	float percent = (float)_hero->_score / _enemyManager->_countMonster;
	std::string fileName = "ui/";
	if (percent >= 0.8f)
	{
		// 3 star
		fileName += "button_rock_greystar4.png";
	}
	else if (percent >= 0.5f)
	{
		// 2 star
		fileName += "button_rock_greystar3.png";
	}
	else
	{
		// 1 star
		fileName += "button_rock_greystar2.png";
	}
	auto sp = Sprite::create(fileName);
	sp->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	sp->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height);
	sp->setScale(0.5f);
	addChild(sp, 10);

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

