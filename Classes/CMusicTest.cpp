#include "CMusicTest.h"

CMusicTest * CMusicTest::createMusic()
{
	return CMusicTest::create();
}

bool CMusicTest::init()
{
	if (!CMusic::init())
		return false;

	_fileName = "res/audio/music/120BPMclicktrack.ogg.mp3";
	_bpm = 120.0f;
	_measures = 4;
	addChange(2, true, false, false, false);
	addChange(5, true, true, false, true);
	addChange(7, false, false, false, false);
	addChange(10, true, true, true, true);

	return true;
}
