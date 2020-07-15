#include <iostream>
#include "FillUp.h"

using namespace std;

int main(int argc, const char *argv[]) {
    
    //Recieved help from Elena Gonzalez 
    //and 
    // Read in the size from the user
    int* pointer = NULL;
    int size;
    cin >> size;
    pointer = new int[size];
    
    // Create an array of appropriate size
   // int arr[size];
    
    // Call the fillUp function
    fillUp(pointer, size);
    
    // Call the printPos function on last position
    printPos(pointer, size-1); 

    //Have to delete because Memory in stack is limited
    delete []pointer; 
    pointer = NULL; //Set pointer back to Null
    
    return 0;
}