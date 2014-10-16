#include "Common.h"
#include "GameMenuScene.h"

USING_NS_CC;

GameMenuScene::GameMenuScene()
	: GameScene("GameMenu")
{
}

bool GameMenuScene::init()
{
	// Init parent class first
	if ( ! GameScene::init() ) return false;

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
	float x = rightX() - half_width(menuItem) - 28.0f;
	float y = topY() * 0.81f - (pos + 1) * node_height(menuItem) * 1.25f;
	menuItem->setPosition(Vec2(x, y));

	// Create the label and center it inside the button sprite
	TTFConfig config(defaultFont, 38.0f);
	auto label = Label::createWithTTF(config, text);
	label->setColor(fontColor);
	button->addChild(label);
	label->setPosition(Vec2(half_width(button), half_height(button)));

	// Create the menu and add the menu item as a child
	addMenuItem(menuItem);
}

void GameMenuScene::createBackButton()
{
#if PLATFORM_PC
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameMenuScene::buttonBackPressed, this));
	float x = leftX() + half_width(closeItem);
	float y = topY() - half_height(closeItem);
	closeItem->setPosition(Vec2(x, y));
	addMenuItem(closeItem);
#endif // PLATFORM_PC
}

void GameMenuScene::createPlayerSection()
{
	// add a label shows "Hello World"
	auto label = LabelTTF::create("Hello World", "Arial", 24);

	// Position the label on the top right corner
	float x = rightX() - half_width(label) - 20.0f;
	float y = topY() - node_height(label);
	label->setPosition(Vec2(x, y));

	// add the label as a child to this layer
	this->addChild(label, 1);
}

void GameMenuScene::buttonBackPressed(Ref* pSender)
{
	auto config = UserDefault::getInstance();
	bool old = config->getBoolForKey("System/FullScreen", false);
	config->setBoolForKey("System/FullScreen", ! old);
	config->flush();
	Director::getInstance()->end();
}

void GameMenuScene::menuTrainingPressed(Ref* pSender)
{
	showUnitSelectionScene("Training", true);
}

void GameMenuScene::menuMissionsPressed(Ref* pSender)
{
	showUnitSelectionScene("Missions", true);
}

void GameMenuScene::menuCollaborationPressed(Ref* pSender)
{
	log("Collaboration not implemented in this version");
}

void GameMenuScene::menuBuildingPressed(Ref* pSender)
{
	log("Building units not implemented in this version");
}
