#include "UnitManager.h"
#include <fstream>

USING_NS_CC;

UnitManager::UnitManager()
{
}

bool UnitManager::load(const std::string& context)
{
	this->context = context;
	std::string filename = context + ".lst";
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	if ( fullpath.length() == 0 ) return eprintf("could not open unit list: %s", fullpath.c_str());

	std::ifstream file(fullpath);
	std::string line;
	while ( std::getline(file, line) )
		if ( line.length() > 0 )
			loadLine(line);

	return true;
}

bool UnitManager::loadLine(const std::string& line)
{
	// A file extract may be:

	// intro:            <-- level 1
	// sum_xy.xml        <-- unit 1-1
	// abs_diff.xml      <-- unit 1-2
	// average_n.xml     <-- unit 1-3
	//
	// dyn_mem:          <-- level 2
	// median.xml        <-- unit 2-1

	// Levels ends with :
	if ( line[ line.length() - 1] == ':' )
	{
		levels.push_back(UnitLevel(line.substr(0, line.length() - 1)));
		return true;
	}

	// If reached this point, the line contains an unit, not a level
	// A least a level must be provided in the file
	assert(levels.size() > 0);
	if ( levels.size() == 0 ) return false;

	levels[levels.size() - 1].units.push_back(line);
	return true;
}
