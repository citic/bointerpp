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

	auto button = Sprite::create("ChipDamaged.png");
	auto menuItem = MenuItemLabel::create(button, CC_CALLBACK_1(UnitSelectionScene::unitPressed, this));

	// Place the button in the right place using the pos index
	float x = leftX() + node_width(menuItem) * 1.5f * (unitIndex + 1);
	float y = topY() - (levelIndex + 1) * node_height(menuItem) * 1.25f;
	menuItem->setPosition(Vec2(x, y));

	// Create the label and center it inside the button sprite
	char text[32];
	sprintf(text, "%zu-%zu", levelIndex + 1, unitIndex + 1);
	TTFConfig config(defaultFont, 38.0f);
	auto label = Label::createWithTTF(config, text);
	label->setColor(fontColor);
	button->addChild(label);
	label->setPosition(Vec2(half_width(button), half_height(button)));

	// Create the menu and add the menu item as a child
	addMenuItem(menuItem);
}


bool UnitSelectionScene::animatePods()
{
	return true;
}

void UnitSelectionScene::unitPressed(Ref* pSender)
{
	log("an unit was selected");
}
