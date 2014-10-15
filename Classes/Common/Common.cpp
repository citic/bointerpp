#include "Common.h"

bool eprintf(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	//cocos2d::log(format, args);
	vfprintf(stderr, format, args);
	va_end(args);
	return false;
}
