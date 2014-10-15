#include "UnitManager.h"

USING_NS_CC;

UnitManager::UnitManager()
{
}

bool UnitManager::load(const std::string& context)
{
	this->context = context;
	std::string filename = context + ".lst";
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	log("index filename: %s", fullpath.c_str());
	if ( fullpath.length() == 0 ) return false;

	return true;
}
