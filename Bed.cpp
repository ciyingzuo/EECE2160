/*
 * Bed.cpp
 *
 *  Created on: 2016Äê10ÔÂ11ÈÕ
 *      Author: HUNTE
 */
#include"HW2P2.h"
#include<iostream>
#include<string>
using namespace std;

// constructor for bed
Bed::Bed(string n, string s):Furniture(n) {
	size = "";
	if (s == "Twin" || s == "Full" || s == "Queen" || s == "King") {
		size = s;
	} else {
		cout << "Invalid size of string" << endl;
	}
}

// print bed
void Bed::print() {
	Furniture::print();
	cout << "size: " << size << endl;
}
