#include "BaseScene.h"
#include "PlayerManager.h"
#include "PlayerMenuItem.h"

USING_NS_CC;

PlayerMenuItem::PlayerMenuItem()
	: playerName(nullptr)
	, playerStatus(nullptr)
{
}

PlayerMenuItem* PlayerMenuItem::create()
{
	return PlayerMenuItem::create((const ccMenuCallback&)nullptr);
}

PlayerMenuItem* PlayerMenuItem::create(const ccMenuCallback& callback)
{
	PlayerMenuItem* result = new (std::nothrow) PlayerMenuItem();
	result->initWithCallback(callback);
	result->autorelease();
	return result;
}

bool PlayerMenuItem::initWithCallback(const ccMenuCallback& callback)
{
	if ( ! cocos2d::MenuItem::initWithCallback(callback) ) return false;

	// Player name is prominent in the top of the item
	const std::string& name = PlayerManager::getInstance()->getCurrentPlayerName();
	MenuItemFont::setFontSize(16.0f);
	playerName = MenuItemFont::create(name, _callback);
	playerName->setColor(BaseScene::fontColor);
	this->setContentSize(Size(node_width(playerName) + 10.0f, 40.0f));
	playerName->setPosition(half_width(this), node_height(this) - half_height(playerName));
	addChild(playerName);

	return true;
}
