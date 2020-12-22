#pragma once

#include "cocos2d.h"

class CLayerSelectScreenPlay : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CLayerSelectScreenPlay);

	void gotoScreen1Callback(cocos2d::Ref* pSender);
	void gotoScreen2Callback(cocos2d::Ref* pSender);
	void gotoScreen3Callback(cocos2d::Ref* pSender);
	void backSceneCallback(cocos2d::Ref* pSender);



protected:
	virtual bool initBg();
};

