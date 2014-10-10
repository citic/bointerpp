#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "BaseScene.h"

class GameScene : public BaseScene
{
  public:
	/// Constructor
	explicit GameScene(const std::string& sceneName);

  protected: // Title bar: menu in game
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

  public:
	/// Called when the Config button is pressed
	void buttonConfigPressed(cocos2d::Ref* pSender);

  public:
	/// Shows the unit selection scene with units from the given context
	/// @param context the folder where units are to be loaded from: "Training" or "Missions"
	static void showUnitSelectionScene(const std::string& context);
};

#endif // GAMESCENE_H
