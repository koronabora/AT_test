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
#include <iostream>
#include <string>
#include <map>
#include <windows.h>

#include "ViewDebugger.h"

using namespace std;

int main(int argc, char** argv)
{
	SetConsoleOutputCP(65001);
	string path = argv[0];
	string foo;
	cout << "Enter working directory [defalut - current]: ";
	getline(cin, foo);
	path = foo.empty() ? path : foo;
	ViewDebugger vd;
	vd.DebugView(path);
	return 0;
}