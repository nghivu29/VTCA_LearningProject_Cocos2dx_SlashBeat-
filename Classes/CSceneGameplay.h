#pragma once
#include "cocos2d.h"
#include "common.h"
#include "CHero.h"
#include "CMusic.h"
#include "CEnemyManager.h"
#include "CLayerOption.h"
#include "InfiniteParallaxNode.h"

class CSceneGameplay : public cocos2d::Scene
{
	// các thuộc tính
protected:
	int _gameStatus;
	CHero* _hero;
	CMusic* _music;
	CEnemyManager* _enemyManager;
	bool _isPlayMusic = false;

	// bien dung de test
	cocos2d::Label* _test;

	cocos2d::Menu* _menuCtrl;
	CLayerOption* _layerOption;
	cocos2d::ParallaxNode* paraBg;
	cocos2d::ParallaxNode* paraBg2;
	InfiniteParallaxNode* _backgroundElements;
	InfiniteParallaxNode* _frontgroundElements;

//các thuộc tính dùng đẻ tùy chỉnh màng chơi

	// chỉnh tốc độ di chuyển của enemy ( x càng lớn enemy đi càng chậm )
	int _x = 2;

	// chỉnh tốc độ của backround (_bgSpeed càng lớn càng nhanh )
	float _bgSpeed = 14;

	// chinh toc do chay cua hero;
	float _heroRunSpeed;

	// chọn bg music ( tạo hàm switch case )
	int _musicID = 1;



	// chọn hero
	int _heroID;

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
	virtual bool initMusic();
	virtual bool initHero();
	virtual bool initBackground();
	virtual bool initEnemyMananager();
	virtual bool initBtnPause();
	virtual bool initLayerOption();

	void pauseGame(cocos2d::Ref*);

	void helpInitParallaxLayer(InfiniteParallaxNode* parallax, const std::string &fileName, int z, cocos2d::Vec2 ratio, float distance = 0);

};

