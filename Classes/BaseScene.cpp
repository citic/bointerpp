#include "Common.h"
#include "BaseScene.h"

USING_NS_CC;

#include <cstdio>

// on "init" you need to initialize your instance
bool BaseScene::init()
{
	// Init parent class
	if ( ! Layer::init() ) return false;

	// Get the current dimensions of the screen
	visibleOrigin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

#if COCOS2D_DEBUG
	fprintf(stdout,"Visible: origin = (%.2f, %.2f) size = (%.2f, %.2f)\n"
		, visibleOrigin.x, visibleOrigin.y, visibleSize.width, visibleSize.height);
#endif

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
