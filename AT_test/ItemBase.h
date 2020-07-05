#pragma once

#include <memory>
#include <string>

using namespace std;

class ItemBase
{
public:
	ItemBase(): parent(nullptr) {};
	ItemBase(ItemBase* _parent = nullptr) : parent(_parent) {};
	virtual ~ItemBase() {};
	void setParent(ItemBase* _parent) { this->parent = _parent; };
	ItemBase* getParent() { return parent; };
	virtual void add(shared_ptr<ItemBase> e) {};
	virtual void remove(shared_ptr<ItemBase> e) {};
	virtual bool applyFilter(const string& filter) { return false;  }; // true if name is mathing with filter

protected:
	ItemBase* parent;
};