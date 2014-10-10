#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene(const std::string& sceneName)
	: BaseScene(sceneName)
{
}

void GameScene::createStandardMenu()
{
	createBackButton();
	createGameLogo();
	createInfoButton();
	createConfigButton();
}

void GameScene::createBackButton()
{
}

void GameScene::createGameLogo()
{
}

void GameScene::createInfoButton()
{
}

void GameScene::createConfigButton()
{
	auto button = createButton("Config", CC_CALLBACK_1(GameScene::buttonConfigPressed, this));
	float x = rightX() * 0.8f;
	float y = topY() - button->getContentSize().height * 0.5f;
	button->setPosition(Vec2(x, y));
}

void GameScene::createPlayerSection()
{
}

void GameScene::buttonConfigPressed(cocos2d::Ref* pSender)
{
	log("Config dialog not implemented in this version");
}


#include "UnitSelectionScene.h"

void GameScene::showUnitSelectionScene(const std::string& context)
{
	auto scene = UnitSelectionScene::createScene(context);
	Director::getInstance()->replaceScene(TransitionSlideInR::create(0.75f, scene));
}
