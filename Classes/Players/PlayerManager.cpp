#include "PlayerManager.h"

USING_NS_CC;

PlayerManager::PlayerManager()
{
}

PlayerManager* PlayerManager::getInstance()
{
	static PlayerManager* sharedInstance = nullptr;
	if ( ! sharedInstance)
	{
		sharedInstance = new (std::nothrow) PlayerManager();
		CCASSERT(sharedInstance, "FATAL: Not enough memory");
		sharedInstance->init();
	}

	return sharedInstance;
}

bool PlayerManager::init()
{
	auto config = UserDefault::getInstance();
	currentPlayerName = config->getStringForKey("CurrentPlayer/Name", _("Player"));
	return true;
}
