#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene(const std::string& sceneName)
	: BaseScene(sceneName)
{
}

void GameScene::createStandardMenu()
{
	createStandarMenuBackground();
	createBackButton();
	createGameLogo();
	createInfoButton();
	createConfigButton();
}

void GameScene::createStandarMenuBackground()
{
	auto sprite = Sprite::create("TitleBar.png");
	sprite->setPosition(Vec2(centerX(), topY() - half_height(sprite)));
	this->addChild(sprite, zorderBackground + 1);
}

void GameScene::createBackButton()
{
	auto button = createButton("ButtonBack", CC_CALLBACK_1(GameScene::buttonBackPressed, this));
	float x = leftX() + half_width(button) + 3.0f;
	float y = topY() - half_height(button) - 3.0f;
	button->setPosition(Vec2(x, y));
}

void GameScene::createGameLogo()
{
}

void GameScene::createInfoButton()
{
}

void GameScene::createConfigButton()
{
	auto button = createButton("ButtonConfig", CC_CALLBACK_1(GameScene::buttonConfigPressed, this));
	float x = rightX() - half_width(button) - 3.0f;
	float y = topY() - half_height(button) - 3.0f;
	button->setPosition(Vec2(x, y));
}

void GameScene::createPlayerSection()
{
}

void GameScene::buttonConfigPressed(cocos2d::Ref* pSender)
{
	log("Config dialog not implemented in this version");
}


#include "GameMenuScene.h"
#include "UnitSelectionScene.h"

void GameScene::showGameMenuScene()
{
	auto scene = GameMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionSlideInL::create(0.75f, scene));
}

void GameScene::showUnitSelectionScene(const std::string& context)
{
	auto scene = UnitSelectionScene::createScene(context);
	Director::getInstance()->replaceScene(TransitionSlideInR::create(0.75f, scene));
}
