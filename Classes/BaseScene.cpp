#include "Common.h"
#include "BaseScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool BaseScene::init()
{
	// Init parent class
	if ( ! Layer::init() ) return false;

//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void BaseScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

float BaseScene::leftX() const
{
	return Director::getInstance()->getVisibleOrigin().x;
}

float BaseScene::rightX() const
{
	auto director = Director::getInstance();
	return director->getVisibleOrigin().x + director->getVisibleSize().width;
}

float BaseScene::topY() const
{
	auto director = Director::getInstance();
	return director->getVisibleOrigin().y + director->getVisibleSize().height;
}

float BaseScene::bottomY() const
{
	return Director::getInstance()->getVisibleOrigin().y;
}

float BaseScene::centerX() const
{
	auto director = Director::getInstance();
	return director->getVisibleOrigin().x + director->getVisibleSize().width * 0.5f;
}

float BaseScene::centerY() const
{
	auto director = Director::getInstance();
	return director->getVisibleOrigin().y + director->getVisibleSize().height * 0.5f;
}

