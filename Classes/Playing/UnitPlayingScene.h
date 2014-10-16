#ifndef UNITPLAYINGSCENE_H
#define UNITPLAYINGSCENE_H

#include "GameScene.h"

class UnitPlayingScene : public GameScene
{
  protected:
	/// The context where the units are found. It is a folder where units are to be loaded from
	/// "Training" or "Missions"
	std::string context;
	/// The filename for the unit, e.g: "sum_xy"
	std::string unitName;

  public:
	/// Default constructor
	explicit UnitPlayingScene(const std::string& context, const std::string& unitName);
	/// Creates an auto-release scene containing this layer
	static cocos2d::Scene* createScene(const std::string& context, const std::string& unitName);
	/// Creates an auto-release object of this layer
	static UnitPlayingScene* createWithContextAndUnit(const std::string& context, const std::string& unitName);
	/// Initializes the scene. This method is called before the scene is shown
	virtual bool init();

  public:
	/// Called when the Back button is pressed
	virtual void buttonBackPressed(cocos2d::Ref* sender) { showUnitSelectionScene(context); }
};

#endif // UNITPLAYINGSCENE_H
