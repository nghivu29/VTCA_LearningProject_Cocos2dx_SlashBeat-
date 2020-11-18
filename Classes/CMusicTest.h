#pragma once
#include "CMusic.h"

class CMusicTest : public CMusic
{
public:
	static CMusicTest* createMusic();
	virtual bool init();
	CREATE_FUNC(CMusicTest);
};

