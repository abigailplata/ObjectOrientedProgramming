#ifndef Greet_h
#define Greet_h
// We should include <string> here
#include <string>
using namespace std;
// Implement your "greet" function below

//Got help from a peer, Elena Gonzalez.

typedef void (*apfunc)(string);

void greet (string name, void funct(string)){
	apfunc greet = funct;
	greet(name);
}

#endif /* Greet_h */
