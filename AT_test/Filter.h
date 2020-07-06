#pragma once

#include <string>
#include <algorithm>
#include <iterator>
#include <string>

using std::string;

struct Filter
{
	static bool isStringMatchingWithFilter(const string& s, const string& filter);
};
