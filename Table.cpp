/*
 * Table.cpp
 *
 *  Created on: 2016��10��11��
 *      Author: HUNTE
 */
#include"HW2P2.h"
#include<iostream>
#include<string>
using namespace std;

// constructor
Table::Table(string n, string w):Furniture(n) {
	wood = "";
	if (w == "Pine" || w == "Oak") {
		wood = w;
	} else {
		cout << "Invalid size of string" << endl;
	}
}

// print table
void Table::print() {
	Furniture::print();
	cout << "wood: " << wood << endl;
}
