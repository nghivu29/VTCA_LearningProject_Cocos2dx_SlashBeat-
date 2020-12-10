#pragma once
#include "cocos2d.h"

class CLayerOption : public cocos2d::Layer
{
private:
	cocos2d::Menu* _menu;
	int _musicID;

public:
	static CLayerOption* createLayer();
	virtual bool init();
	CREATE_FUNC(CLayerOption);

	void playContinue(cocos2d::Ref*);
	void backScene(cocos2d::Ref*);
	void playAgain(cocos2d::Ref*);
	
	void setMusicID(int id);
};

