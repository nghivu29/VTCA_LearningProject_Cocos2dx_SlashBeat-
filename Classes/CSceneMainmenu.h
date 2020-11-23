#pragma once
#include "cocos2d.h"

class CSceneMainmenu : public cocos2d::Scene
{
private:
	cocos2d::Menu* _menu;
	cocos2d::MenuItem* _itemPauseGame;
	cocos2d::MenuItem* _itemExitGame;

public:
	static CSceneMainmenu* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneMainmenu);

	void startGame(cocos2d::Ref*);
	void exit(cocos2d::Ref*);
};

