/* Заметка:

	Конечный код должен быть написан, как если бы
	он писался для рабочего проекта.

	Код может включать пример/тест, демонстрирующий работоспособность.
	Будет пример/тест или нет -- не важно.

	Можно использовать сторонние библиотеки
	или написать необходимый вспомогательный функционал.
	Можно использовать любой стандарт С++.
*/

#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

/*
	В качестве примера применения этого интерфейса
	представь дерево, которое отображает папки и файлы;
	у каждой папки имеется поле поиска,
	который ищет по файлам в ней. Но при этом
	сама иерархия папок определяется извне.
.
└──  🔍
	├── 📁 A 🔍
	│   ├── 12
	│   └── 13
	└── 📁 D 🔍
		├── 📁 B 🔍
		│   ├── 12
		│   ├── 22
		│   ├── 13
		│   └── 23
		└── 📁 C 🔍
			├── 12
			├── 13
			└── 123
.
└── 🔍 3
	├── 📁 A 🔍
	│   └── 13
	└── 📁 D 🔍
		├── 📁 B 🔍
		│   ├── 13
		│   └── 23
		└── 📁 C 🔍
			├── 13
			└── 123
.
└── 🔍 3
	├── 📁 A 🔍
	│   └── 13
	└── 📁 D 🔍 1
		├── 📁 B 🔍
		│   └── 13
		└── 📁 C 🔍
			├── 13
			└── 123
.
└── 🔍 3
	├── 📁 A 🔍
	│   └── 13
	└── 📁 D 🔍 2
		├── 📁 B 🔍
		│   └── 23
		└── 📁 C 🔍
			└── 123


	Плюс, представь несколько таких деревьев, которые находятся в отдельно друг от друга.
	От каждого дерева можно получить список View, которые в нем находятся.
	И есть глобальный поиск по всем этим деревьям.
	(Под поиском подразумевается поиск по имени элемента)
*/


int main()
{
}