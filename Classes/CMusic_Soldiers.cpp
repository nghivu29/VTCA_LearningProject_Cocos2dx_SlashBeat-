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
	addChange(1, false, true, true, true);
	addChange(2, true, true, true, true);
	addChange(35, false, false, false, false);
	addChange(43, true, true, true, true);

	return true;
}
