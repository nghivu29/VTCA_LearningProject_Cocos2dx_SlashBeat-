#include "CMusic.h"
#include "AudioEngine.h"


USING_NS_CC;

using namespace experimental;





void CMusic::StartMusic()
{
	//Start the music
	_audioID = AudioEngine::play2d(_fileName);

	//Record the time when the music starts
	_dspSongTime = AudioEngine::getCurrentTime(_audioID);

	// run update
	scheduleUpdate();
}

bool CMusic::init()
{
	if (!Node::init())
		return false;
	//Calculate the number of seconds in each beat
	_secPerBeat = 60.0f / _songBpm;
	return true;
}

void CMusic::update(float dt)
{
	_loopPositionInAnalog = _loopPositionInBeats / _beatsPerLoop;

	//determine how many seconds since the song started
	_songPosition = (float)(AudioEngine::getCurrentTime(_audioID) - _dspSongTime - _firstBeatOffset);

	//determine how many beats since the song started
	_songPositionInBeats = _songPosition / _secPerBeat;

	//calculate the loop position
	if (_songPositionInBeats >= (_completedLoops + 1) * _beatsPerLoop)
		_completedLoops++;
	_loopPositionInBeats = _songPositionInBeats - _completedLoops * _beatsPerLoop;

}

void CMusic::pause()
{
	AudioEngine::pause(_audioID);
}

void CMusic::resume()
{
	AudioEngine::resume(_audioID);
}

//int CMusic::hasNote()
//{
//	if (_notesChanges[_beatCurrent].size() != 0)
//	{
//		lastChangeFromBeat = _beatCurrent;
//		return _notesChanges[_beatCurrent][_measureCurrent];
//	}
//	else
//	{
//		if (lastChangeFromBeat != -1)
//		{
//			return _notesChanges[lastChangeFromBeat][_measureCurrent];
//		}
//	}
//	return 0;
//}
//
//// chưa nghĩ ra thuật toán
//bool CMusic::hasNote(int deltaFrame)
//{
//	
//	return false;
//}
//
//void CMusic::addChange(int beatStart,  ...)
//{
//	va_list ap;
//	va_start(ap, beatStart);
//	for (size_t i = 0; i < _measures; i++)
//	{
//		_notesChanges[beatStart].push_back(va_arg(ap, int));
//	}
//	va_end(ap);
//}


