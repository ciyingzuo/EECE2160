#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// peint the matrix
void print_matrix(int m[][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (j == 2) {
				cout << m[i][j] << endl;
			} else {
				cout << m[i][j] << " ";
			}
		}
	}
}

// transpose by change the value of the matrix
void indexTranspose(int m[][3]) {
	int n[3][3];
	n[0][0] = m[0][0];
	n[1][0] = m[0][1];
	n[2][0] = m[0][2];
	n[0][1] = m[1][0];
	n[1][1] = m[1][1];
	n[2][1] = m[1][2];
	n[0][2] = m[2][0];
	n[1][2] = m[2][1];
	n[2][2] = m[2][2];
	m = n;
	print_matrix(m);
}

// transpose by change the pointer of the matrix
void pointerTranspose(int m[][3]) {
	int *p = &m[0][0];
	int temp;
	temp = *(p + 1);
	*(p + 1) = *(p + 3);
	*(p + 3) = temp;

	temp = *(p + 2);
	*(p + 2) = *(p + 6);
	*(p + 6) = temp;

	temp = *(p + 5);
	*(p + 5) = *(p + 7);
	*(p + 7) = temp;

	print_matrix(m);
}

int main() {

	// declare variables
	char det;
	int m[3][3];

	// if n, will input manually.
	cout << "Input from file? y or n";
	cin >> det;

	if (det == 'n') {
		cout << "Enter numbers separate by space" << endl;
		cin >> m[0][0] >> m[1][0] >> m[2][0] >> m[0][1] >> m[1][1] >> m[2][1]
				>> m[0][2] >> m[1][2] >> m[2][2];
	} else {
		ifstream inf;
		inf.open("CarRecords.txt");
		while (m[0][0] >> m[1][0] >> m[2][0] >> m[0][1] >> m[1][1] >> m[2][1]
				>> m[0][2] >> m[1][2] >> m[2][2]) {
		}
	}

	// transpose the matrix in 2 ways
	print_matrix(m);
	pointerTranspose(m);
	indexTranspose(m);
}

