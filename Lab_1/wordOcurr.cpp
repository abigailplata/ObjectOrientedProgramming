#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	ifstream readFile;
	readFile.open("words.txt");
	string wcount, count;
	int occur = 0;
	int i, input;

	cin >> count;

	while (readFile >> wcount) {
		input = 1;
		for (i =0; i < count.length(); i++) {
			if (!(tolower(count[i] = tolower(wcount[i])))) {
				input = 0;
				break;
			}
		}
		if(input == 1) {
			occur++;
		}

	}
	cout << occur;
	return 0;
}
