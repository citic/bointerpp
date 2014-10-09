#ifndef AppDelegate_h
#define AppDelegate_h

#include <cocos2d.h>

/**
@brief Represents the global video game object, the cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class AppDelegate : private cocos2d::Application
{
  public:
	/// Constructor
	AppDelegate();
	/// Destructor
	virtual ~AppDelegate();
	/// Added in Cocos2d-x v3.3
	virtual void initGLContextAttrs();
	/// Called when the game is run from operating system, for doing initialization
	/// @return true on success, app continue, false on fail, app terminate.
	virtual bool applicationDidFinishLaunching();
	/// The game is running but it was minimized
	virtual void applicationDidEnterBackground();
	/// The game was minimized and now it is being restored
	virtual void applicationWillEnterForeground();

  protected:
	/// Create the window, set its size and other initialization
	void createWindow();
};

#endif // AppDelegate_h

