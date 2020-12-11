#include "CMusicThroughTheFireAndFlames.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

CMusicThroughTheFireAndFlames * CMusicThroughTheFireAndFlames::createMusic()
{
	return CMusicThroughTheFireAndFlames::create();
}

bool CMusicThroughTheFireAndFlames::init()
{
	/*
	_x = ;
	_musicID = ;
	_bgSpeed = 0;
	*/

	_fileName = "res/audio/music/ThroughTheFireAndFlames02.mp3";

	AudioEngine::preload(_fileName);
	_songBpm = 200.0f;
	_firstBeatOffset = 18.4f;
	_beatsPerLoop = 4.0f;

	addNote(1, 1, 0, 0, 0);
	addNote(5, 0, 0, 0, 0);
	addNote(9, 1, 0, 0, 0);
	addNote(13, 0, 0, 0, 0);
	addNote(17, 1, 0, 0, 0);
	addNote(21, 0, 0, 0, 0);
	addNote(29, 1, 1, 1, 1);
	addNote(37, 0, 0, 0, 0);
	addNote(41, 8, 0, 0, 0);
	addNote(67, 6, 0, 0, 0);
	addNote(85, 6, 0, 6, 0);
	addNote(89, 6, 6, 6, 6);
	addNote(98, 4, 0, 0, 0);

	



	if (!CMusic::init())
		return false;
	return true;
}
