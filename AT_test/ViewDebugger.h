#pragma once

#include <string>
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

const wstring FOLDER_ICON = L" 📁 ";
const wstring SEARCH_ICON = L" 🔍 ";
const wstring LAST_ELEM_PADDING = L" └── ";
const wstring ELEM_PADDING = L" ├── ";
const wstring SPACER_PADDING = L" │  ";

struct ViewDebugger
{
	static void DebugView(const View& v);
};
