#include "CHero.h"
#include "proj.win32/resource.h"

USING_NS_CC;

CHero * CHero::createHero()
{
	return CHero::create();
}

bool CHero::init()
{
	if (!CActor::init())
		return false;
	return true;
}

bool CHero::loadResource()
{
	return true;
}




