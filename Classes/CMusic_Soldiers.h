#pragma once
#include "CMusic.h"

class CMusic_Soldiers : public CMusic
{
public:
	static CMusic_Soldiers* createMusic();
	virtual bool init();
	CREATE_FUNC(CMusic_Soldiers);
};

