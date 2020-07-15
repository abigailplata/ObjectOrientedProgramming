#include <iostream>
#include <string>
using namespace std;

int main () 
{
	int n;
	cin >> n;
	while (n > 0) {
		if (n%2 == 0){
			cout << "EVEN";
		} else {
			cout << "ODD"
		}
	}
    return 0;
}