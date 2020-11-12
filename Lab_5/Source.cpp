#include <iostream>
#include "Book.h"
#include "BaseDesc.h";

void foo1(A ob) {
	cout << "FOO\n";
}
void foo2(A *ob) {
	cout << "*FOO\n";
}
void foo3(A &ob) {
	cout << "&FOO\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	Book GetBook(2, "Книга Статичная");   // инициализация класса Book
	Genre GetGenre("Генри", "Книга Статичная Генри"); // инициализация класса Genre
	
	Book* DynamicGetBook = new Book(1, "Книга Динамичная");
	Book* DynamicGetGenre = new Genre("Фантастика", "Книга Динамичная");

	// Перекрытые методы
	cout << "Не виртуальные методы получения имени: \n";
	cout << DynamicGetBook->NoVirtualClassName() << endl
		<< DynamicGetGenre->NoVirtualClassName() << endl;

	string ret = GetBook.getNameBook(); // вернуть имя книги
	cout << "Извлеченная книга: " << ret << endl;

	// Возвращение имени класса
	cout << DynamicGetBook->classname() << endl
		<< DynamicGetGenre->classname() << endl
		<< GetBook.classname() << endl
		<< GetGenre.classname() << endl;

	// isA
	cout << DynamicGetBook->isA("Genre") << endl
		<< DynamicGetGenre->isA("Genre") << endl;

	// Безопасное приведение типов
	Book* subСlass1 = dynamic_cast<Book*>(DynamicGetBook);
	cout << "THIS " << subСlass1->classname() << " THIS\n";
	Book* subСlass = dynamic_cast<Book*>(DynamicGetGenre);
	cout << "THIS1 " << subСlass->classname() << " THIS1\n";

	delete DynamicGetBook;
	delete DynamicGetGenre;

	A GetA = new B(10, 20);
	B *GetB = new B(20, 30);
	A* GetTemp = new B(50,20);
	foo1(&GetA);
	foo2(GetB);
	foo3(*GetB);

	return 0;
}