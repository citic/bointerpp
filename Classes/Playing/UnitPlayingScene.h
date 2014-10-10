#ifndef UNITPLAYINGSCENE_H
#define UNITPLAYINGSCENE_H

#include "GameScene.h"

class UnitPlayingScene : public GameScene
{
  protected:
	/// The context where the units are found. It is a folder where units are to be loaded from
	/// "Training" or "Missions"
	std::string context;

  public:
	UnitPlayingScene();

  public:
	/// Called when the Back button is pressed
	virtual void buttonBackPressed(cocos2d::Ref* pSender) { showUnitSelectionScene(context); }
};

#endif // UNITPLAYINGSCENE_H
