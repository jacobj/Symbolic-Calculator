/*
 This file tests the Integer class
 */

#include <iostream>
#include "Integer.h"
using namespace std;

int main()
{
	long first, second;
    
	// Create Integer objects
	Integer coeff1;
	Integer coeff2;
	Integer coeff3;
    
	// obtain user inputed values
	cout << "Enter first value: " ;
	cin >> first;
	cout << endl;
	cout << "Enter second value: ";
	cin >> second;
	cout << endl;
    
	// store user input values
	coeff1.setValue(first);
	coeff2.setValue(second);
    
    long testSize = 8;
    Integer testCase[testSize];
    
    testCase[0] = coeff1 + coeff2;
    testCase[1] = coeff1 + coeff3;
    testCase[2] = coeff1 - coeff2;
    testCase[3] = coeff2 - coeff1;
    testCase[4] = coeff1 * coeff2;
    testCase[5] = coeff3 * coeff2;
    testCase[6] = coeff2 / coeff1;
    testCase[7] = coeff2 / coeff3;
    
    for(int i = 0; i < testSize; i++) {
    	cout << testCase[i].getValue() << endl;
    }
    cout<<coeff1.toDouble();
    
	return 0;
}
