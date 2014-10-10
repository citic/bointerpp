#ifndef PlayerManager_h
#define PlayerManager_h

#include "Common.h"

class PlayerManager : public cocos2d::Ref
{
	DECLARE_NO_COPY_CLASS(PlayerManager)

  protected:
	/// The nickname of the local player on this device
	std::string currentPlayerName;

  public:
	/// Set initial values
	virtual bool init();
	/// Returns a pointer to the singleton instance of this class
	static PlayerManager* getInstance();
	/// Get the name of the current player
	inline const std::string& getCurrentPlayerName() const { return currentPlayerName; }

  protected:
	/// Protected default constructor
	PlayerManager();
};

#endif // PlayerManager_h
