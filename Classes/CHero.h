#pragma once
#include "CActor.h"

class CHero : public CActor
{
	// các phương thức
public:
	static CHero* createHero();
	virtual bool init();
	CREATE_FUNC(CHero);

	// loadresouce hero
	virtual bool loadResource();

private:
	virtual bool initWin32Ctrl();
};

