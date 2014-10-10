#ifndef UNITSELECTIONSCENE_H
#define UNITSELECTIONSCENE_H

#include "GameScene.h"

class UnitSelectionScene : public GameScene
{
  protected:
	/// The context where the units are found. It is a folder where units are to be loaded from
	/// "Training" or "Missions"
	std::string context;

  public:
	/// Default constructor
	explicit UnitSelectionScene(const std::string& context);
	/// Creates an auto-release scene containing this layer
	static cocos2d::Scene* createScene(const std::string& context);
	/// Creates an auto-release object of this layer
	static UnitSelectionScene* createWithContext(const std::string& context);
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();

  public:
	/// Called when the Back button is pressed
	virtual void buttonBackPressed(cocos2d::Ref* pSender) { showGameMenuScene(); }
};

#endif // UNITSELECTIONSCENE_H
