#pragma once

#include "FolderView.h"

#include <string>

using namespace std;

class FileList
{
public:
	static FolderView GetFileList(const string& path);
};
