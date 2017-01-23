#include <iostream>
using namespace std;

int main() {
	int state = 0;
	while (state == 0) {
		cout << "Main menu:" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Fina a Person" << endl;
		cout << "3. Remove a Person" << endl;
		cout << "4. Print the List" << endl;
		cout << "5. Exit" << endl;
		cout << "Select an option: ";
		cin >> state;
		cout << endl;

		switch (state) {
		case 1:
			cout << "You selected \"Add a Person\"" << endl;
			break;
		case 2:
			cout << "You selected \"Fina a Person\"" << endl;
			break;
		case 3:
			cout << "You selected \"Remove a Person\"" << endl;
			break;
		case 4:
			cout << "You selected \"Print the List\"" << endl;
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
	return 0;
}
