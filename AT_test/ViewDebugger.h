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
	const wchar_t PATH_DELIM = L'\\';
#else
	const wchar_t PATH_DELIM = L'//';
#endif
const wstring FOLDER_ICON = L" 📁 ";
const wstring SEARCH_ICON = L" 🔍 ";
const wstring LAST_ELEM_PADDING = L" └── ";
const wstring ELEM_PADDING = L" ├── ";
const wstring SPACER_PADDING = L" │  ";

struct ViewDebugger
{
	ViewDebugger();
	~ViewDebugger();
	static void DebugView(const string& path);
	static void buildView(const vector<wstring>& files);
	static shared_ptr<ItemBase> root;
	static vector<wstring> split(const wstring& s);
};
