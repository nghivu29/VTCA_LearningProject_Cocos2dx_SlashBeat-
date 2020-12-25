#include "CHero.h"
#include "common.h"

USING_NS_CC;

#define HERO_POS_UP Vec2(HERO_POS_X, GROUND2_POS_Y_RATIO*Director::getInstance()->getVisibleSize().height)
#define HERO_POS_DOWN Vec2(HERO_POS_X, GROUND1_POS_Y_RATIO*Director::getInstance()->getVisibleSize().height)

CHero * CHero::createHero()
{
	return CHero::create();
}

bool CHero::init()
{
	if (!CActor::init())
		return false;

	setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);

	scheduleUpdate();

	return true;
}

bool CHero::loadResource()
{
	return true;
}

void CHero::update(float dt)
{
	if (_hp <= 0 && lastStatus != DEAD)
	{
		dead();
		lastStatus = DEAD;
	}
}

bool CHero::initWin32Ctrl()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode k, cocos2d::Event*) {
		if (_status == DEAD)
			return false;
		
		
		switch (k)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_7:
			idle2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_8:
			run2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_2:
			if (getPosition() == HERO_POS_UP)
			{
				runTeleEffect();
				setPosition(HERO_POS_DOWN);
				runAfterTeleEffect();
			}
			attack1();
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_1:
			if (getPosition() == HERO_POS_UP)
			{
				runTeleEffect();
				setPosition(HERO_POS_DOWN);
				runAfterTeleEffect();
			}
			attack2();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_5:
			_frameFly = 0;
			if (getPosition() == HERO_POS_DOWN)
			{
				runTeleEffect();
				setPosition(HERO_POS_UP);
				runAfterTeleEffect();
			}
			attack1();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_4:
			_frameFly = 0;
			if (getPosition() == HERO_POS_DOWN)
			{
				runTeleEffect();
				setPosition(HERO_POS_UP);
				runAfterTeleEffect();
			}
			attack2();
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}


bool CHero::initAndroidCtrl()
{
	center_scene = Vec2
	(
		Director::getInstance()->getVisibleOrigin().x + Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleOrigin().y + Director::getInstance()->getVisibleSize().height / 2
	);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* t, Event*)
	{
		if (_status == DEAD)
			return false;

		if (t->getLocation().y > center_scene.y)
		{
			_frameFly = 0;
			if (t->getLocation().x > center_scene.x)
			{
				if (getPosition() == HERO_POS_DOWN)
				{
					runTeleEffect();
					setPosition(HERO_POS_UP);
					runAfterTeleEffect();
				}
				attack1();
			}
			else
			{
				if (getPosition() == HERO_POS_DOWN)
				{
					runTeleEffect();
					setPosition(HERO_POS_UP);
					runAfterTeleEffect();
				}
				attack2();
			}
		}
		else
		{
			if (t->getLocation().x > center_scene.x)
			{
				if (getPosition() == HERO_POS_UP)
				{
					runTeleEffect();
					setPosition(HERO_POS_DOWN);
					runAfterTeleEffect();
				}
				attack1();
			}
			else
			{
				if (getPosition() == HERO_POS_UP)
				{
					runTeleEffect();
					setPosition(HERO_POS_DOWN);
					runAfterTeleEffect();
				}
				attack2();
			}
		}


		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}


void CHero::runTeleEffect()
{
	auto scene = Director::getInstance()->getRunningScene();
	Sprite* duAnh;
	duAnh = Sprite::createWithSpriteFrame(this->getDisplayFrame());
	duAnh->setColor(Color3B::BLACK);
	duAnh->setOpacity(50);
	duAnh->setScale(this->getScale());
	duAnh->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	duAnh->setPosition(this->getPosition());
	scene->addChild(duAnh);
	duAnh->runAction(MoveBy::create(0.2, Vec2(-100, 10)));
	duAnh->runAction(FadeOut::create(0.3));
	duAnh->runAction(ScaleBy::create(0.3, 0.9));
	duAnh->runAction(Sequence::create(DelayTime::create(0.6), RemoveSelf::create(), nullptr));



	auto duAnh2 = Sprite::createWithSpriteFrame(duAnh->getDisplayFrame());
	duAnh2->setColor(Color3B::BLACK);
	duAnh2->setOpacity(70);
	duAnh2->setScale(this->getScale());
	duAnh2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	duAnh2->setPosition(this->getPosition());
	scene->addChild(duAnh2);
	duAnh2->runAction(MoveBy::create(0.3, Vec2(-70, -10)));
	duAnh2->runAction(FadeOut::create(0.6));
	duAnh2->runAction(ScaleBy::create(0.6, 1.1));
	duAnh2->runAction(Sequence::create(DelayTime::create(0.6), RemoveSelf::create(), nullptr));



}

void CHero::runAfterTeleEffect()
{
	auto scene = Director::getInstance()->getRunningScene();
	Sprite* duAnh;
	duAnh = Sprite::createWithSpriteFrame(this->getDisplayFrame());
	duAnh->setScale(this->getScale()*1.05f);
	duAnh->setColor(Color3B::BLACK);
	duAnh->setOpacity(200);
	duAnh->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	duAnh->setPosition(this->getPosition()-Vec2(30, 0));
	scene->addChild(duAnh, 1);
	duAnh->runAction(MoveTo::create(0.5, this->getPosition()));
	duAnh->runAction(ScaleTo::create(0.2, this->getScale()));
	duAnh->runAction(FadeOut::create(0.2));
	duAnh->runAction(Sequence::create(DelayTime::create(0.2f), RemoveSelf::create(), nullptr));

}

void CHero::hit()
{
	CActor::hit();
	_combo = 0;
}

void CHero::comboEffect1()
{
	Sprite* duAnh;
	duAnh = Sprite::createWithSpriteFrame(this->getDisplayFrame());
	duAnh->setColor(Color3B::BLUE);
	duAnh->setOpacity(60);
	duAnh->setScale(1.2f);
	duAnh->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	duAnh->setPosition(0, 0);
	addChild(duAnh, -1);
	duAnh->runAction(FadeOut::create(0.3));
	duAnh->runAction(Sequence::create(DelayTime::create(0.6), RemoveSelf::create(), nullptr));
}

void CHero::atk1()
{
	if (_status == DEAD)
		return;

	if (getPosition() == HERO_POS_UP)
	{
		runTeleEffect();
		setPosition(HERO_POS_DOWN);
		runAfterTeleEffect();
	}
	attack2();
}

void CHero::atk2()
{
	if (_status == DEAD)
		return;

	if (getPosition() == HERO_POS_UP)
	{
		runTeleEffect();
		setPosition(HERO_POS_DOWN);
		runAfterTeleEffect();
	}
	attack1();
}

void CHero::atk4()
{
	if (_status == DEAD)
		return;

	if (getPosition() == HERO_POS_DOWN)
	{
		runTeleEffect();
		setPosition(HERO_POS_UP);
		runAfterTeleEffect();
	}
	attack2();
}

void CHero::atk5()
{
	if (_status == DEAD)
		return;

	if (getPosition() == HERO_POS_DOWN)
	{
		runTeleEffect();
		setPosition(HERO_POS_UP);
		runAfterTeleEffect();
	}
	attack1();
}





