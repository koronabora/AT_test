#pragma once

#include <algorithm>
#include <iterator>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "View.h"
#include "TreeNode.h"

using namespace std;

/*
└──  🔍
	├── 📁 A 🔍
	│   ├── 12
	│   └── 13
	└── 📁 D 🔍
		├── 📁 B 🔍
*/

const string FOLDER_ICON = " <F> ";
const string LAST_ELEM_PADDING = "  \\ ";
const string ELEM_PADDING = " |- ";
const string NORMAL_SPACER_PADDING = " |  ";
const string LAST_SPACER_PADDING = "     ";
const string ESCAPE_SEQUENCE = "q";
const string MODIFY_SEQUENCE = "m";
const string CREATE_SEQUENCE = "c";
const string REMOVE_SEQUENCE = "r";

namespace fs = std::filesystem;

struct ViewDebugger
{
	ViewDebugger();
	~ViewDebugger();
	void DebugView(const string& path);
	shared_ptr<TreeNode> root;
	void testLoop();
	void printTree(const shared_ptr<TreeNode>& item, const string& prevPadding, const bool& isLastl);
	map<size_t, shared_ptr<TreeNode>> nodeLineNumbers;
	size_t counter = 0;
	size_t getLineIdByNode(const shared_ptr<TreeNode>& node);
};
