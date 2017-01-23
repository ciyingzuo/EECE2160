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
	Car *next;
};

// create struct for list
struct List {
	// First Car in the list. A value equal to NULL indicates that the
	// list is empty.
	Car *head;
	// Current Car in the list. A value equal to NULL indicates a
	// past-the-end position.
	Car *current;
	// Pointer to the element appearing before 'current'. It can be NULL if
	// 'current' is NULL, or if 'current' is the first element in the list.
	Car *previous;
	int count;
};

// initialize the list
void ListInitialize(List *list) {
	list->head = NULL;
	list->current = NULL;
	list->previous = NULL;
	list->count = 0;
}

// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(List *list) {
	if (list->current) {
		list->previous = list->current;
		list->current = list->current->next;
	}
}

// Move the current position to the first element in the list.
void ListHead(List *list) {
	list->previous = NULL;
	list->current = list->head;
}

// Get the element at the current position, or NULL if the current position is
// past-the-end.
Car *ListGet(List *list) {
	return list->current;
}

// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(List *list, Car *car) {
	// Set 'next' pointer of current element
	car->next = list->current;
	// Set 'next' pointer of previous element. Treat the special case where
	// the current element was the head of the list.
	if (list->current == list->head)
		list->head = car;
	else
		list->previous->next = car;
	// Set the current element to the new person
	list->current = car;
}

// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(List *list) {
	// Ignore if current element is past-the-end
	if (!list->current)
		return;
	// Remove element. Consider special case where the current element is
	// in the head of the list.
	if (list->current == list->head)
		list->head = list->current->next;
	else
		list->previous->next = list->current->next;
	// Free element, but save pointer to next element first.
	Car *next = list->current->next;
	delete list->current;
	// Set new current element
	list->current = next;
}

// insert cars to list from file
void insert_linkedList(List *list) {
	string brand, type, color, sep;
	int year;
	ifstream inf;
	inf.open("CarRecords.txt");
	while (inf >> brand >> type >> year >> sep >> color) {
		Car *newCar;
		newCar = new Car;
		newCar->brand = brand.substr(0, brand.size() - 1);
		newCar->type = type.substr(0, type.size() - 1);
		newCar->year = year;
		newCar->color = color.substr(0, type.size() - 1);
		newCar->next = NULL;
		ListHead(list); //go to beginning of the list
		ListInsert(list, newCar); //add the new person to the end of the list
	}
}

// print the singal car
void print_cars_list(Car *car) {
	cout << car->brand << ", " << car->type << ", " << car->year << ", "
			<< car->color << endl;
}

// sort cars by color
void sort_cars(Car *c) {
	int count = 1;
	int n;
	for (int i = 0; i <= 9; i++) {
		Car temp = c[i];
		for (int j = count; j <= 9; j++) {
			Car temp2 = c[j];
			if (temp.color.compare(temp2.color) <= 0) {
			} else {
				temp = temp2;
				n = j;
			}
		}
		Car temp1 = c[i];
		c[i] = temp;
		c[n] = temp1;
		count++;
	}
}

// sort cars by color
void sort_cars_by_color(List *list) {
	Car *c;
	c = new Car[10];

// a failed attempt, i keep the code here
// if i want do further edit
//
//	for (int i = 0; i <= 9; i++) {
//		ListHead(list);
//		for (int j = 8; j >= 0; j--) {
//			Car *c = ListGet(list);
//			Car *cp = list->previous;
//			ListNext(list);
//			Car *c1 = ListGet(list);
//			if (c->color.compare(c1->color) < 0) {
//				if (cp != NULL) {
//					cp->next = c1;
//					c->next = c1->next;
//					c1->next = c;
//				} else {
//					c->next = c1->next;
//					c1->next = c;
//				}
//			}
//		}
//	}
//}

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
	sort_cars(c);
	delete list;
	ListInitialize(list);
	ListHead(list);
	for (int i = 0; i <= 9; i++) {
		ListHead(list); //go to beginning of the list
		while (ListGet(list) != NULL) { //traverse list until the end is reached
			ListNext(list);
		}
		ListInsert(list, c); //add the new person to the end of the list
		c++;
	}
}

// Determine if two cars are same
bool same(Car *c1, Car *c2) {
	if ((c1->brand == c2->brand) && (c1->brand == c2->brand)
			&& (c1->year == c2->year) && (c1->type == c2->type)) {
		return true;
	} else {
		return false;
	}
}

// print same cars
void print_duplicates(List *list) {
	int count = 1;
	for (int i = 0; i <= 8; i++) {
		ListHead(list);
		for (int k = count; k > 1; k--) {
			ListNext(list);
		}
		Car *temp = ListGet(list);
		for (int j = count; j <= 9; j++) {
			ListNext(list);
			Car *temp2 = ListGet(list);
			if (same(temp, temp2)) {
				cout << temp->brand << ", " << temp->type << ", " << temp->year
						<< ", " << temp->color << endl;
			}
		}
		count++;
	}
}

int main() {

	// declare variables
	List list;				// Create the main list
	ListInitialize(&list);			// Initialize the list
	int state = 0;

	// display the main menu
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

		switch (state) {
		case 1: {
			cout << "You selected \"Print the cars array\"" << endl;
			ListHead(&list);
			for (int i = 0; i <= 9; i++) {
				Car *c = ListGet(&list);
				print_cars_list(c);
				ListNext(&list);
			}
			break;
		}
		case 2:
			cout << "You selected \"Insert car records into a sorted array\""
					<< endl;
			ListHead(&list);
			insert_linkedList(&list);
			break;
		case 3:
			cout << "You selected \"Sort cars by color\"" << endl;
			ListHead(&list);
			sort_cars_by_color(&list);
			break;
		case 4:
			cout << "You selected \"Print duplicates\"" << endl;
			ListHead(&list);
			print_duplicates(&list);
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
