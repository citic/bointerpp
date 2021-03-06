#ifndef GameMenuScene_h
#define GameMenuScene_h

#include "GameScene.h"

class GameMenuScene : public GameScene
{
  public:
	/// Default Constructor
	GameMenuScene();
	/// Create a scene containing this layer
	CREATE_SCENE(GameMenuScene)
	/// implement the "static create()" method manually
	CREATE_FUNC(GameMenuScene)
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();

  protected: // Miscelaneous
	/// Create the game menu and its items
	void createMenu();
	/// Create a label menu item
	void createMenuItem(size_t pos, const std::string& text, const cocos2d::ccMenuCallback& callback);
	/// Creates the button to return to the level selection scene or game menu
	virtual void createBackButton();
	/// Creates a sprite for showing basic information of the current player
	virtual void createPlayerSection();

  public: // Call back functions
	/// Called when the Back button is pressed (exit the game)
	virtual void buttonBackPressed(cocos2d::Ref* pSender);
	/// Called when the Training button/menu item is pressed
	void menuTrainingPressed(cocos2d::Ref* pSender);
	/// Called when the Training button/menu item is pressed
	void menuMissionsPressed(cocos2d::Ref* pSender);
	/// Called when the Training button/menu item is pressed
	void menuCollaborationPressed(cocos2d::Ref* pSender);
	/// Called when the Training button/menu item is pressed
	void menuBuildingPressed(cocos2d::Ref* pSender);
};

#endif // GameMenuScene_h
