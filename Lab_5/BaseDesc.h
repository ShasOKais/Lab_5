#pragma once

#include <iostream>

using namespace std;

class A {
protected:
	int x = 0;
public:
	A() {
		cout << "A()\n";
		x = 0;
	}
	A(int x) {
		this->x = x;
		cout << "A(x)\n";
	}
	A(A* p) {
		cout << "Mark A\n";
	}
	A(A& p) {
		cout << "Copy A\n";
	}

	void f1() {
		cout << "A - f1\n";
		f2();
	}
	void f2() {
		cout << "A - f2\n";
	}

	virtual ~A() {
		cout << "~A()\n";
	}
};

class B : public A {
private:
	int y;
public:
	B() {
		cout << "B()\n";
		y = 0;
	}
	B(int x, int y) : A(x){
		this->y = y;
		cout << "B()\n";
	}
	B(B& p) : A(p.x) {
		cout << "Copy B\n";
	}

	void f1() {
		cout << "B - f1\n";
		f2();
	}
	void f2() {
		cout << "B - f2\n";
	}

	virtual ~B() {
		cout << "~A()\n";
	}
};