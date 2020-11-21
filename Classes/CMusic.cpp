#include "CMusic.h"

USING_NS_CC;

void CMusic::playMusic()
{
	f = (_fps*_bpm) / (60 * _measures);
	if (!_fileName.empty()) {
		resetMusic();
		SimpleAudioEngine::getInstance()->playBackgroundMusic(_fileName.c_str());
		schedule(schedule_selector(CMusic::update), 1/_fps);
		//scheduleUpdate();
	}
}

void CMusic::resetMusic()
{
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	_frameCurrent = 0;
	_measureCurrent = 0;
	_beatCurrent = 0;
}

bool CMusic::hasNote()
{
	if (_notesChanges[_beatCurrent].size() != 0)
	{
		lastChangeFromBeat = _beatCurrent;
		return _notesChanges[_beatCurrent][_measureCurrent];
	}
	else
	{
		if (lastChangeFromBeat != -1)
		{
			return _notesChanges[lastChangeFromBeat][_measureCurrent];
		}
	}
	return false;
}

// chưa nghĩ ra thuật toán
bool CMusic::hasNote(int deltaFrame)
{
	
	return false;
}

void CMusic::addChange(int beatStart, bool measure1 ...)
{
	va_list ap;
	va_start(ap, beatStart);
	for (size_t i = 0; i < _measures; i++)
	{
		_notesChanges[beatStart].push_back(va_arg(ap, bool));
	}
	va_end(ap);
}


bool CMusic::init()
{
	if (!Node::init())
		return false;

	_fileName = "";
	_bpm = 0;
	_fps = 60.0f;
	_measures = 0;
	resetMusic();

	return true;
}

void CMusic::update(float dt)
{
	_frameCurrent++;
	count++;
	if (count > f) {
		count = 1;
		_measureCurrent++;
		if (_measureCurrent >= _measures)
		{
			_measureCurrent = 0;
			_beatCurrent++;
		}
	}
}

std::string CMusic::getFileName()
{
	return _fileName;
}

float CMusic::getBpm()
{
	return _bpm;
}

float CMusic::getFps()
{
	return _fps;
}

int CMusic::getFrameCurrent()
{
	return _frameCurrent;
}

int CMusic::getMeasures()
{
	return _measures;
}

int CMusic::getMeasureCurrent()
{
	return _measureCurrent;
}

int CMusic::getBeatCurrent()
{
	return _beatCurrent;
}

void CMusic::logNotesChanges()
{
	std::string str = "";
	for (auto i = _notesChanges.begin(); i != _notesChanges.end() ; i++)
	{
		for (size_t j = 0; j < _measures; j++)
		{
			str += StringUtils::format("%d|%s ", j, (*i).second.at(j) ? "true":"false" );
		}
		log("beat %d: %s", (*i).first, str);
		str = "";
	}
}

float CMusic::getFramePerBeat()
{
	return f*_measures;
}


