#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "BaseScene.h"

// Forward declarations
class PlayerMenuItem;

class GameScene : public BaseScene
{
  protected:
	/// Sprite for the title bar background
	cocos2d::Sprite* titleBar;
	/// Button to return to the previous screen
	cocos2d::MenuItem* backButton;
	/// Sprite containing the name of the scene
	cocos2d::MenuItemLabel* sceneTitle;
	/// Button to show info about this scene, e.g: the task description on unit playing scene
	cocos2d::MenuItem* infoButton;
	/// Show info for current player
	PlayerMenuItem* playerMenuItem;
	/// Gear button to configure the game
	cocos2d::MenuItem* configButton;

  public:
	/// Constructor
	explicit GameScene(const std::string& sceneName);

  protected: // Title bar: menu in game
	/// Creates a standard menu with common buttons: configure, back/exit, player...
	virtual void createStandardMenu(const std::string& title);
	/// Creates and places the background for the standar menu
	virtual void createStandarMenuBackground();
	/// Creates the button to return to the level selection scene or game menu
	virtual void createBackButton();
	/// Shows the game logo in the menu of the game
	virtual void createGameLogo();
	/// Shows the title for this scene in the center of the title bar
	virtual void createSceneTitle(const std::string& title);
	/// Creates the info button for showing credits in game menu or the unit description in game
	virtual void createInfoButton();
	/// Creates the config button and places it in the screen
	virtual void createConfigButton();
	/// Creates a sprite for showing basic information of the current player
	virtual void createPlayerSection();

  public:
	/// Called when the Back button is pressed
	virtual void buttonBackPressed(cocos2d::Ref* pSender) = 0;
	/// Called when the Info button is pressed
	void buttonInfoPressed(cocos2d::Ref* pSender);
	/// Called when the Config button is pressed
	void buttonConfigPressed(cocos2d::Ref* pSender);
	/// Called when the Player section is pressed
	void playerSectionPressed(cocos2d::Ref* pSender);

  public:
	/// Shows the game menu scene
	static void showGameMenuScene();
	/// Shows the unit selection scene with units from the given context
	/// @param context The folder where units are to be loaded from: "Training" or "Missions"
	/// @param forward Send true if changing from game menu to unit selection, false if
	/// switching from unit playing to unit selection scene
	static void showUnitSelectionScene(const std::string& context, bool forward);
	/// Shows the unit playing scene for the given unit (challenge)
	/// @param context The folder where units are to be loaded from: "Training" or "Missions"
	/// @param unitName The name of the unit to play, e.g: "sum_xy"
	static void showUnitPlayingScene(const std::string& context, const std::string& unitName);
};

#endif // GAMESCENE_H
