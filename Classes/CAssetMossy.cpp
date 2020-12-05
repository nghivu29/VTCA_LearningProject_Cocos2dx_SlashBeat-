#include "CAssetMossy.h"
#include "common.h"

USING_NS_CC;

CAssetMossy * CAssetMossy::createMossy()
{
	return CAssetMossy::create();
}

bool CAssetMossy::init()
{
	if (!Sprite::init())
		return false;
	loadData();
	setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	setScale(0.2f);
	return true;
}


void CAssetMossy::update(float dt)
{
}

bool CAssetMossy::loadData()
{
	auto cache = SpriteFrameCache::getInstance();
	if (cache->isSpriteFramesWithFileLoaded(MAP_TILE_MOSSY_PATH))
		return true;
	cache->addSpriteFramesWithFile(MAP_TILE_MOSSY_PATH);
	return true;
}

CAssetMossy * CAssetMossy::createMossy(const char* i)
{
	auto cache = SpriteFrameCache::getInstance();
	auto mossy = CAssetMossy::createMossy();
	auto s = StringUtils::format("tile0%s.png", i);
	mossy->setSpriteFrame(cache->getSpriteFrameByName(s));
	return mossy;
}
