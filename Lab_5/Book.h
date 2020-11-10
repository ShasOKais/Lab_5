#pragma once
#include <iostream>

using namespace std;

class Book {
private:
	string NameBook;
public:
	Book() {
		cout << "Book()\n";
		NameBook = nullptr;
	}
	Book(string NameBook) {
		cout << "setNameToBook(string Name)\n";
		this->NameBook = NameBook;
	}
	string getNameBook() {
		return NameBook;
	}
	void setNameBook(string NameBook) {
		this->NameBook = NameBook;
	}
	~Book() {
		cout << "~Book: " << NameBook << endl;
		NameBook = nullptr;
	}
};

class Genre : public Book {
private:
	int numBook;
	string NameGenre;
public:
	Genre() {
		cout << "Genre()\n";
		NameGenre = nullptr;
	}
	Genre(int numBook, string NameGenre, string NameBook) {
		this->numBook = numBook;
		this->NameGenre = NameGenre;
		this->setNameBook(NameBook);
		cout << "Конструктор с параметрами Genre: "
			<< numBook << " "
			<< NameGenre << " "
			<< NameBook << "\n";
	}
	~Genre() {
		cout << "~Genre: " << NameGenre << endl;
		NameGenre = nullptr;
	}
};