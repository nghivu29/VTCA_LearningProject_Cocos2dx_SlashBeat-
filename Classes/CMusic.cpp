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

	//finish call
	AudioEngine::setFinishCallback(_audioID, [&, this](int, const std::string&) 
		{
			_isDone = true;
		});


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


int CMusic::whichNote()
{

	if (_songPosition >= 0)
	{
		pre_songPosition = _songPosition;
		if (_notesChanges[(int)_completedLoops].size() != 0)
		{
			pre_completedLoops = (int)_completedLoops;
			return _notesChanges[(int)_completedLoops][(int)_loopPositionInBeats];
		}
		else
		{
			if (pre_completedLoops != -1000)
			{
				return _notesChanges[(int)pre_completedLoops][(int)_loopPositionInBeats];
			}
		}
	}
	return 0;
}

void CMusic::addNote(int songPositionInBeats,  ...)
{
	va_list ap;
	va_start(ap, songPositionInBeats);
	for (size_t i = 0; i < _beatsPerLoop; i++)
	{
		_notesChanges[songPositionInBeats].push_back(va_arg(ap, int));
	}
	va_end(ap);
}

float CMusic::getCurrentTime()
{
	return AudioEngine::getCurrentTime(_audioID);
}


