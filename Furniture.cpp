/*
 * Furniture.cpp
 *
 *  Created on: 2016Äê10ÔÂ11ÈÕ
 *      Author: HUNTE
 */
#include"HW2P2.h"
#include<iostream>
#include<string>
using namespace std;

// constructor
Furniture::Furniture(string n) {
	name = n;
	width = 0;
	height = 0;
	depth = 0;
	this->ReadDimentions();
}

// read dementions for object
void Furniture::ReadDimentions() {
	double w;
	double h;
	double d;
	bool done = false;
	while (!done) {
		cout << "Enter width: ";
		cin >> w;
		cout << "Enter height: ";
		cin >> h;
		cout << "Enter depth: ";
		cin >> d;
		if (w >= 0 && h >= 0 && d >= 0) {
			width = w;
			height = h;
			depth = d;
			done = true;
		}
	}
}

// print furniture
void Furniture::print() {
	cout << "Width: " << width << ", " << "Height: " << height << ", "
			<< "Depth: " << depth << endl;
}

