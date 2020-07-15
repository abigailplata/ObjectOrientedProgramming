#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
        int n; //to hold number
        char c; //to hold character

        string output=""; //to save output

        cin>>c>>n;

        while(true) {

                if(n>=0){

                        //add c to output number times

                        while(n>0){

                                output = output + c;

                                n--;

                                }
                        cin >> c >> n;

                        } else if(n == -1) {

                                output = output + "\n";
                                cin >> c >> n;

                        } else if(n == -2) {

                                break;

                        }

        }
        cout << output;
        return 0;
}
