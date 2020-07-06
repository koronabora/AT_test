#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "Element.h"

using namespace std;

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

struct View
{
	// `Range` �������� ����������� ��� ��������,
	// � �������� ����� �������� �������� `Element*`
	// ����� ����� ����������� ������ ���� �����
	// ������ ������������ �� ���������
	// � ������ `add` �� ������ ������� �� `elements`
	template<class Range>
	View(const Range& elements);
	View();

	// `add` � `remove` ���������� ����������� �����
	void add(shared_ptr<Element> e);
	void remove(shared_ptr<Element> e);
	// �������� ������ ������ �� �����. ������ true, ���� ������� ������������
	bool applyFilters(const map<size_t, string>& newFilters);

	//! ���������� ���-�� ������� ���������
	virtual size_t count() const;

	//! ���������� i-��� ������� �������
	shared_ptr<Element> get(size_t i) const;

	map<size_t, string> filters;
	vector<size_t> visibleItems;

	// ��������
	vector<shared_ptr<Element>> elements;
};
