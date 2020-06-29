#pragma once

#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

struct Element
{
	string name;
	map<string, string> properties;
	Element(const char* n) : name(n) {}
};
