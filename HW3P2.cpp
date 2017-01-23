#include <stdio.h>
#include <cstdlib>
#include <iostream>


using namespace std;

int main()
{
	// declare functions and variables
	int subtract(int x, int y);
	void binary(int i);
	int a, b, c = 0;
	cout << "Enter two numbers" << endl;
	cin >> a >> b;
	int sum = a^b^c, c2;
	c = ((c&a) | (a&b) | (c&b)) << 1;
	while (c) {
		c2 = (c&sum) << 1;
		sum ^= c;
		c = c2;
	}
	cout << "The sum is ";
	printf("%d\n", sum);
	cout << "The difference is ";
	printf("%d\n", subtract(a, b));
	cout << "Binary for first number: ";
	binary(a);
	cout << "\nBinary for second number: ";
	binary(b);
}

// subtract two number by logic operation
int subtract(int x, int y)
{
	if (y == 0)
		return x;
	return subtract(x ^ y, (~x & y) << 1);
}

// transfer integer to binary
void binary(int i) {
	if (i / 2 != 0) {
		binary(i / 2);
	}
	printf("%d", i % 2);
}
