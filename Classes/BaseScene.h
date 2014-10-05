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
  public:
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();
	/// Called when the close button is pressed
	void menuCloseCallback(cocos2d::Ref* pSender);

  public: // Coordinates for the 4 corners
	/// Gets the first left visible x pixel
	float leftX() const;
	/// Gets the last right visible x pixel
	float rightX() const;
	/// Gets the first top visible y pixel
	float topY() const;
	/// Gets the last bottom visible y pixel
	float bottomY() const;
	/// Gets the x pixel in the middle of the window
	float centerX() const;
	/// Gets the y pixel in the middle of the window
	float centerY() const;
};

#endif // BASESCENE_H
