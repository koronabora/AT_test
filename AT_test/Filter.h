#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>

using std::map;
using std::vector;
using std::string;

struct Filter
{
	static size_t getLastFilterId();
	static bool isStringMatchingWithFilter(const string& s, const map<size_t, string>& filters);
	static void mergeFilters(map<size_t, string>& filters, const map<size_t, string>& newFilters);
	static void clearFilters(map<size_t, string>& filters);
private:
	static size_t lastFilterId;
};
