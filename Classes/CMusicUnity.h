#pragma once
#include "CMusic.h"

class CMusicUnity : public CMusic
{
public:
	static CMusicUnity* createMusic();
	virtual bool init();
	CREATE_FUNC(CMusicUnity);
};

