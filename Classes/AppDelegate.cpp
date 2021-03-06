#include "AppDelegate.h"
#include "Common.h"
#include "GameMenuScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
  #ifndef LINUX
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

	GLView::setGLContextAttrs(glContextAttrs);
  #endif
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	auto director = Director::getInstance();

	// Create and init the game window
	createWindow();

  #if (COCOS2D_DEBUG == 1)
	// turn on display FPS only in debug mode
	director->setDisplayStats(true);
  #endif

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60.0);

	// Set the default font for labels and its size
	MenuItemFont::setFontName(BaseScene::defaultFont);
	MenuItemFont::setFontSize(12.0f);

	// create a scene. it's an autorelease object
	auto scene = GameMenuScene::createScene();
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();

	// Pause sounds
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();

	// Resume sounds
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

#ifdef LINUX
#define GLVIEWCLASS GLView
#else
#define GLVIEWCLASS GLViewImpl
#endif

void AppDelegate::createWindow()
{
	auto director = Director::getInstance();
	auto window = director->getOpenGLView();

	// If running on mobile device, window exists, on PC it is created
	if( ! window )
	{
		auto config = UserDefault::getInstance();
		if ( config->getBoolForKey("System/FullScreen", false) )
			window = GLVIEWCLASS::createWithFullScreen("bointer++");
		else
			window = GLVIEWCLASS::create("bointer++");
		assert(window);
		director->setOpenGLView(window);
	}

  #if PLATFORM_MOBILE
	window->setDesignResolutionSize(1024, 768, ResolutionPolicy::NO_BORDER);
  #else
	window->setDesignResolutionSize(1024, 768, ResolutionPolicy::EXACT_FIT);
  #endif

  #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	// If it is running on iPad HD, indicate our graphics are designed for HD
	if ( window->getFrameSize().height > 768 )
		director->setContentScaleFactor(2);
  #endif

  #if PLATFORM_PC
	// We can change window size on PC. On mobile devices we keep the default frame size
	window->setFrameSize(1024, 768);
  #endif
}
