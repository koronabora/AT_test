#pragma once

#include <memory>
#include <string>

using namespace std;

struct ItemBase
{
public:
	ItemBase() : parent(nullptr) {};
	ItemBase(const string& _name) : parent(nullptr), name(_name) {};
	ItemBase(ItemBase* _parent) : parent(_parent) {};
	virtual ~ItemBase() {};
	void setParent(ItemBase* _parent) { this->parent = _parent; };
	ItemBase* getParent() { return parent; };
	virtual void add(shared_ptr<ItemBase> e) 
	{
	
	};
	virtual void remove(shared_ptr<ItemBase> e) 
	{
	
	};
	virtual bool applyFilter(const string& filter) 
	{
		return false;
	}; // true if name is mathing with filter
	virtual void setName(const string& _name) { name = _name; };
	virtual size_t count() const { 
		return 0;
	};
	virtual string getName() { return name; };
	virtual shared_ptr<ItemBase> get(size_t i) const 
	{ 
		return nullptr; 
	};
	virtual bool isLeaf()
	{
		return false;
	}


	ItemBase* parent;
	string name;
};
