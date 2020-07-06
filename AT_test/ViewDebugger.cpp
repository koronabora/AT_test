#include "ViewDebugger.h"

ViewDebugger::ViewDebugger()
{
	root = make_shared<TreeNode>();
	root->setName("R");
	nodeLineNumbers[++counter] = root;
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
			nodeLineNumbers[++counter] = node0;
			for (size_t j = 0; j < 3; j++)
			{
				shared_ptr<TreeNode> node1 = make_shared<TreeNode>();
				node1->setParent(node0.get());
				node1->setName(to_string(j + 1));
				node0->addChildren(node1);
				nodeLineNumbers[++counter] = node1;
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
	string newPosString;
	size_t newPos;
	while (working)
	{
#ifdef _MSC_VER
		system("cls");
#else
		system("clear");
#endif
		//cout << "Current filter: " << newPosString << endl;
		cout << "[<line>] - <name> - {<filters>}" << endl;
		cout << "------------------" << endl;
		printTree(root, "", true);
		cout << "------------------" << endl;
		cout << "Enter line to modify or [" << ESCAPE_SEQUENCE << "] for exit: ";
		getline(cin, newPosString);
		if (newPosString.compare(ESCAPE_SEQUENCE) == 0)
			working = false;
		else  if (root && !newPosString.empty())
		{
			newPos = stoul(newPosString.c_str(), nullptr, 10);
			if (newPos != 0)
			{
				if (nodeLineNumbers.find(newPos) == nodeLineNumbers.end())
				{
					cout << "Line number is invalid! Press any key to try again. " << endl;
					getline(cin, newPosString);
				}
				else
				{
					auto item = nodeLineNumbers[newPos];
					if (item)
					{
						// view current filter
						map<size_t, string> filters = item->getFilters();
						cout << "Current filters: " << endl;
						map<size_t, size_t> foo; // filter line - filter id
						size_t id = 0; // def filter line
						// code could be improved to allow a few filters simultaneously
						for (const auto& e : filters)
						{
							cout << "[" << ++id << "] " << e.second << endl;
							foo[id] = e.first;
						}
						// show avaliable operations
						if (!filters.empty())
							cout << "Select operation: <" << MODIFY_SEQUENCE << "> - modify, <" << REMOVE_SEQUENCE << "> - remove" << endl;
						else
							cout << "<empty>" << endl << "Select operation: <" << CREATE_SEQUENCE << "> - create" << endl;
						// read operatiom
						string op;
						getline(cin, op);
						if (op.compare(CREATE_SEQUENCE) == 0 && filters.empty())
						{
							// append new filter
							cout << "Enter the new filter: " << endl;
							string newFilter;
							getline(cin, newFilter);
							filters[Filter::getNewFilterId()] = newFilter;
						}
						else if (op.compare(MODIFY_SEQUENCE) == 0)
						{
							// modify
							cout << "Enter the new filter: " << endl;
							string newFilter;
							getline(cin, newFilter);
							filters[foo[id]] = newFilter;
						}
						else if (op.compare(REMOVE_SEQUENCE) == 0)
						{
							// remove filter
							filters[foo[id]] = "";

						}
						cout << "Done" << endl;
						// apply new filters
						item->applyFilters(filters);
					}
				}
			}
		}
	}
}

size_t ViewDebugger::getLineIdByNode(const shared_ptr<TreeNode>& node)
{
	for (const auto& e : nodeLineNumbers)
		if (e.second == node)
		{
			return e.first;
		}
	return 0;
}

void ViewDebugger::printTree(const shared_ptr<TreeNode>& item, const string& prevPadding, const bool& isLast)
{
	// construct spacer
	if (item && item->isVisible())
	{
		// tree node
		cout << "[" << getLineIdByNode(item) << "] ";
		string padding = prevPadding;
		padding.append(isLast ? LAST_ELEM_PADDING : ELEM_PADDING);
		string s = padding;
		s.append(FOLDER_ICON);
		s.append(item->getName());
		// get filters
		map<size_t, string> filters = item->getFilters();
		s.append(" {");
		for (const auto& e : filters)
		{
			s.append(e.second +"");
		}
		s.append("}");
		//
		cout << s << endl;

		if (!item->getView())
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
			auto view = item->getView();
			size_t count = view->count();
			for (size_t i = 0; i < count; i++)
			{
				auto elem = view->get(i);
				if (elem)
				{
					cout << "[X] ";
					padding = prevPadding;
					padding.append((i == count - 1) ? LAST_ELEM_PADDING : ELEM_PADDING);
					s = padding + elem->name;
					cout << s << endl;
				}
			}
		}
	}
}