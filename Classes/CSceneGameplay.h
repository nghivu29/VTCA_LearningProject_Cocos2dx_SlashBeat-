#pragma once
#include "cocos2d.h"
#include "proj.win32/resource.h"
#include "CHero.h"
#include "CMusicTest.h"
#include "CEnemyManager.h"

class CSceneGameplay : public cocos2d::Scene
{
	// các thuộc tính
protected:
	CHero* _hero;
	CMusic* _music;
	CEnemyManager* _enemyManager;

	cocos2d::Vec2 origin;
	cocos2d::Size visibleSize;

	// các phương thức
public:
	// khởi tạo scene 
	static CSceneGameplay* createScene();
	// định nghĩa cho scene
	virtual bool init();

	// tải tài nguyên của màng chơi
	virtual bool loadResource();

	// update
	virtual void update(float delta);
	
	// Scene
	CREATE_FUNC(CSceneGameplay);

protected:
	virtual bool initHero();
	virtual bool initBackground();
	virtual bool initEnemyMananager();
};

