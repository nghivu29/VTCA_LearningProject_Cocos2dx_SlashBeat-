#pragma once
#include "cocos2d.h"


enum EMusic
{
	TEST,
	BLACKSMITH_S_FORGE,
	THROUGHTHEFIREANDFLAMES,
	UNITY
};

class CMusic : public cocos2d::Node
{
public:
	// tên file.mp3
	std::string _fileName;

	//Song beats per minute
//This is determined by the song you're trying to sync up to
	float _songBpm;

	//The number of seconds for each song beat
	float _secPerBeat;

	//Current song position, in seconds
	float _songPosition;

	//Current song position, in beats
	float _songPositionInBeats;

	//How many seconds have passed since the song started
	float _dspSongTime;

	//id of audio.
	int _audioID;

	//The offset to the first beat of the song in seconds
	float _firstBeatOffset;

	// Looping
		//the number of beats in each loop
	float _beatsPerLoop;

	//the total number of loops completed since the looping clip first started
	int _completedLoops = 0;

	//The current position of the song within the loop in beats.
	float _loopPositionInBeats;


	//The current relative position of the song within the loop measured between 0 and 1.
	float _loopPositionInAnalog;

	// bai nhac hoan thanh hay chua
	bool _isDone = false;

	// mảng đánh dấu
	std::map < int, std::vector<int> > _notesChanges;

	// các biến hỗ trợ tính toán
	int pre_completedLoops = -1000;
	float pre_songPosition = 0;

	


public:
	// phát nhạc
	virtual void StartMusic();

	// định nghĩa cho nhạc
	virtual bool init();

	// update thuộc tính theo từng frame
	void update(float dt);

	void pause();

	void resume();


	// loại nhịp nào ( tạo kẻ thù tùy vào kết quả này )
	int whichNote();

	// đánh dấu các mốc thay đổi việc đánh phách. số lượng biến trong va_list = _measures
	void addNote(int songPositionInBeats, ...);

	float getCurrentTime();
};
