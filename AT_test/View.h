#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "ItemBase.h"
#include "Element.h"

using std::string;
using std::map;
using std::vector;
using std::shared_ptr;

/*
	`View` -- �����, ������� �������� �� ����������� ��������� ������������� ����(� ������ ������ `Element`).

	���������� �������� �������� ������ �� ���������.
	����� ������ ���� ����������� �����������.
	� �������� ���, ����� ����� ���� ����������� ������ ����.

-----------------
	���� -- ��������� ���������(���������� �������).
	���� ��� �����������(�������� �����������),
	� �������� ���������� ������ ��� ����������
	�������������� �����������.
-----------------
*/

struct View : public ItemBase
{
	// `Range` �������� ����������� ��� ��������,
	// � �������� ����� �������� �������� `Element*`
	// ����� ����� ����������� ������ ���� �����
	// ������ ������������ �� ���������
	// � ������ `add` �� ������ ������� �� `elements`
	template<class Range>
	View(const Range& elements);
	View();

	// interface methods
	// `add` � `remove` ���������� ����������� �����
	void add(shared_ptr<ItemBase> e);
	void remove(shared_ptr<ItemBase> e);
	// �������� ������ ������ �� �����. ������ true, ���� ������� ������������
	bool applyFilter(const string& filter);

	//! ���������� ���-�� ������� ���������
	virtual size_t count() const;

	//! ���������� i-��� ������� �������
	shared_ptr<ItemBase> get(size_t i) const;

	string currentFilter;
	vector<size_t> visibleItems;
	bool isLeaf();

	// ��������
	vector<shared_ptr<ItemBase>> elements;
};
