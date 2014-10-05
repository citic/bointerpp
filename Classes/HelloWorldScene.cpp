#include "Common.h"
#include "HelloWorldScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	// Init parent class
	if ( ! BaseScene::init() ) return false;

	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
#if PLATFORM_PC
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(rightX() - closeItem->getContentSize().width * 0.5f,
								bottomY() + closeItem->getContentSize().height * 0.5f));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
#endif // PLATFORM_PC

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	auto label = LabelTTF::create("Hello World", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(centerX(), topY() - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("GameMenu/Background.jpg");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(centerX(), centerY()));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	return true;
}
