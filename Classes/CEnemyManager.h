#pragma once
#include "CMusic.h"
#include "CEnemy.h"

class CEnemyManager
{
private:
	CMusic* _music;
	CActor* _target;

	// độ lệch khoảng cách khi quái di chuyển đến mục tiêu trong 1 beat
	float _detalRange = 0;

	//The distance enemy start
	float _distanceEnemyRun;

	//The among of time enemy go to target
	float _timeEnemyRun;

	//thời gian đó gấp mấy lần _serPerBeat
	int x;

	// beat gần nhất
	int h_mostRecentBeat = -100;

	// boss
	CEnemy* _boss;

public:
	virtual void updateEnemies(float dt);
	CEnemy* createMonster(int enemyName, CActor* target);
	virtual bool init();

	void bossScript1(CEnemy* enemy);

	// setter
	void setMusic(CMusic* music);
	void setTarget(CActor* target);
	void setDetalRange(float dt);
	void setX(int x);

	// getter
	float getDetalRange();
	
	// constructor
	CEnemyManager(CMusic* music, CActor* target);


	// debug log
	void logSongPosition();

	// help
	float helpChaseTarget(float targetPosY);
};

