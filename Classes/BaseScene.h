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
  protected:
	/// The first visible (x,y) pixel of the window/screen
	cocos2d::Vec2 visibleOrigin;
	/// The current size (width, height) of the window/screen
	cocos2d::Size visibleSize;

  public:
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();
	/// Called when the close button is pressed
	void menuCloseCallback(cocos2d::Ref* pSender);

  public: // Coordinates for the 4 corners
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
};

#endif // BASESCENE_H
