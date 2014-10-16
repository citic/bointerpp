#include "GameScene.h"
#include "PlayerMenuItem.h"

USING_NS_CC;

GameScene::GameScene(const std::string& sceneName)
	: BaseScene(sceneName)
	, titleBar(nullptr)
	, backButton(nullptr)
	, sceneTitle(nullptr)
	, playerMenuItem(nullptr)
	, configButton(nullptr)
{
}

void GameScene::createStandardMenu(const std::string& title)
{
	createStandarMenuBackground();
	createBackButton();
	createGameLogo();
	createSceneTitle(title);
	createInfoButton();
	createConfigButton();
	createPlayerSection();
}

void GameScene::createStandarMenuBackground()
{
	this->titleBar = Sprite::create("TitleBar.png");
	this->titleBar->setPosition(Vec2(centerX(), topY() - half_height(titleBar)));
	this->addChild(titleBar, zorderBackground + 1);
}

void GameScene::createBackButton()
{
	backButton = createButton("ButtonBack", CC_CALLBACK_1(GameScene::buttonBackPressed, this));
	float x = leftX() + half_width(backButton) + 3.0f;
	float y = topY() - half_height(backButton) - 3.0f;
	backButton->setPosition(Vec2(x, y));
}

void GameScene::createGameLogo()
{
	auto sprite = Sprite::create("GameLogo.png");
	float x = node_width(backButton) + 10.0f + half_width(sprite);
	float y = topY() - half_height(sprite) + 4.0f;
	sprite->setPosition(Vec2(x, y));
	this->addChild(sprite, zorderMiddleground);
}

void GameScene::createSceneTitle(const std::string& title)
{
	// Create the label and center it inside the button sprite
	TTFConfig config(defaultFont, 38.0f);
	auto label = Label::createWithTTF(config, title);
	label->setColor(fontColor);

	// Pressing the title of the scene, shows information
	sceneTitle = MenuItemLabel::create(label, CC_CALLBACK_1(GameScene::buttonInfoPressed, this));
	sceneTitle->setPosition(Vec2(centerX(), topY() - half_height(sceneTitle) - 2.0f));

	// Create the menu and add the menu item as a child
	addMenuItem(sceneTitle);
}

void GameScene::createInfoButton()
{
	infoButton = createButton("ButtonInfo", CC_CALLBACK_1(GameScene::buttonInfoPressed, this));
	float x = centerX() - half_width(sceneTitle) - 7.0f - half_width(infoButton);
	float y = topY() - half_height(infoButton) - 3.0f;
	infoButton->setPosition(Vec2(x, y));
}

void GameScene::createConfigButton()
{
	configButton = createButton("ButtonConfig", CC_CALLBACK_1(GameScene::buttonConfigPressed, this));
	float x = rightX() - half_width(configButton) - 3.0f;
	float y = topY() - half_height(configButton) - 3.0f;
	configButton->setPosition(Vec2(x, y));
}

void GameScene::createPlayerSection()
{
	playerMenuItem = PlayerMenuItem::create(CC_CALLBACK_1(GameScene::playerSectionPressed, this));
	float x = rightX() - node_width(configButton) - half_width(playerMenuItem) - 6.0f;
	float y = topY() - half_height(playerMenuItem) - 3.0f;
	playerMenuItem->setPosition(Vec2(x, y));
	addChild(playerMenuItem, zorderMiddleground);
}

void GameScene::buttonInfoPressed(cocos2d::Ref* pSender)
{
	log("Info dialog not implemented in this version");
}

void GameScene::playerSectionPressed(cocos2d::Ref* pSender)
{
	log("Player management dialog not implemented in this version");
}


void GameScene::buttonConfigPressed(cocos2d::Ref* pSender)
{
	log("Config dialog not implemented in this version");
}


#include "GameMenuScene.h"
#include "UnitSelectionScene.h"
#include "UnitPlayingScene.h"

void GameScene::showGameMenuScene()
{
	auto scene = GameMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionSlideInL::create(0.66f, scene));
}

void GameScene::showUnitSelectionScene(const std::string& context, bool forward)
{
	auto scene = UnitSelectionScene::createScene(context);
	auto transition = forward ? TransitionSlideInR::create(0.66f, scene) : TransitionSlideInL::create(0.75f, scene);
	Director::getInstance()->replaceScene(transition);
}

void GameScene::showUnitPlayingScene(const std::string& context, const std::string& unitName)
{
	auto scene = UnitPlayingScene::createScene(context, unitName);
	Director::getInstance()->replaceScene(TransitionSlideInR::create(0.66f, scene));
}
