#include "CMusicTest.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;


CMusicTest * CMusicTest::createMusic()
{
	return CMusicTest::create();
}



bool CMusicTest::init()
{
	_fileName = "res/audio/music/120BPMclicktrack.ogg.mp3";

	AudioEngine::preload(_fileName);
	_songBpm = 120.0f;
	_firstBeatOffset = 0.0f;
	_beatsPerLoop = 4.0f;

	if (!CMusic::init())
		return false;
	return true;
}
