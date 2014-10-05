#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <cocos2d.h>

class HelloWorld : public cocos2d::Layer
{
public:
	/// Create a scene containing this layer
	static cocos2d::Scene* createScene();
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();
	/// Called when the close button is pressed
	void menuCloseCallback(cocos2d::Ref* pSender);
	/// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
