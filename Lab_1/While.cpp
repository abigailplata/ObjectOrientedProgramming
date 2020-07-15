#include <iostream>
#include <string>
using namespace std;

int main () 
{
	int n;
	cin >> n;
	while (n > 0) {
		if (n%2 == 0){
			cout << "EVEN" << endl;
			cin >> n;
		} else {
			cout << "ODD" << endl;
			cin >> n;
		}
	} 
    return 0;
}