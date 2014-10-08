#include "Common.h"
#include "GameMenuScene.h"

USING_NS_CC;

GameMenuScene::GameMenuScene()
	: BaseScene("GameMenu")
{
}

bool GameMenuScene::init()
{
	// Init parent class first
	if ( ! BaseScene::init() ) return false;

	// Create scenery
	createMenu();
	createBackButton();
	createPlayerSection();

	// Done
	return true;
}

void GameMenuScene::createMenu()
{
	createMenuItem(0, _("Training"), CC_CALLBACK_1(GameMenuScene::menuTrainingPressed, this));
	createMenuItem(1, _("Missions"), CC_CALLBACK_1(GameMenuScene::menuMissionsPressed, this));
	createMenuItem(2, _("Collaboration"), CC_CALLBACK_1(GameMenuScene::menuCollaborationPressed, this));
	createMenuItem(3, _("Building"), CC_CALLBACK_1(GameMenuScene::menuBuildingPressed, this));
}

void GameMenuScene::createMenuItem(size_t pos, const std::string& text, const ccMenuCallback& callback)
{
	// The menu item is a button (sprite) compound of a background image and a label
	auto button = Sprite::create("ButtonBackground.png");
	auto menuItem = MenuItemLabel::create(button, callback);

	// Place the button in the right place using the pos index
	float x = rightX() - menuItem->getContentSize().width * 0.5f - 28.0f;
	float y = topY() * 0.81f - (pos + 1) * menuItem->getContentSize().height * 1.25f;
	menuItem->setPosition(Vec2(x, y));

	// Create the label and center it inside the button sprite
	TTFConfig config("Tenby-Five.otf", 38.0f);
	auto label = Label::createWithTTF(config, text);
	button->addChild(label);
	x = button->getContentSize().width * 0.5f;
	y = button->getContentSize().height * 0.5f;
	label->setPosition(Vec2(x, y));

	// Create the menu and add the menu item as a child
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}

void GameMenuScene::createBackButton()
{
#if PLATFORM_PC
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BaseScene::menuCloseCallback, this));
	float x = leftX() + closeItem->getContentSize().width * 0.5f;
	float y = topY() - closeItem->getContentSize().height * 0.5f;
	closeItem->setPosition(Vec2(x, y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
#endif // PLATFORM_PC
}

void GameMenuScene::createPlayerSection()
{
	// add a label shows "Hello World"
	auto label = LabelTTF::create("Hello World", "Arial", 24);

	// Position the label on the top right corner
	float x = rightX() - label->getContentSize().width * 0.5f - 20.0f;
	float y = topY() - label->getContentSize().height;
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void GameMenuScene::menuTrainingPressed(Ref* pSender)
{
	log("No implemented in this version");
}

void GameMenuScene::menuMissionsPressed(Ref* pSender)
{
	log("No implemented in this version");
}

void GameMenuScene::menuCollaborationPressed(Ref* pSender)
{
	log("No implemented in this version");
}

void GameMenuScene::menuBuildingPressed(Ref* pSender)
{
	log("No implemented in this version");
}
