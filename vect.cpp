#include <iostream>
#define DEBUG true //for some debugging information
using namespace std;

// Function Initialize
// 	Initializes default values for vector
void Initialize();

// Function Finalize
// 	Deletes vector memory space
void Finalize();

// Function Grow
// 	Params: add
// 	Increases memory space allocated
void Grow(int add);

// Function AddElement
// 	Adds a new value to the end of the array
void AddElement();

// Function PrintVector
// 	Prints vector
void PrintVector();

// Function RemoveElement
// 	Removes the last element from the array
// 	Calls Shink if too much memory is allocated
void RemoveElement();

// Function Shrink
// 	Removes half the memory allocated from vector
void Shrink();

// Function InsertElement
// 	Inserts element at designated index
void InsertElement();


// Global variables for the vector
double *v;
int count; // how many elements have been used
int size; // how much memory is allocated

int main(){
	Initialize(); // sets size to 2 and count to 0
	int op = -1; // "nothing chosen"
	while(op < 0){ //while no choice or invalid choice
		if(DEBUG)cout<<"Vector Size: "<<size<<" Count: "<<count<<endl;
		cout<<"Main menu:\n1. Print the array\n2. Append element at the end\n3. Remove last element\n4. Insert one element\n5. Exit\nSelect an option: ";
		cin>>op;cout<<endl; //print menu and ask for input
		switch(op){
			case 1:
				cout<<"You selected \"Print the Array\"!\n";
				PrintVector();
				break;
			case 2:
				cout<<"You selected \"Append element at the end\"!\n";
				AddElement();
				break;
			case 3:
				cout<<"You selected \"Remove last element\"!\n";
				RemoveElement();
				break;
			case 4:
				cout<<"You selected \"Insert one element\"!\n";
				InsertElement();
				break;
			case 5:
				cout<<"Quitting...\n";
				return 0;
			default:
				cout<<"Error! Invalid Input\n";
		}
		cout<<endl;
		op = -1;
	}
		
	Finalize(); // deletes allocated memory
	return 0;
}

void Initialize(){
	count = 0;
	size = 2;
	v = new double[size]; //allocate the memory space
	return; //just good practice
}

void Finalize(){
	delete v;
	return;
}

void Grow(int add){
	double *temp;
	temp = new double[size+add];
	if(DEBUG)cout<<"Vector Grown!\nOld vector capacity: "<<size<<"\n";
	for(int i=0;i<size;i++){
		temp[i] = v[i]; //copies old vector into new vector
	}
	if(DEBUG)cout<<"New vector capacity: "<<size+add<<"\n";;
	delete v; //frees memory space
	v = temp; //points to new bigger memory space
	size += add; //recounts the size of the vector
	return;
}

void AddElement(){
	double val;
	cout<<"Enter a new value: "; cin >> val;
	if(count < size){ // if theres space
		v[count] = val;
	} else {
		Grow(1); //if there isn't grow the vector
		v[count] = val;
	}
	count++;
	return;
}

void PrintVector(){
	cout<<"Your Vector:\n\t";
	for (int i = 0; i < count; i++) cout<<v[i]<<" "; //cycle through elements and print	
	cout<<endl;
	return;
}


void RemoveElement(){
	if(count != 0) { //if the vector isn't empty
		count--; //pretend the last value doesn't exist
		if(1.0*count/size <= 0.3)Shrink(); //if less than 30% then shrink the vector
	}
	else cout<<"Error: Trying to remove empty vector!\n";
	return;
}

void Shrink(){
	double *temp;
	temp = new double[size/2];
	if(DEBUG)cout<<"Vector Shrunk!\nOld vector capacity: "<<size<<"\n";
	for(int i=0;i<size/2;i++){
		temp[i] = v[i]; //copies old vector into new vector
	}
	if(DEBUG)cout<<"New vector capacity: "<<size/2<<"\n";;
	delete v; //frees memory space
	v = temp; //points to new bigger memory space
	size /= 2;
	return;
}

void InsertElement(){
	int idx;
	double elmt;
	cout<<"Enter the index of new element: "; cin >> idx;
	cout<<"Enter the new element: "; cin >> elmt;
	if( idx > count ) { //if the index requested isn't a part of your vector
		cout<<"Error: Invalid position!\n";
	} else if (idx == count){ //if it's a new position, grow the vector
		Grow(1);
		v[idx] = elmt;
		count++;
	}
	else { //for replacement operations
		v[idx] = elmt;
	}
	return;
}
