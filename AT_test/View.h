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
	View(const Range& elements);
	View();

	// `add` и `remove` вызываются чрезвычайно редко
	void add(shared_ptr<Element> e);
	void remove(shared_ptr<Element> e);
	// применим фильтр поиска по имени. Вернет true, если элемент соотвествует
	bool applyFilter(const string& filter);

	//! Возвращает кол-во видимых элементов
	virtual size_t count() const;

	//! Возвращает i-тый видимый элемент
	shared_ptr<Element> get(size_t i) const;

	string currentFilter;
	vector<size_t> visibleItems;

	// Элементы
	vector<shared_ptr<Element>> elements;
};
