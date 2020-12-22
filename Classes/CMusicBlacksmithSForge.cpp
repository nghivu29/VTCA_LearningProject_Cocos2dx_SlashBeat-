#include "CMusicBlacksmithSForge.h"

#include "AudioEngine.h"
#include "CEnemy.h"

USING_NS_CC;
using namespace experimental;


CMusicBlacksmithSForge * CMusicBlacksmithSForge::createMusic()
{
	return CMusicBlacksmithSForge::create();
}

bool CMusicBlacksmithSForge::init()
{

	_fileName = "res/audio/music/We_ll Meet Again - TheFatRat.mp3";

	AudioEngine::preload(_fileName);
	_songBpm = 384.0f;
	_firstBeatOffset = 0.0f;
	_beatsPerLoop = 8.0f;
	
	
	addNote(0, 1, 1, 1, 0, 0, 0, 0, 0);
	addNote(6, 1, 0, 0, 0, 1, 0, 0, 0);

	// ver 1
	addNote(8, 1, 1, 1, 0, 3, 0, 0, 0);
	addNote(14, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(16, 1, 1, 1, 0, 3, 0, 0, 0);
	addNote(22, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(24, 6, 0, 6, 0, 6, 0, 6, 0);
	addNote(32, 5, 0, 5, 0, 5, 0, 5, 0);
	addNote(39, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(40, 3, 0, 0, 6, 6, 0, 0, 0);
	addNote(54, 3, 0, 0, 0, 3, 0, 0, 0);

	//ver 2
	addNote(56, 7, 0, 0, 0, 6, 0, 0, 0);
	addNote(62, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(64, 7, 0, 0, 0, 6, 0, 0, 0);
	addNote(70, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(72, 6, 0, 6, 0, 6, 0, 6, 0);
	addNote(80, 5, 0, 5, 0, 5, 0, 5, 0);
	addNote(87, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(88, 7, 0, 0, 6, 6, 0, 0, 0);
	addNote(94, 3, 0, 0, 3, 0, 0, 0, 0);
	addNote(96, 7, 0, 0, 6, 6, 0, 0, 0);
	addNote(102, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(103, 3, 0, 0, 0, 3, 0, 0, FIRE_2);


	//
	addNote(104, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(111, 0, 0, 0, 0, 0, 0, 0, FIRE_2);
	addNote(112, 3, 0, 0, 0, 0, 7, 0, 7);
	addNote(113, 0, 0, 0, 0, 0, 7, 0, 7);
	addNote(119, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(120, 1, 0, 0, 0, 0, 0, 0, 0);
	addNote(127, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(128, 2, 0, 0, 0, 0, 0, 0, 0);
	addNote(135, 0, 0, 0, 0, 0, 0, 0, 0);
	addNote(136, 7, 0, 0, 6, 6, 0, 0, 0);
	addNote(142, 3, 0, 0, 3, 0, 0, 0, 0);
	addNote(144, 7, 0, 0, 6, 6, 0, 0, 0);
	addNote(150, 3, 0, 0, 0, 3, 0, 0, 0);
	addNote(151, 3, 0, 0, 0, 3, 0, 0, FIRE_2);
	addNote(152, 0, 0, 0, 0, 0, 0, 0, 0);


	

	if (!CMusic::init())
		return false;
	return true;
}
