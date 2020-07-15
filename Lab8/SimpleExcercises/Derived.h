#include <iostream>
#include "ADT.h"
//help from Emily Bossiere
using namespace std;

class Derived : public ADT{
public:
	void doSomething(){
		cout << "I did something" << endl;
	}
	
	void doSomethingElse(){
		cout << "I did something else" << endl;
	}
	
	void dontDoThis(){
	
	}
};