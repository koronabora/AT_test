#pragma once

#include <vector>
#include <string>
#include <map>

#include "ItemBase.h"
#include "Filter.h"

using std::string;
using std::map;
using std::vector;

struct Element
{
	string name;
	map<string, string> properties;
	Element(const string& n) : name(n) {};
	Element() {};
};
