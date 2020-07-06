#include "Filter.h"

bool Filter::isStringMatchingWithFilter(const string& s, const string& filter)
{
	size_t pos = s.find(filter);
	return pos != string::npos;
	//return true;
}