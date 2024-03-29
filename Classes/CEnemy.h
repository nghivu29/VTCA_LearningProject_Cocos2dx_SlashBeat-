﻿#pragma once
#include "CObjDependOnMusic.h"
#include "CActor.h"

enum EEnemyType
{
	SOFT,
	HARD
};

enum EEnemy
{
	NOPE,
	SPHERICAL_MONSTER_1,
	SPHERICAL_MONSTER_2,
	ROCK_MONSTER_1,
	ROCK_MONSTER_2,
	SPHERICAL_MONSTER_FLAPPY_1,
	SPHERICAL_MONSTER_FLAPPY_2,
	SKULL_MONSTER_1,
	SKULL_MONSTER_2,
	FIRE_1,
	FIRE_2,
	BOSS0,
	ENEMY_FROM_BOSS0
};

class CEnemy : public CActor, public CObjDependOnMusic
{
	// các thuộc tính
protected:
	// mục tiêu tấn công của quái
	CActor* _targetActor;
	// loại quái cứng phải dùng khiên để phá, loại quái mềm dùng kiếm chém
	EEnemyType _type;
	// tên chủng loài của quái, dùng để tạo đúng quái đúng thời điểm ở thuộc tính map trong lớp CMusic
	EEnemy _enemyName;

public:
	cocos2d::ParticleSystem* _effect;
	float _lifeTime;


	// các phương thức
public:
	virtual bool init();
	CREATE_FUNC(CEnemy);

	// load resource chung cho các Enemy
	virtual bool loadResource();

	// up date status
	virtual void update(float dt);

	//
	virtual void hit();

	// setter
	void setTarget(CActor* targetActor);
	void setType(EEnemyType type);
	void setName(EEnemy name);

	// getter
	EEnemy getName();
	EEnemyType getType();
};

