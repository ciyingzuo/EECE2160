#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// create struct for cars
struct Car {
	string brand;
	string type;
	int year;
	string color;
};

// insert cars from file to array
void insert_array(Car *c) {
	string brand, type, color, sep;
	int count = 0, year;
	ifstream inf;
	inf.open("CarRecords.txt");
	while (inf >> brand >> type >> year >> sep >> color) {
		Car *newCar;
		newCar = new Car;
		newCar->brand = brand.substr(0, brand.size() - 1);
		newCar->type = type.substr(0, type.size() - 1);
		newCar->year = year;
		newCar->color = color.substr(0, type.size() - 1);
		c[count] = *newCar;
		count++;
		delete newCar;
	}
}

// print the singal car
void print_cars_array(Car *c) {
	for (int i = 0; i <= 9; i++) {
		Car newCar;
		newCar = c[i];
		cout << newCar.brand << ", " << newCar.type << ", " << newCar.year
				<< ", " << newCar.color << endl;
	}
}

// sort cars by year ascending
void sort_cars_by_year(Car *c) {
	int count = 1;
	int n;
	for (int i = 0; i <= 9; i++) {
		Car temp = c[i];
		for (int j = count; j <= 9; j++) {
			Car temp2 = c[j];
			if (temp.year <= temp2.year) {
			}
			else { temp = temp2;
			n = j;
			}
		}
		Car temp1 = c[i];
		c[i] = temp;
		c[n] = temp1;
		count++;
	}
}

// return true if two cars are same
bool same(Car c1, Car c2) {
	if ((c1.brand == c2.brand) && (c1.brand == c2.brand) && (c1.year == c2.year)
			&& (c1.type == c2.type)) {
		return true;
	} else {
		return false;
	}
}

// print the same cars
void print_duplicates(Car *c) {
	Car *c1 = c;
	int count = 1;
	for (int i = 0; i <= 9; i++) {
		Car temp = c1[i];
		for (int j = count; j <= 9; j++) {
			Car temp2 = c1[j];
			if (same(temp, temp2)) {
				cout << temp.brand << ", " << temp.type << ", " << temp.year
						<< ", " << temp.color << endl;
			}
		}
		count++;
	}
}

int main() {

	// declare variables
	Car *c;
	c = new Car[10];
	int state = 0;

	// print main menu
	while (state == 0) {
		cout << "Main menu:" << endl;
		cout << "1. Print the cars array" << endl;
		cout << "2. Insert car records into a sorted array" << endl;
		cout << "3. Sort cars by year" << endl;
		cout << "4. Print duplicates" << endl;
		cout << "5. Exit" << endl;
		cout << "Select an option: ";
		cin >> state;
		cout << endl;

		// out put results
		switch (state) {
		case 1:
			cout << "You selected \"Print the cars array\"" << endl;
			print_cars_array(c);
			break;
		case 2:
			cout << "You selected \"Insert car records into a sorted array\""
					<< endl;
			insert_array(c);
			break;
		case 3:
			cout << "You selected \"Sort cars by year\"" << endl;
			sort_cars_by_year(c);
			break;
		case 4:
			cout << "You selected \"Print duplicates\"" << endl;
			print_duplicates(c);
			break;
		case 5:
			cout << "Exit program" << endl;
			return 0;
		default:
			cout << "Choose an valid option" << endl;
		}
		cout << endl;
		state = 0;
	}
}
