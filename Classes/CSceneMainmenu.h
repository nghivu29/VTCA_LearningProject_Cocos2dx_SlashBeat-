#pragma once
#include "cocos2d.h"

class CSceneMainmenu : public cocos2d::Scene
{
private:
	cocos2d::Menu* _menu;
	cocos2d::MenuItem* _itemPlayGame;
	cocos2d::MenuItem* _itemExitGame;

public:
	static CSceneMainmenu* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneMainmenu);

	void startGame(cocos2d::Ref*);
	void exit(cocos2d::Ref*);

protected:
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	virtual bool initBg();
	virtual bool initMenu();
};
