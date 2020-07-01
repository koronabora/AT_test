#pragma once

#include "View.h"

using std::weak_ptr;

struct Tree
{
	weak_ptr<Tree> parent;
};
