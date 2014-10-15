#ifndef UnitManager_h
#define UnitManager_h

#include "Common.h"

/** Loads the list of units for a given context */
class UnitManager
{
	DECLARE_NO_COPY_CLASS(UnitManager);

  protected:
	/// The context for loading units: e.g: "Training", "Missions"
	std::string context;

  public:
	/// Constructor
	UnitManager();
	/// Loads units for the given context
	/// @return true on success, false on fail
	bool load(const std::string& context);
};

#endif // UnitManager_h
