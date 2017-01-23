/*
 * main.cpp
 *
 *  Created on: 2016Äê10ÔÂ11ÈÕ
 *      Author: HUNTE
 */
#include"HW2P2.h"
#include<iostream>
#include<string>
using namespace std;

// create and print furniture
int main() {

	// declare variables
	string nt, wt, nb, sb;

	// create table
	cout << "Creating table...\n";
	cout << "Enter name: ";
	cin >> nt;
	cout << "Enter wood type (Pine, Oak): ";
	cin >> wt;
	Table myTable(nt, wt);

	// create bed
	cout << "\nCreating bed...\n";
	cout << "Enter the name: ";
	cin >> nb;
	cout << "Enter the size (Twin, Full, Queen, King): ";
	cin >> sb;
	Bed myBed(nb, sb);

	// print object
	cout << "\nPrinting Objects\n" << endl;
	cout << nt << ":\n";
	myTable.print();

	cout << nb << ":\n";
	myBed.print();
}
