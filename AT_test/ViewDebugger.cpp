#include "ViewDebugger.h"

shared_ptr<ItemBase> ViewDebugger::root = nullptr;

ViewDebugger::ViewDebugger()
{
	root = make_shared<ItemBase>(new View());
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
		vector<wstring> fileNames = { p.wstring() };
		for (auto& el : filesystem::recursive_directory_iterator(p, filesystem::directory_options::skip_permission_denied))
		{
			//wcout << el.path().wstring() << endl;
			fileNames.push_back(el.path().wstring());
		}
		buildView(fileNames);
	}
	catch (...)
	{
		wcout << L"Filessytem exception" << endl;
	}
}

// using code from http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
vector<wstring> ViewDebugger::split(const wstring& s)
{
	vector<wstring> res;
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

void ViewDebugger::buildView(const vector<wstring>& files)
{
	// split to vector<vector<wstring>>	
	vector<vector<wstring>> treeData;
	for (const wstring& ws : files)
		treeData.push_back(split(ws));

	// analyze data and build tree
	size_t currentLevel = 0;
	for (vector<wstring> v : treeData)
	{
	}
}