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

	bool isVisible() const { return  visible; };


	map<size_t, string> getFilters() { return nodeFilters; };
	bool applyFilters(const map<size_t, string>& filters, const bool& isSideEffect = false )
	{
		// merge filters
		Filter::mergeFilters(nodeFilters, filters);

		// apply new filters to each child
		bool res = false;
		if (view)
			res = view->applyFilters(nodeFilters);
		for (auto& e : next)
			if (e && e->applyFilters(nodeFilters))
				res = true;
		visible = res;
		// remove empty filters
		Filter::clearFilters(nodeFilters);
		return res;
	}

private:

	TreeNode* parent = nullptr;
	string name;

	shared_ptr<View> view = nullptr;
	vector<shared_ptr<TreeNode>> next;
	bool visible = true;
	map<size_t, string> nodeFilters;
	map<size_t, string> sideEffectFilters;
};