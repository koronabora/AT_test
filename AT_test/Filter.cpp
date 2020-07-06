#include "Filter.h"

size_t Filter::lastFilterId = 0;

size_t Filter::getLastFilterId()
{
	return lastFilterId++;
}

bool Filter::isStringMatchingWithFilter(const string& s, const map<size_t, string>& filters)
{
	bool res = true;
	for (const auto& f : filters)
	{
		size_t pos = s.find(f.second);
		if (pos == string::npos)
			res = false;
	}
	return res;
}

void Filter::mergeFilters(map<size_t, string>& filters, const map<size_t, string>& newFilters)
{

}

void Filter::clearFilters(map<size_t, string>& filters)
{
	for (auto& e : filters)
		if (e.second.empty())
			filters.erase(e.first);
}