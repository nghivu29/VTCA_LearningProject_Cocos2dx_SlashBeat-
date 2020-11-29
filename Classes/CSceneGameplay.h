#pragma once
#include "cocos2d.h"
#include "common.h"
#include "CHero.h"
#include "CMusicTest.h"
#include "CEnemyManager.h"
#include "CLayerOption.h"
#include "InfiniteParallaxNode.h"

class CSceneGameplay : public cocos2d::Scene
{
	// các thuộc tính
protected:
	CHero* _hero;
	CMusic* _music;
	CEnemyManager* _enemyManager;

	cocos2d::Menu* _menuCtrl;
	CLayerOption* _layerOption;
	cocos2d::ParallaxNode* paraBg;
	cocos2d::ParallaxNode* paraBg2;
	InfiniteParallaxNode* _backgroundElements;
	InfiniteParallaxNode* _frontgroundElements;

	cocos2d::Vec2 origin;
	cocos2d::Size visibleSize;
	int _frameHeroFly = 0;

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
	virtual bool initBtnPause();
	virtual bool initLayerOption();

	void pauseGame(cocos2d::Ref*);

	void helpInitParallaxLayer(InfiniteParallaxNode* parallax, const std::string &fileName, int z, cocos2d::Vec2 ratio, float distance = 0);
};

