#include "UnitSelectionScene.h"

USING_NS_CC;

UnitSelectionScene::UnitSelectionScene(const std::string& context)
	: GameScene("UnitSelection")
	, context(context)
{
}

UnitSelectionScene* UnitSelectionScene::createWithContext(const std::string& context)
{
	UnitSelectionScene* object = new UnitSelectionScene(context);
	if ( ! object ) return nullptr;
	if ( object->init() )
	{
		object->autorelease();
		return object;
	}
	delete object;
	return nullptr;
}

cocos2d::Scene* UnitSelectionScene::createScene(const std::string& context)
{
	auto scene = cocos2d::Scene::create();
	scene->addChild( UnitSelectionScene::createWithContext(context) );
	return scene;
}

bool UnitSelectionScene::init()
{
	// Init parent class first
	if ( ! BaseScene::init() ) return false;

	// Create scenery
	createStandardMenu();

	// Done
	return true;
}

