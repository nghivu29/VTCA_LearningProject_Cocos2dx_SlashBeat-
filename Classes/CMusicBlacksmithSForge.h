#pragma once
#include "CMusic.h"

class CMusicBlacksmithSForge : public CMusic
{
public:
	static CMusicBlacksmithSForge* createMusic();
	virtual bool init();
	CREATE_FUNC(CMusicBlacksmithSForge);
};

