#include "BaseScene.h"

USING_NS_CC;

const Color3B BaseScene::fontColor = Color3B(104, 207, 209);

BaseScene::BaseScene(const std::string& sceneName)
	: sceneName(sceneName)
{
}

void BaseScene::initResourceDirectories()
{
	auto fileUtils = FileUtils::getInstance();
	std::vector<std::string> searchPaths;
	const std::string& graphicsFolder = searchGraphicsFolder();

	searchPaths.push_back(sceneName + '/' + graphicsFolder);
	searchPaths.push_back(sceneName + "/Effects");
	searchPaths.push_back(sceneName);
	searchPaths.push_back(graphicsFolder);
	searchPaths.push_back("Fonts");
	searchPaths.push_back("Music");

	fileUtils->setSearchPaths(searchPaths);

  #if COCOS2D_DEBUG
	log("Scene %s: resources from %s", sceneName.c_str(), (sceneName + '/' + graphicsFolder).c_str());
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

void BaseScene::buttonExitPressed(Ref* pSender)
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
	createBackButton();
	createGameLogo();
	createInfoButton();
	createConfigButton();
}

void BaseScene::createBackButton()
{
}

void BaseScene::createGameLogo()
{
}

void BaseScene::createInfoButton()
{
}

void BaseScene::createConfigButton()
{
/*
	auto button = createButton("Config", CC_CALLBACK_1(BaseScene::buttonConfigPressed, this));
	float x = rightX() * 0.8f;
	float y = topY() - button->getContentSize().height * 0.5f;
	button->setPosition(Vec2(x, y));
 */
}

void BaseScene::createPlayerSection()
{
}

MenuItem* BaseScene::createButton(const std::string& name, const cocos2d::ccMenuCallback& callback, float x, float y)
{
	auto button = MenuItemImage::create(name + "Up.png", name + "Down.png", callback);
	button->setPosition(Vec2(x, y));
	addMenuItem(button);
	return button;
}

void BaseScene::addMenuItem(MenuItem* item)
{
	auto menu = Menu::create(item, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}

void BaseScene::buttonConfigPressed(cocos2d::Ref* pSender)
{
	log("Config dialog not implemented in this version");
}


#include "UnitSelectionScene.h"

void BaseScene::showUnitSelectionScene(const std::string& context)
{
	auto scene = UnitSelectionScene::createScene(context);
	Director::getInstance()->replaceScene(TransitionSlideInR::create(0.75f, scene));
}