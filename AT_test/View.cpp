#include "View.h"

template<class Range>
View::View(const Range& elements)
{
	for (const shared_ptr<ItemBase>& e : elements)
		add(e);
}

View::View() : ItemBase(this)
{}

void View::add(shared_ptr<ItemBase> e)
{
	if (e)
	{
		if (e->applyFilter(currentFilter))
			visibleItems.push_back(elements.size());
		elements.push_back(e);
	}
	else
		cout << "Recieved nullptr as new item." << endl;
}

void View::remove(shared_ptr<ItemBase> e)
{
	for (size_t i = 0; i < elements.size(); i++)
		if (elements[i] == e)
		{
			auto pos = find(visibleItems.begin(), visibleItems.end(), i);
			if (pos != visibleItems.end())
				visibleItems.erase(pos);
			elements.erase(elements.begin() + i);
			break;
		}
}

//! Возвращает кол-во видимых элементов
size_t View::count() const
{
	return visibleItems.size();
}

//! Возвращает i-тый видимый элемент
shared_ptr<ItemBase> View::get(size_t i) const
{
	shared_ptr<ItemBase> res;
	if (i < visibleItems.size())
		res = elements[visibleItems[i]];
	return res;
}

// применим фильтр поиска по имени
bool View::applyFilter(const string& filter)
{
	currentFilter = filter;
	visibleItems.clear();
	bool res = false;
	if (parent)
		for (size_t i = 0; i < elements.size(); i++)
		{
			shared_ptr<ItemBase> e = elements[i];
			if (e && e->applyFilter(filter))
			{
				visibleItems.push_back(i);
				res = true;
			}
		}
	return res;
}

/*void View::refilter()
{
	visibleItems.clear();
	if (parent)
	{	
		for (size_t i = 0; i < elements.size(); i++)
		{
			shared_ptr<ItemBase> e = elements[i];
			if (e && isItemNameOk(e->name))
					visibleItems.push_back(i);
			}
		}
	}
}

bool View::isLeaf()
{
	return false;
}

bool View::isItemNameOk(const string& itemName)
{
	// TODO:
	return true;
}*/