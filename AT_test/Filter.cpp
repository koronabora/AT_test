#include "Filter.h"

size_t Filter::lastFilterId = 0;

size_t Filter::getNewFilterId()
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
	for (const auto& f : newFilters)
	{
		filters[f.first] = f.second;
		/*auto pos = filters.find(f.first);
		if (pos == filters.end())
		{
			// current filter is new
			filters[f.first] = f.second;
		}
		else
		{
			// current filter already exists
			filters[f.first] = f.second;
		}*/
	}
}

void Filter::clearFilters(map<size_t, string>& filters)
{
	for (auto i=filters.begin(); i!=filters.end(); i++)
		if (i->second.empty())
		{
			filters.erase(i->first);
			if (!filters.empty())
			i--;
		}
}