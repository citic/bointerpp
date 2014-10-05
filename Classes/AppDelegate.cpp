#include "AppDelegate.h"
#include "Common.h"
#include "GameMenuScene.h"

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
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

	GLView::setGLContextAttrs(glContextAttrs);
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

	// create a scene. it's an autorelease object
	auto scene = HelloWorld::createScene();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::createWindow()
{
	auto director = Director::getInstance();
	auto window = director->getOpenGLView();

	// If running on mobile device, window exists, on PC it is created
	if( ! window )
	{
		window = GLViewImpl::create("bointer++");
		director->setOpenGLView(window);
	}

	window->setDesignResolutionSize(1024, 768, ResolutionPolicy::NO_BORDER);

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
