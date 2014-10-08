#ifndef BASESCENE_H
#define BASESCENE_H

#include <cocos2d.h>

#define CREATE_SCENE(ChildClass) \
static cocos2d::Scene* createScene() \
{ \
	auto scene = cocos2d::Scene::create(); \
	scene->addChild( ChildClass::create() ); \
	return scene; \
}

/** Base class for all scenes of the game
 */
class BaseScene : public cocos2d::Layer
{
  public: // Data types and constants
	/// Constants used to distinguish the z-order of sprites in the same layer
	static const int zorderBackground = 0;
	static const int zorderMiddleground = 1;
	static const int zorderForeground = 2;
	/// Color for fonts
	static const cocos2d::Color3B fontColor;

  protected:
	/// Each scene has a unique identifier
	std::string sceneName;
	/// The first visible (x,y) pixel of the window/screen
	cocos2d::Vec2 visibleOrigin;
	/// The current size (width, height) of the window/screen
	cocos2d::Size visibleSize;

  public:
	/// Constructor
	explicit BaseScene(const std::string& sceneName);
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();
	/// Called when the close button is pressed
	void menuCloseCallback(cocos2d::Ref* pSender);

  public: // Coordinates for common screen places
	/// Gets the first left visible x pixel
	inline float leftX() const { return visibleOrigin.x; }
	/// Gets the last right visible x pixel
	inline float rightX() const { return visibleOrigin.x + visibleSize.width; }
	/// Gets the first top visible y pixel
	inline float topY() const { return visibleOrigin.y + visibleSize.height; }
	/// Gets the last bottom visible y pixel
	inline float bottomY() const { return visibleOrigin.y; }
	/// Gets the x pixel in the middle of the window
	inline float centerX() const { return visibleOrigin.x + visibleSize.width * 0.5f; }
	/// Gets the y pixel in the middle of the window
	inline float centerY() const { return visibleOrigin.y + visibleSize.height * 0.5f; }

  protected:
	/// Set the search paths for locating resources
	void initResourceDirectories();
	/// Determines the best graphics directory for the given resolution of this device/PC
	/// It returns a string such as "1024x768" or "2048x1536"
	static std::string searchGraphicsFolder();
	/// Plays background music for the game
	virtual void playMusic();
	/// Places the background image of the menu
	virtual void createBackground(const char* backgroundFilename = "Background.jpg");
	/// Creates a standard menu with common buttons: configure, back/exit, player...
	virtual void createStandardMenu();
	/// Creates the button to return to the level selection scene or game menu
	virtual void createBackButton();
	/// Shows the game logo in the menu of the game
	virtual void createGameLogo();
	/// Creates the info button for showing credits in game menu or the unit description in game
	virtual void createInfoButton();
	/// Creates the config button and places it in the screen
	virtual void createConfigButton();
	/// Creates a sprite for showing basic information of the current player
	virtual void createPlayerSection();
};

#endif // BASESCENE_H
