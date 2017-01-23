#include"Calculator.h"
#include"Calculator.cpp"
#include<iostream>
using namespace std;

// represent Arithmetic
class Arithmetic {
private:
	int intData;
	float floatData;
	double doubleData;

	//print the result by calling three method
	template<class T2> void printOperations(T2 obj) {
		cout << obj.getValue1() << " + " << obj.getValue2() << " = " << obj.getSum() << endl;
		cout << obj.getValue1() << " && " << obj.getValue2() << " = " << obj.getLogicalAND() << endl;
		cout << obj.getValue1() << " > " << obj.getValue2() << " = " << obj.isGreater() << endl;
	}

public:

	// constructor
	Arithmetic() {};
	Arithmetic(int i, float f, double d) {
		intData = i;
		floatData = f;
		doubleData = d;
	}

	// operation for interger
	void intOperations(Arithmetic obj) {
		Calculator<int> i(intData, obj.intData);
		printOperations(i);
	}

	// operation for float
	void floatOperations(Arithmetic obj) {
		Calculator<float> f(floatData, obj.floatData);
		printOperations(f);
	}

	// operation for double
	void doubleOperations(Arithmetic obj) {
		Calculator<double> d(doubleData, obj.doubleData);
		printOperations(d);
	}
};

int main() { // Create 1st object
	int int1 = 4;
	float f1 = 10.4;
	double d1 = 20.1;
	Arithmetic object1(int1, f1, d1); // Create 2nd object
	int int2 = 7;
	float f2 = 0.0;
	double d2 = 3.5;
	Arithmetic object2(int2, f2, d2);
	// Check operation on integer data type
	cout << "\nPrinting INTEGER operations..." << endl;
	object1.intOperations(object2);
	// Check operation on float data type
	cout << "\nPrinting FLOAT operations..." << endl;
	object1.floatOperations(object2);
	// Check operation on double data type
	cout << "\nPrinting DOUBLE operations..." << endl;
	object1.doubleOperations(object2); 
} // end main