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

	auto fileUtils = FileUtils::getInstance();
	fileUtils->addSearchPath(context);

	// Create scenery
	createStandardMenu(context);
	createLevelsUnits();
	animatePods();

	// Done
	return true;
}

bool UnitSelectionScene::createLevelsUnits()
{
	// Load levels and units from context list, e.g: "Training.lst" or "Missions.lst"
	if ( ! unitManager.load(context) ) return false;

	// Get the list of levels
	const std::vector<UnitLevel>& levels = unitManager.getLevels();

	// For each level, create a line of chips
	for ( size_t i = 0; i < levels.size(); ++i )
		createLevel(i, levels[i]);

	return true;
}

void UnitSelectionScene::createLevel(size_t levelIndex, const UnitLevel& level)
{
	// For each unit in this level, create a chip
	log("%s:", level.name.c_str());
	for (size_t i = 0; i < level.units.size(); ++i )
		createUnit(levelIndex, i, level.units[i]);
}

void UnitSelectionScene::createUnit(size_t levelIndex, size_t unitIndex, const std::string& filename)
{
	log("%zu-%zu: %s", levelIndex + 1, unitIndex + 1, filename.c_str());
}


bool UnitSelectionScene::animatePods()
{
	return true;
}
