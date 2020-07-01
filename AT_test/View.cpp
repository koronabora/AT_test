#include "View.h"

template<class Range>
View::View(Range& elements)
{
	for (const Element* e : elements)
		add(e);
}

View::View()
{}

// `add` и `remove` вызываются чрезвычайно редко
void View::add(Element* e)
{
	visibleItemIndexes.push_back(elements.size());
	elements.push_back(std::make_shared<Element>(e));
}

void View::remove(Element* e)
{
	
}

//! Возвращает кол-во видимых элементов
int View::count() const
{}

//! Возвращает i-тый видимый элемент
Element* View::get(int i) const
{}

// применим фильтр поиска по имени
void View::applyFilter(const string& filter)
{}