#include "Common.h"
#include "BaseScene.h"

USING_NS_CC;


BaseScene::BaseScene(const std::string& sceneName)
	: sceneName(sceneName)
{
}

void BaseScene::initResourceDirectories()
{
	auto fileUtils = FileUtils::getInstance();
	std::vector<std::string> searchPaths;
	const std::string& graphicsFolder = searchGraphicsFolder();

	searchPaths.push_back("Font");
	searchPaths.push_back("Music");
	searchPaths.push_back(graphicsFolder);
	searchPaths.push_back(sceneName);
	searchPaths.push_back(sceneName + '/' + graphicsFolder);
	searchPaths.push_back(sceneName + "/Effects");

	fileUtils->setSearchPaths(searchPaths);

  #if COCOS2D_DEBUG
	log("Scene %s: resources from %s", (sceneName + '/' + graphicsFolder).c_str());
  #endif
}

std::string BaseScene::searchGraphicsFolder()
{
	Size size = Director::getInstance()->getOpenGLView()->getFrameSize();
	if ( size.height >= 1536 ) return "2048x1536";
	if ( size.height >= 768 ) return "1024x768";
	return "480x320";
}

// on "init" you need to initialize your instance
bool BaseScene::init()
{
	// Init parent class
	if ( ! Layer::init() ) return false;

	// Get the current dimensions of the screen
	visibleOrigin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

  #if COCOS2D_DEBUG
	log("Visible: origin = (%.2f, %.2f) size = (%.2f, %.2f)\n"
		, visibleOrigin.x, visibleOrigin.y, visibleSize.width, visibleSize.height);
  #endif

	initResourceDirectories();
	createBackground();

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

void BaseScene::playMusic()
{

}

void BaseScene::createBackground(const char* backgroundFilename)
{
	auto sprite = Sprite::create(backgroundFilename);
	sprite->setPosition(Vec2(centerX(), centerY()));
	this->addChild(sprite, zorderBackground);
}

void BaseScene::createStandardMenu()
{

}
