#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

// declare function
void binary(int i);

int main() {

	// declare variables
	int n1, n2;
	bool a = false;
	char b = 'k';
	int c = 1;
	double d = 1.1;
	float e = 1.11;
	int f = sizeof(a);
	int g = sizeof(b);
	int h = sizeof(c);
	int i = sizeof(d);
	int j = sizeof(e);

	// print the size
	cout << f << " "<<
	g << " "<<
	h << " "<<
	i << " "<<
	j << endl;

	// input number and out put the value
	cout << "Enter first number";
	cin >> n1;
	cout << "Enter second number";
	cin >> n2;
	cout << "First number raised to the power of the second: " << pow(n1, n2)
			<< endl;
	cout << "The greatest number is " << max(n1, n2) << endl;
	cout << "First Number " << n1 << ", ";
	printf("%x", n1);
	cout << ", ";
	printf("%o", n1);
	cout << ", ";
	binary(n1);
	cout << endl;
	cout << "Second Number " << n2 << ", ";
	printf("%x", n2);
	cout << ", ";
	printf("%o", n2);
	cout << ", ";
	binary(n2);
	cout << endl;
	return 0;
}

// transfer from decimal to binary
void binary(int i) {
	if (i / 2 != 0) {
		binary(i / 2);
	}
	printf("%d", i % 2);
}

