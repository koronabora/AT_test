#pragma once

#include <algorithm>
#include <iterator>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "View.h"

using namespace std;

/*
└──  🔍
	├── 📁 A 🔍
	│   ├── 12
	│   └── 13
	└── 📁 D 🔍
		├── 📁 B 🔍
*/

#ifdef _MSC_VER
	const char PATH_DELIM = '\\';
#else
	const char PATH_DELIM = '//';
#endif
const string FOLDER_ICON = " [F] ";
const string SEARCH_ICON = " {?} ";
const string LAST_ELEM_PADDING = "  \\ ";
const string ELEM_PADDING = " |- ";
const string NORMAL_SPACER_PADDING = " |  ";
const string LAST_SPACER_PADDING = "     ";
const string ESCAPE_SEQUENCE = "q";

namespace fs = std::filesystem;

struct ViewDebugger
{
	ViewDebugger();
	~ViewDebugger();
	void DebugView(const string& path);
	void buildView(const vector<string>& files);
	shared_ptr<ItemBase> root;
	vector<string> split(const string& s);
	vector<shared_ptr<ItemBase>> parseViewData(const vector<vector<string>> treeData, const size_t& currentLevel, const string& targetParentName);
	void testLoop();
	void printTree(const shared_ptr<ItemBase>& item, const string& prevPadding, const bool& isLastl);
};
