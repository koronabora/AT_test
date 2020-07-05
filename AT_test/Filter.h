#pragma once

#include <string>

using std::string;

struct Filter
{
	static bool isStringMatchingWithFilter(const string& s, const string& filter);
};
