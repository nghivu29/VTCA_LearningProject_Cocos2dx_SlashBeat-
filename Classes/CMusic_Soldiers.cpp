#include "CMusic_Soldiers.h"

CMusic_Soldiers * CMusic_Soldiers::createMusic()
{
	return CMusic_Soldiers::create();
}

bool CMusic_Soldiers::init()
{
	if (!CMusic::init())
		return false;

	_fileName = "res/audio/music/Otherwise_Soldiers.mp3";
	_bpm = 117.0f;
	_measures = 4;
	addChange(1, 0, 0, 1, 0);
	addChange(2, 0, 0, 1, 0);
	addChange(3, 0, 0, 2, 0);
	addChange(4, 0, 0, 1, 0);
	addChange(5, 0, 0, 2, 0);
	addChange(6, 1, 1, 1, 1);
	addChange(8, 1, 1, 2, 1);
	addChange(9, 3, 3, 3, 2);
	addChange(10, 0, 0, 0, 0);
	addChange(12, 2, 0, 0, 0);
	addChange(14, 0, 2, 0, 0);
	addChange(17, 0, 0, 0, 3);
	addChange(18, 3, 3, 2, 0);
	addChange(19, 0, 0, 0, 0);
	addChange(20, 1, 1, 1, 1);

	//addChange(14, 1, 0, 0, 0);
	addChange(35, 0, 0, 0, 0);
	addChange(43, 2, 1, 2, 1);

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(_fileName.c_str());
	return true;
}
