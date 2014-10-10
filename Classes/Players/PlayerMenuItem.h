#ifndef PlayerMenuItem_h
#define PlayerMenuItem_h

#include "Common.h"

class PlayerMenuItem : public cocos2d::MenuItem
{
	DECLARE_NO_COPY_CLASS(PlayerMenuItem)

  protected:
	/// Shows the current player name in the top
	cocos2d::MenuItemFont* playerName;
	/// Shows the status of the current player: his/her level and number of completed units
	cocos2d::MenuItemFont* playerStatus;

  public:
	/// Default constructor
	PlayerMenuItem();
	/// Creates a MenuItem with no target/selector
	static PlayerMenuItem* create();
	/// Creates a MenuItem with a target/selector
	static PlayerMenuItem* create(const cocos2d::ccMenuCallback& callback);
	/// Initializes a MenuItem with a target/selector
	bool initWithCallback(const cocos2d::ccMenuCallback& callback);
};

#endif // PlayerMenuItem_h
