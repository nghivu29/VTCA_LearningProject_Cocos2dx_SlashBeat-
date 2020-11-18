#include "CActor.h"

USING_NS_CC;

bool CActor::init()
{
	if (!Sprite::init())
		return false;
	if (!(loadResource() && CAnimateActor::initAnimate()))
		return false;
	return true;
}

bool CActor::loadResource()
{
	return true;
}


