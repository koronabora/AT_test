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
	`View` -- класс, который отвечает за отображение элементов определенного типа(в данном случае `Element`).

	Необходимо добавить операцию поиска по элементам.
	Поиск должен быть максимально эффективным.
	И работать так, чтобы можно было реализовать пример ниже.

-----------------
	Ниже -- имеющийся интерфейс(объявления методов).
	Надо его реализовать(написать определения),
	и добавить неоходимые методы для реализации
	вышеописанного функционала.
-----------------
*/

struct View
{
	// `Range` является контейнером или массивом,
	// у которого типом элемента является `Element*`
	// Вызов этого конструкора должен быть равен
	// вызову конструктора по умолчанию
	// и вызову `add` на каждый элемент из `elements`
	template<class Range>
	View(Range& elements);

	View();

	// `add` и `remove` вызываются чрезвычайно редко
	void add(Element* e);
	void remove(Element* e);

	//! Возвращает кол-во видимых элементов
	int count() const;
	//! Возвращает i-тый видимый элемент
	Element* get(int i) const;
	
	// применим фильтр поиска по имени
	void applyFilter(const string& filter);

	// Элементы
	vector<shared_ptr<Element>> elements;
	vector<size_t> visibleItemIndexes;
};
