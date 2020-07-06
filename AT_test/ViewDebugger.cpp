#include "ViewDebugger.h"

ViewDebugger::ViewDebugger()
{
	root = make_shared<View>();
}

ViewDebugger::~ViewDebugger()
{
}

void ViewDebugger::DebugView(const string& path)
{
	try
	{
		filesystem::path p(path);
		if (!filesystem::is_directory(p))
			p = p.parent_path();
		wcout << L"Working with path: [" << p.wstring() << L"]" << endl;
		vector<string> fileNames;// = { p.string() };
		for (auto& el : filesystem::recursive_directory_iterator(p, filesystem::directory_options::skip_permission_denied))
		{
				fileNames.push_back(el.path().string());
		}
		buildView(fileNames);
	}
	catch (...)
	{
		wcout << L"Filessytem exception" << endl;
	}
}

// using code from http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
vector<string> ViewDebugger::split(const string& s)
{
	vector<string> res;
	size_t current, previous = 0;
	current = s.find_first_of(PATH_DELIM);
	while (current != std::string::npos) {
		res.push_back(s.substr(previous, current - previous));
		previous = current + 1;
		current = s.find_first_of(PATH_DELIM, previous);
	}
	res.push_back(s.substr(previous, current - previous));
	return res;
}

void ViewDebugger::buildView(const vector<string>& files)
{
	// split to vector<vector<wstring>>	
	vector<vector<string>> treeData;
	for (const string& ws : files)
		treeData.push_back(split(ws));

	// analyze data and build tree
	if (!treeData.empty() && !treeData[0].empty())
	{
		// first element is root
		root->setName(treeData[0][0]);
		vector<shared_ptr<ItemBase>> items = parseViewData(treeData, 1, treeData[0][0]);
		for (shared_ptr<ItemBase>& e : items)
		{
			e->setParent(root.get());
			root->add(e);
		}
	}

	// view tree
	testLoop();
}

vector<shared_ptr<ItemBase>> ViewDebugger::parseViewData(const vector<vector<string>> treeData, const size_t& currentLevel, const string& targetParentName)
{
	vector<shared_ptr<ItemBase>> items; // cur level items
	vector<string> viewNames; // view names at current item
	for (vector<string> v : treeData)
	{
		if (v.size() > currentLevel && currentLevel > 0)
		{
			string parentName = v[currentLevel - 1];
			string curName = v[currentLevel];
			if (parentName == targetParentName)
				if (v.size() - 1 == currentLevel)
				{
					// element
					auto el = make_shared<Element>();
					el->setName(curName);
					items.push_back(el);
				}
				else
				{
					// view
					// check is new item unique
					auto pos = find(viewNames.begin(), viewNames.end(), curName);
					if (pos == viewNames.end())
					{
						shared_ptr<ItemBase> rootItem = make_shared<View>();
						items.push_back(rootItem);
						rootItem->setName(curName);
						viewNames.push_back(curName);
						vector<shared_ptr<ItemBase>> items = parseViewData(treeData, currentLevel + 1, curName);
						//wcout << L"Found " << items.size() << L" items for root [" << curName.c_str() << L"]" << endl;
						for (shared_ptr<ItemBase>& e : items)
						{
							e->setParent(rootItem.get());
							rootItem->add(e);
						}

					}
				}
		}
	}
	return items;
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

void ViewDebugger::printTree(const shared_ptr<ItemBase>& item, const string& prevPadding, const bool& isLast)
{
	// construct spacer
	if (item)
	{
		string s = prevPadding;
		s.append(isLast ? LAST_ELEM_PADDING : ELEM_PADDING);
		if (!item->isLeaf())
			s.append(FOLDER_ICON);
		s.append(item->getName());
		if (!item->isLeaf())
			s.append(SEARCH_ICON);
		//if (item->isLeaf())
			cout << s << endl;

		// view child items
		string newPadding = prevPadding;
		if (item->count() == 1)
			newPadding += LAST_SPACER_PADDING;
		else
			newPadding += NORMAL_SPACER_PADDING;
		for (size_t i = 0; i < item->count(); i++)
		{
			shared_ptr<ItemBase> e = item->get(i);
			bool last = false;
			if (i == item->count() - 1)
				last = true;
			printTree(e, newPadding, last);
		}
	}
}