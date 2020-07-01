#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>

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

struct View
{
	// `Range` �������� ����������� ��� ��������,
	// � �������� ����� �������� �������� `Element*`
	// ����� ����� ����������� ������ ���� �����
	// ������ ������������ �� ���������
	// � ������ `add` �� ������ ������� �� `elements`
	template<class Range>
	View(Range& elements);

	View();

	// `add` � `remove` ���������� ����������� �����
	void add(Element* e);
	void remove(Element* e);

	//! ���������� ���-�� ������� ���������
	int count() const;
	//! ���������� i-��� ������� �������
	Element* get(int i) const;
	
	// �������� ������ ������ �� �����
	void applyFilter(const string& filter);

	// ��������
	vector<shared_ptr<Element>> elements;
	vector<size_t> visibleItemIndexes;
};
