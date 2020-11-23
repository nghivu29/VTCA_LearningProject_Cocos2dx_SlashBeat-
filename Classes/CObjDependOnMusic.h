#pragma once
#include "CMusic.h"

class CObjDependOnMusic
{
protected:
	CMusic* _music;

public:
	void setMusic(CMusic* music);
};
