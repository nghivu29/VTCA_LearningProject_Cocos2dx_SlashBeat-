#include "CMusic_Soldiers.h"

CMusic_Soldiers * CMusic_Soldiers::createMusic()
{
	return CMusic_Soldiers::create();
}

bool CMusic_Soldiers::init()
{
	if (!CMusic::init())
		return false;

	/*_fileName = "res/audio/music/Otherwise_Soldiers.mp3";
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
	addChange(17, 0, 0, 3, 3);
	addChange(18, 3, 2, 0, 0);
	addChange(19, 0, 0, 0, 0);
	addChange(20, 2, 2, 2, 2);
	addChange(24, 2, 4, 4, 4);
	addChange(25, 1, 4, 4, 4);
	addChange(26, 3, 3, 3, 2);
	addChange(27, 2, 1, 1, 1);


	addChange(34, 3, 3, 3, 3);
	addChange(35, 0, 0, 0, 0);
	addChange(43, 2, 0, 2, 0);*/

	_fileName = "res/audio/music/ThroughTheFireAndFlames02.mp3";
	_bpm = 108.0f;
	_measures = 4;
	_beatDelay = 4;


	addChange(0, 2, 0, 0, 0);
	addChange(1, 0, 0, 0, 0);
	addChange(4, 1, 0, 2, 0);
	addChange(5, 0, 0, 0, 0);
	addChange(9, 2, 0, 0, 0);
	addChange(10, 0, 0, 0, 0);
	addChange(13, 2, 0, 0, 0);
	addChange(14, 0, 0, 0, 0);
	addChange(15, 0, 0, 1, 0);
	addChange(16, 2, 0, 1, 0);
	addChange(17, 0, 0, 0, 0);
	addChange(40, 2, 0, 0, 0);
	addChange(41, 0, 0, 0, 0);
	addChange(45, 2, 0, 0, 0);
	addChange(46, 0, 0, 0, 0);
	addChange(54, 2, 0, 0, 0);
	addChange(84, 0, 0, 0, 0);
	addChange(85, 0, 1, 1, 1);
	addChange(86, 1, 1, 1, 1);
	addChange(87, 2, 0, 0, 0);
	addChange(88, 0, 0, 0, 0);
	for (size_t i = 90; i < 103; i++)
	{
		if (i % 2) addChange(i, 1, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}
	addChange(103, 6, 0, 2, 0);
	addChange(104, 1, 0, 1, 1);
	addChange(105, 1, 1, 1, 1);
	addChange(106, 2, 0, 0, 0);
	addChange(107, 0, 0, 0, 0);
	for (size_t i = 109; i < 117; i++)
	{
		if (i % 2) addChange(i, 1, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}
	//addChange(109, 1, 0, 0, 0);
	for (size_t i = 117; i < 125; i++)
	{
		if (i % 2) addChange(i, 2, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}
	//addChange(117, 2, 0, 0, 0);
	for (size_t i = 125; i < 135; i++)
	{
		if (i % 2) addChange(i, 1, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}
	//addChange(127, 1, 0, 0, 0);
	
	addChange(135, 8, 0, 0, 0);
	addChange(136, 0, 0, 0, 0);
	addChange(137, 8, 0, 0, 0);
	addChange(138, 0, 0, 0, 0);
	addChange(139, 2, 0, 0, 0);
	addChange(140, 6, 6, 6, 6);
	addChange(141, 6, 6, 6, 6);
	addChange(142, 0, 0, 0, 0);

	for (size_t i = 144; i < 154; i++)
	{
		if (i % 2) addChange(i, 2, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}

	addChange(154, 1, 1, 1, 1);

	for (size_t i = 160; i <= 170; i++)
	{
		if (i % 2) addChange(i, 2, 0, 0, 0);
		else addChange(i, 0, 0, 0, 0);
	}

	addChange(173, 1, 0, 0, 0);
	addChange(174, 2, 0, 1, 0);
	addChange(175, 6, 0, 0, 0);
	addChange(176, 0, 0, 0, 0);
	
	addChange(182, 1, 0, 2, 0);
	addChange(189, 1, 2, 1, 2);
	addChange(211, 0, 0, 0, 0);
	


	

	


	SimpleAudioEngine::getInstance()->playBackgroundMusic(_fileName.c_str());
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	return true;
}
