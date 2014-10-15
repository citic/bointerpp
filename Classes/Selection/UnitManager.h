#ifndef UnitManager_h
#define UnitManager_h

#include "Common.h"

/** A level has a name and a list of units. Units are grouped in levels
Levels and their units are numbered automatically, for example:

@code
intro:            <-- level 1
sum_xy.xml        <-- unit 1-1
abs_diff.xml      <-- unit 1-2
average_n.xml     <-- unit 1-3

dyn_mem:          <-- level 2
median.xml        <-- unit 2-1
@endcode
*/
struct UnitLevel
{
	std::string name;
	std::vector<std::string> units;

	explicit UnitLevel(const std::string& name = "") : name(name) { }
};

/** Loads the list of units for a given context */
class UnitManager
{
	DECLARE_NO_COPY_CLASS(UnitManager)

  protected:
	/// The context for loading units: e.g: "Training", "Missions"
	std::string context;
	/// Units are grouped in levels. Each level has exercises of the same concept
	std::vector<UnitLevel> levels;

  public:
	/// Constructor
	UnitManager();
	/// Loads units for the given context
	/// @return true on success, false on fail
	bool load(const std::string& context);
	/// Get access to the levels, be sure to call load() before this method
	inline const std::vector<UnitLevel>& getLevels() const { return levels; }

  protected:
	/// Loads the given line from the list file
	bool loadLine(const std::string& line);
};

#endif // UnitManager_h
