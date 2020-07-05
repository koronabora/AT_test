#pragma once

#include <vector>
#include <string>
#include <map>

#include "ItemBase.h"
#include "Filter.h"

using std::string;
using std::map;
using std::vector;

struct Element: public ItemBase
{
	string name;
	map<string, string> properties;
	Element(const string& n) : ItemBase(this), name(n) {}

	// virtual methods
	void add(shared_ptr<ItemBase> e) {};
	void remove(shared_ptr<ItemBase> e) {};
	bool applyFilter(const string& filter) { return Filter::isStringMatchingWithFilter(name, filter); };
	bool isLeaf() { return true; };
};
