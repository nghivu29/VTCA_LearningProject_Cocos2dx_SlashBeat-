#include "CSceneTutorial.h"

USING_NS_CC;

CSceneTutorial * CSceneTutorial::createScene()
{
	return CSceneTutorial::create();
}

bool CSceneTutorial::init()
{
	_x = 8;
	_bgSpeed = 5.0f;
	_heroRunSpeed = 0.5f;
	_musicID = 1;

	if (!CSceneGameplay::init())
		return false;

	setTag(0);
	_enemyManager->_fireLifeTime = 5.0f;

	return true;
}

bool CSceneTutorial::initBackground()
{
	// Ảnh Background

	// Tạo 1 đối tượng Parallax
	_backgroundElements = InfiniteParallaxNode::create();
	_backgroundElements->setPosition(origin.x, origin.y);

	_frontgroundElements = InfiniteParallaxNode::create();
	_frontgroundElements->setPosition(origin.x, origin.y);

	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/01_Sky.png", 0, Vec2(0.1, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/02_Stars.png", 1, Vec2(0.2, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/03_Moon.png", 2, Vec2(0.3, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/04_Cloud.png", 3, Vec2(0.4, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/05_Cloud.png", 4, Vec2(0.5, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/06_Cloud.png", 5, Vec2(0.6, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/07_Cloud.png", 6, Vec2(0.7, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/08_Cloud.png", 7, Vec2(0.8, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/09_Cloudsmall.png", 8, Vec2(0.9, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/10_Cloudsmall.png", 9, Vec2(1.0, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/11_Mountains.png", 10, Vec2(1.1, 1));
	helpInitParallaxLayer(_backgroundElements, "res/bg/desert/12_Desert.png", 11, Vec2(1.2, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/desert/mossy02.png", 0, Vec2(1.3, 1));
	helpInitParallaxLayer(_frontgroundElements, "res/bg/desert/mossy.png", 1, Vec2(1.4, 1));

	addChild(_backgroundElements, -5);
	addChild(_frontgroundElements, 5);

	auto effect = CCParticleSystemQuad::create("effect/particle_texture2.plist");
	effect->setPosition(origin.x + visibleSize.width, origin.y + visibleSize.height*0.1);
	addChild(effect, 10);

	showTutorial();

	return true;
}

void CSceneTutorial::showTutorial()
{
	_imgTutorial = Sprite::create("tutorial.png");
	_imgTutorial->setScale(0.6 * (visibleSize.width / _imgTutorial->getContentSize().width, visibleSize.height / _imgTutorial->getContentSize().height));
	_imgTutorial->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(_imgTutorial, 15);

	_imgTutorial->runAction(Sequence::create
	(
		CallFunc::create([this]() {this->unscheduleUpdate(); }),
		DelayTime::create(7), FadeOut::create(2), 
		CallFunc::create([this]() {this->scheduleUpdate(); }),
		nullptr)
	);
}
