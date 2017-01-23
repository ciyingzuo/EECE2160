/*
 * CarRecords.cpp
 *
 *  Created on: 2016Äê10ÔÂ10ÈÕ
 *      Author: HUNTE
 */

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// represent car
class Car {
private:

	//declare field
	string make;
	string model;
	int year;
	string color;

public:

	//constructor
	Car() {
		make = "";
		model = "";
		year = 0;
		color = "";
	}

	//set fields for car
	void setFields(string mk, string md, int yr, string cl) {
		make = mk;
		model = md;
		year = yr;
		color = cl;
	}

	// return make
	string getMake() {
		return make;
	}

	// return model
	string getModel() {
		return model;
	}

	// return year
	int getYear() {
		return year;
	}

	// return color
	string getColor() {
		return color;
	}
};

// subclass of car, represent carrecords
class CarRecords: public Car {
private:

	// declare fields
	int arraySize; // keep track of number of records
	ifstream infile;
	Car *cars;
public:

	// constructor
	CarRecords(int size) {
		int yr;
		arraySize = 0;
		cars = new Car[size];
		string mk, md, sep, cl;
		int count = 0;
		infile.open("CarRecords.txt");
		while(infile >> mk >> md >> yr >> sep >> cl) {
			Car c;
			c.setFields(mk, md, yr, cl);
			cars[count] = c;
			count++;
			arraySize++;
		} // Reads file records to array
	}

	// deconstructor
	~CarRecords();

	// print the records
	void printCarRecords() {
		cout << "PRINTING " << arraySize << " RECORDS!" << endl << endl;
		cout << "---------------------" << endl;
		for (int i = 0; i < arraySize; i++) {
			Car newCar1;
			newCar1 = cars[i];
			cout << newCar1.getMake() << newCar1.getModel() << newCar1.getYear() << "," << newCar1.getColor()
					<< endl;
		}
		cout << endl;
	}

	// sort cars by make
	void sort_cars_by_make() {
		cout << "SORTING RECORDS BY MAKE....." << endl << endl;;
		int count = 1;
		int n;
		for (int i = 0; i < arraySize; i++) {
			Car temp = cars[i];
			n = i;
			for (int j = count; j < arraySize; j++) {
				Car temp2 = cars[j];
				if (temp.getMake().compare(temp2.getMake()) <= 0) {
				} else {
					temp = temp2;
					n = j;
				}
			}
			Car temp1 = cars[i];
			cars[i] = temp;
			cars[n] = temp1;
			count++;
		}
	}

	// sort cars by year by descending order
	void sort_cars_by_year() {
		cout << "SORTING RECORDS BY YEAR....." << endl << endl;
		int count = 1;
		int n;
		for (int i = 0; i < arraySize; i++) {
			Car temp = cars[i];
			n = i;
			for (int j = count; j < arraySize; j++) {
				Car temp2 = cars[j];
				if (temp.getYear() > temp2.getYear()) {
				} else {
					temp = temp2;
					n = j;
				}
			}
			Car temp1 = cars[i];
			cars[i] = temp;
			cars[n] = temp1;
			count++;
		}
	}

	// print the same car
	void print_duplicates() {
		cout << "CHECKING FOR DUPLICATES..." << endl;
		Car *c1 = cars;
		int count = 1;
		for (int i = 0; i < arraySize; i++) {
			Car temp = c1[i];
			for (int j = count; j < arraySize; j++) {
				Car temp2 = c1[j];
				if ((temp.getMake() == (temp2.getMake())
						&& (temp.getYear() == temp2.getYear())
						&& (temp.getModel() == temp2.getModel())
						&& temp.getColor() == temp2.getColor())) {
					cout << temp.getMake() << temp.getYear() << ","
							<< temp.getModel() << temp.getColor()
							<< endl;
				}
			}
			count++;
		}
	}
};


int main() {

	// declare variable
	int numRecs;
	cout << "Number or Records to read? ";
	cin >> numRecs;
	CarRecords *cr = new CarRecords(numRecs);
// Print car records
	cr->printCarRecords();
// Sort by Year
	cr->sort_cars_by_year();
// Print car records
	cr->printCarRecords();
// Sort by Make
	cr->sort_cars_by_make();
// Print car records
	cr->printCarRecords();
// Check for Duplicates
	cr->print_duplicates();
} // end main
