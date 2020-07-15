#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string filename = "words.txt";
	ifstream file(filename);
  	int xwords = 0;
  	string word;

 	 while (file >> word) {
  	  ++xwords;
 	 }


 	 cout << xwords << endl;
 	 cin.get();
}