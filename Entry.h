#include <iostream>
#include <string>
// #include "address_book_entry.cpp"

using namespace std;

struct Entry {
	string n, ln, email;

	
	void setName(string n) {
		this->n = n;
	}

	void getName() {

	}

	void setLastname(string ln) {
		this->ln = ln;
	}

	void setEmail(string email) {
		this->email = email;
	}

	void print() {
		cout << "First Name: " << n << endl;
		cout << "Last Name: " << ln << endl;
		cout << "Email: " << email << endl;

	}
};
