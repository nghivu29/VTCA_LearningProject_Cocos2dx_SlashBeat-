#pragma once
#include "CObjDependOnMusic.h"
#include "CActor.h"


class CEnemy : public CActor, public CObjDependOnMusic
{
	// các thuộc tính
protected:
	cocos2d::Sprite* _spTarget;

	// các phương thức
public:
	virtual bool init();
	CREATE_FUNC(CEnemy);

	// load resource chung cho các Enemy
	virtual bool loadResource();

	// up date status
	virtual void update(float dt);
};

