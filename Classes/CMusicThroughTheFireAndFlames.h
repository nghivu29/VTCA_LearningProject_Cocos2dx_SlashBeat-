#pragma once
#include "CMusic.h"

class CMusicThroughTheFireAndFlames : public CMusic
{
public:
	static CMusicThroughTheFireAndFlames* createMusic();
	virtual bool init();
	CREATE_FUNC(CMusicThroughTheFireAndFlames);
};

