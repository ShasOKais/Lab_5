#pragma once
#include <iostream>

using namespace std;

class Book {
private:
	int NumBook;
	string NameBook;
public:
	Book() {
		cout << "Book()\n";
		NameBook = "";
		NumBook = NULL;
	}
	Book(int NumBook, string NameBook) {
		this->NumBook = NumBook;
		this->NameBook = NameBook;
		cout << "Book(param):" << NumBook << " " << NameBook << endl;
	}
	string getNameBook() {
		return this->NameBook;
	}
	virtual string classname() { // переопределяемый метод класса Book
		return "Book";
	}
	virtual bool isA(string name) {
		return this->classname() == name;
	}
	void setNameBook(string NameBook) {
		this->NameBook = NameBook;
	}
	string NoVirtualClassName() {
		return "Book";
	}
	virtual ~Book() {
		cout << "~Book: " << NameBook << endl;
		NameBook = "";
	}
};

class Genre : public Book {
private:
	string NameGenre;
public:
	Genre() {
		cout << "Genre()\n";
		NameGenre = "";
	}
	Genre(string NameGenre, string NameBook) {
		this->NameGenre = NameGenre;
		this->setNameBook(NameBook);
		cout << "Genre(param): "
			<< NameGenre << " "
			<< NameBook << "\n";
	}
	void setGenreBook(string NameBook, string GenreBook) {
		this->NameGenre = GenreBook;
		this->setNameBook(NameBook);
	}
	string classname() { // переопределяемый метод класса Genre
		return "Genre";
	}
	virtual bool isA(string name) {
		return this->classname() == name;
	}
	string NoVirtualClassName() {
		return "Genre";
	}
	virtual ~Genre() {
		cout << "~Genre: " << NameGenre << endl;
		NameGenre = "";
	}
};