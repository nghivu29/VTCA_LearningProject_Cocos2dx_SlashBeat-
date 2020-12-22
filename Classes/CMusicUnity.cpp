#include "CMusicUnity.h"
#include "AudioEngine.h"
#include "CEnemy.h"

USING_NS_CC;
using namespace experimental;


CMusicUnity * CMusicUnity::createMusic()
{
	return CMusicUnity::create();
}

bool CMusicUnity::init()
{
	_fileName = "res/audio/music/Unity - TheFatRat.mp3";

	AudioEngine::preload(_fileName);
	_songBpm = 210.0f;
	_firstBeatOffset = 0.0f;
	_beatsPerLoop = 4.0f;

	addNote(0, BOSS0, 0, 0, 0);
	addNote(1, 0, 0, 0, 0);
	addNote(5, FIRE_2, 0, 0, 0);
	addNote(6, 1, 0, 0, 0);
	addNote(21, 1, 0, 6, 0);
	addNote(36, 8, 8, 8, 8);
	addNote(37, 8, 0, 0, 0);
	addNote(38, 3, 0, 8, 0);
	addNote(68, 6, 6, 6, 6);
	addNote(69, 6, 0, FIRE_1, 0);
	addNote(70, 3, 0, ENEMY_FROM_BOSS0, 0);
	addNote(101, FIRE_2, 0, 0, 0);
	addNote(102, 0, 0, 0, 0);


	
	//addNote(53, 3, 0, 8, 0);




	if (!CMusic::init())
		return false;
	return true;
}
