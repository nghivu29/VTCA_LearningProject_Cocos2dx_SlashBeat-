#pragma once
#include "cocos2d.h"

class CSceneSplash : cocos2d::Scene
{
	// các thuộc tính
protected:

	// các phương thức
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(CSceneSplash);

private:
	bool initIntro();
	void gotoSceneByTouch(cocos2d::Scene* scene);
	
};

