#include "UnitPlayingScene.h"

USING_NS_CC;

UnitPlayingScene::UnitPlayingScene(const std::string& context, const std::string& unitName)
	: GameScene("UnitPlaying")
	, context(context)
	, unitName(unitName)
{
}

cocos2d::Scene* UnitPlayingScene::createScene(const std::string& context, const std::string& unitName)
{
	auto scene = cocos2d::Scene::create();
	scene->addChild( UnitPlayingScene::createWithContextAndUnit(context, unitName) );
	return scene;
}

UnitPlayingScene* UnitPlayingScene::createWithContextAndUnit(const std::string& context, const std::string& unitName)
{
	UnitPlayingScene* object = new UnitPlayingScene(context, unitName);
	if ( ! object ) return nullptr;
	if ( object->init() )
	{
		object->autorelease();
		return object;
	}
	delete object;
	return nullptr;
}

bool UnitPlayingScene::init()
{
	// Init parent class first
	if ( ! BaseScene::init() ) return false;

	auto fileUtils = FileUtils::getInstance();
	fileUtils->addSearchPath(context);

	// Create scenery
	createStandardMenu(unitName);

	// Done
	return true;
}
