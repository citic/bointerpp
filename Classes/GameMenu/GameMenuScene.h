#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "BaseScene.h"

class GameMenuScene : public BaseScene
{
  public:
	/// Constructor
	GameMenuScene();
	/// Create a scene containing this layer
	CREATE_SCENE(GameMenuScene)
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();
	/// implement the "static create()" method manually
	CREATE_FUNC(GameMenuScene)
};

#endif // __HELLOWORLD_SCENE_H__
