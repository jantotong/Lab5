#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include "Stack.h"
#include "BST.h"
using std::cout;
using std::cin;
using std::string;
using std::ofstream; 
using std::endl;
using std::getline;


// Driver Program to test above functions 
int main()
{
	Stack <int*> stackptr;
	int i;
	BST<string> name;
	BST<string> birthday;
	ofstream noufile;
	ofstream boufile;
	noufile.open("NamesOutput.txt");
	boufile.open("BirthdaysOutput.txt");

	ifstream infile;
	infile.open("InputData.txt");
	string bdaya[99], namea[99];
	string str = "";


	if (infile.is_open()) {
		for (i = 0; !infile.eof(); i++) {
			getline(infile, namea[i]);
			getline(infile, bdaya[i]);
		}
	}

	noufile << "Names File:" << endl;
	cout << "Names File:" << endl;

	for (int j = 0; j<i; j++) {
		cout << "Name: " << namea[j]<< "\tBirthday: " << bdaya[j] << endl;
		noufile << "Name: " << namea[j] << "\tBirthday: " << bdaya[j] << endl;
		name.insert(namea[j]);
	}

	cout << "Post-Order for Names: " << endl;
	noufile << "Post-Order Names: " << endl;

	name.printPostorder();
	noufile << name.ouPostorder();

	name.ouEmpty(); //empty string

	cout << "Pre-Order for names: " << endl;
	noufile << "\nPre-Order Names: " << endl;

	name.printPreorder();
	noufile << name.ouPreorder();

	name.ouEmpty();
	//Bday Part
	boufile << "Birthday File:" << endl;
	cout << endl<<"Birthday File:" << endl;

	for (int j = 0; j < i; j++) {
		cout << "Name: " << namea[j] << "\tBirthday: " << bdaya[j] << endl;
		boufile << "Name: " << namea[j] << "\tBirthday: " << bdaya[j] << endl;
		birthday.insert(bdaya[j]);
	}

	cout << "In-Order for Birthdays: " << endl;
	boufile << "In-Order Birthdays: " << endl;

	birthday.printInorder();
	boufile << birthday.ouInorder();

	birthday.ouEmpty(); 

	cout << "Breadth-First for Birthdays: " << endl;
	boufile << "\nBreadth-First Birthdays: " << endl;

	birthday.printBFirst();
	boufile << birthday.ouBFirst();

	// Close the file 
	infile.close();
	boufile.close();
	noufile.close();
	system("pause");
	return 0;
}
