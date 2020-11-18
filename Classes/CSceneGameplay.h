#pragma once
#include "cocos2d.h"
#include "proj.win32/resource.h"
#include "CHero.h"


class CSceneGameplay : public cocos2d::Scene
{
	// các thuộc tính
public:
	CHero* _hero;

	// các phương thức
public:
	// khởi tạo scene 
	static CSceneGameplay* createScene();
	// định nghĩa cho scene
	virtual bool init();

	// tải tài nguyên của màng chơi
	virtual bool loadResource();
	
	// Scene
	CREATE_FUNC(CSceneGameplay);

protected:
	virtual bool initHero();
};

