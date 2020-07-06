#pragma once

#include <vector>
#include <string>
#include <map>

#include "ItemBase.h"
#include "Filter.h"

using std::string;
using std::map;
using std::vector;

struct Element : public ItemBase
{
	//string name;
	map<string, string> properties;
	Element(const string& n) : ItemBase() { ItemBase::setName(n); }
	Element() : ItemBase() {};

	// virtual methods
	virtual void add(shared_ptr<ItemBase> e) {};
	virtual void remove(shared_ptr<ItemBase> e) {};
	virtual bool applyFilter(const string& filter) { return Filter::isStringMatchingWithFilter(name, filter); };
	virtual size_t count() const
	{ 
		return 0; 
	};
	virtual shared_ptr<ItemBase> get(size_t i) const { return nullptr; };
	virtual bool isLeaf()
	{
		return true;
	}
};
