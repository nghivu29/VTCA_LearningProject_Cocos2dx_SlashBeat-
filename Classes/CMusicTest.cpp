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
	addChange(0, 2, 1, 1, 1);
	/*addChange(7, false, false, false, false);
	addChange(10, true, false, false, true);
	addChange(15, false, false, true, true);*/

	return true;
}
