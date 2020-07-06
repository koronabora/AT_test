#pragma once

#include "View.h"

struct TreeNode
{
	TreeNode(TreeNode* _parent = nullptr) : parent(_parent) {};

	void setName(const string& _name) { name = _name; }
	string getName() const { return name; };

	void setParent(TreeNode* _parent) { parent = _parent; };
	TreeNode* getParent() const { return parent; };

	void setView(shared_ptr<View> newView) { view = newView; };
	shared_ptr<View> getView() const { return view; };

	void addChildren(shared_ptr<TreeNode> e) { next.push_back(e); };
	vector<shared_ptr<TreeNode>> getChild() const { return next; };

	TreeNode* parent = nullptr;
	string name;

	shared_ptr<View> view = nullptr;
	vector<shared_ptr<TreeNode>> next;

	bool applyFilter(const string& filter)
	{
		bool res = false;
		if (view)
			res = view->applyFilter(filter);
		for (auto& e : next)
			if (e && e->applyFilter(filter))
					res = true;
		return res;
	}

};