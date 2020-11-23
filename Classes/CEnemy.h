#pragma once
#include "CObjDependOnMusic.h"
#include "CActor.h"


class CEnemy : public CActor, public CObjDependOnMusic
{
	// các thuộc tính
protected:
	CActor* _targetActor;

	// các phương thức
public:
	virtual bool init();
	CREATE_FUNC(CEnemy);

	// load resource chung cho các Enemy
	virtual bool loadResource();

	// up date status
	virtual void update(float dt);

	// setter
	void setTarget(CActor* targetActor);
};

