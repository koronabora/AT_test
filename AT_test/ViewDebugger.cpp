#include "ViewDebugger.h"

ViewDebugger::ViewDebugger()
{
	root = make_shared<TreeNode>();
	root->setName("R");
}

ViewDebugger::~ViewDebugger()
{
}

void ViewDebugger::DebugView(const string& path)
{
	if (root)
		for (size_t i = 0; i < 3; i++)
		{
			shared_ptr<TreeNode> node0 = make_shared<TreeNode>();
			node0->setParent(root.get());
			node0->setName(to_string(i + 1));
			root->addChildren(node0);
			for (size_t j = 0; j < 3; j++)
			{
				shared_ptr<TreeNode> node1 = make_shared<TreeNode>();
				node1->setParent(node0.get());
				node1->setName(to_string(j + 1));
				node0->addChildren(node1);
				for (size_t l = 0; l < 3; l++)
				{
					shared_ptr<View> view = make_shared<View>();
					node1->setView(view);
					for (size_t k = 0; k < 3; k++)
					{
						auto e = make_shared<Element>();
						e->name = to_string(i * 100 + j * 10 + k + 1) + ".txt";
						view->add(e);
					}
				}
			}
		}
	// view tree
	testLoop();
}

void ViewDebugger::testLoop()
{
	bool working = true;
	string curFilter;
	while (working)
	{
#ifdef _MSC_VER
		system("cls");
#else
		system("clear");
#endif
		cout << "Current filter: " << curFilter << endl;
		cout << "------------------" << endl;
		printTree(root, "", true);
		cout << "------------------" << endl;
		cout << "Enter filtering keyword or press [" << ESCAPE_SEQUENCE << "] for extit: ";
		getline(cin, curFilter);
		if (curFilter.compare(ESCAPE_SEQUENCE) == 0)
			working = false;
		else  if (root)
			root->applyFilter(curFilter);
	}
}

void ViewDebugger::printTree(const shared_ptr<TreeNode>& item, const string& prevPadding, const bool& isLast)
{
	// construct spacer
	if (item)
	{
		// tree node
		string padding = prevPadding;
		padding.append(isLast ? LAST_ELEM_PADDING : ELEM_PADDING);
		string s = padding;
		s.append(FOLDER_ICON);
		s.append(item->getName());
		//s.append(SEARCH_ICON);
		cout << s << endl;

		if (!item->view)
		{
			auto children = item->getChild();
			for (size_t i = 0; i < children.size(); i++)
			{
				if (children[i])
				{
					bool last = (i == children.size() - 1);
					printTree(children[i], padding, last);
				}
			}
		}
		else
		{
			// view child items
			auto view = item->view;
			size_t count = view->count();
			for (size_t i = 0; i < count; i++)
			{
				auto elem = view->get(i);
				if (elem)
				{
					padding = prevPadding;
					padding.append((i == count - 1) ? LAST_ELEM_PADDING : ELEM_PADDING);
					s = padding + elem->name;
					cout << s << endl;
				}
			}
		}
	}
}