#define Data_h

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
//Help from Emily Bossiere
using namespace std;

class Data {
vector<int> data; 

public:
	void add(int number){
		data.push_back(number);
	}
	
	void print(){
		for (vector<int>::const_iterator i = data.begin(); i != data.end(); ++i){
			cout << *i << " ";
		}
		cout << endl;
	}
	
	void sort(){
		int i, key, j;
		int n = data.size();
   		for (i = 1; i < n; i++) {
       		key = data[i];
       		j = i-1;
 
       		while (j >= 0 && data[j] > key) {
           		data[j+1] = data[j];
           		j = j-1;
       		}
       		data[j+1] = key;
   		}
	}
	
};