#include "Common.h"
#include "BaseScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool BaseScene::init()
{
	// Init parent class
	if ( ! Layer::init() ) return false;

	// Get the current dimensions of the screen
	visibleOrigin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	// Done
	return true;
}

void BaseScene::menuCloseCallback(Ref* pSender)
{
	auto config = UserDefault::getInstance();
	bool old = config->getBoolForKey("System/FullScreen", false);
	config->setBoolForKey("System/FullScreen", ! old);
	config->flush();
	Director::getInstance()->end();
}
