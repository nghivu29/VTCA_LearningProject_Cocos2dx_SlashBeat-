#include "CMusicBlacksmithSForge.h"

#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;


CMusicBlacksmithSForge * CMusicBlacksmithSForge::createMusic()
{
	return CMusicBlacksmithSForge::create();
}

bool CMusicBlacksmithSForge::init()
{
	/*
	_x = 2;
	_musicID = 1;
	_bgSpeed = 14;
	*/

	_fileName = "res/audio/music/Blacksmith's Forge.mp3";

	AudioEngine::preload(_fileName);
	_songBpm = 47.5f;
	_firstBeatOffset = 5.2f;
	_beatsPerLoop = 2.0f;

	addNote(1, 1, 1);
	addNote(7, 2, 2);
	addNote(15, 4, 4);
	addNote(23, 5, 5);
	addNote(31, 4, 4);
	addNote(39, 0, 0);
	

	if (!CMusic::init())
		return false;
	return true;
}
