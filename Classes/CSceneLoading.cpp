#include "CSceneLoading.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

CSceneLoading * CSceneLoading::createScene()
{
	return CSceneLoading::create();
}

bool CSceneLoading::init()
{
	if (!Scene::init())
		return false;

	auto loadingBar = ui::LoadingBar::create("LoadingBarFile.png");
	loadingBar->setDirection(ui::LoadingBar::Direction::RIGHT);

	// something happened, change the percentage of the loading bar
	loadingBar->setPercent(25);

	// more things happened, change the percentage again.
	loadingBar->setPercent(35);

	this->addChild(loadingBar);

	return true;
}
