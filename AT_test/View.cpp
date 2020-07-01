#include "View.h"

template<class Range>
View::View(Range& elements)
{
	for (const Element* e : elements)
		add(e);
}

View::View()
{}

// `add` � `remove` ���������� ����������� �����
void View::add(Element* e)
{
	visibleItemIndexes.push_back(elements.size());
	elements.push_back(std::make_shared<Element>(e));
}

void View::remove(Element* e)
{
	
}

//! ���������� ���-�� ������� ���������
int View::count() const
{}

//! ���������� i-��� ������� �������
Element* View::get(int i) const
{}

// �������� ������ ������ �� �����
void View::applyFilter(const string& filter)
{}