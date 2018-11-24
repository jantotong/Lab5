#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include "BST.h"
using std::cout;
using std::cin;
using std::string;
using std::ofstream; 
using std::wofstream;
using std::endl;
using std::getline;


// Driver Program to test above functions 
int main()
{
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

	noufile << name.printPostorder() << endl;

	cout << "Pre-Order for names: " << endl;
	noufile << "Pre-Order Names: " << endl;

	noufile << name.printPreorder() << endl;

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

	boufile << birthday.printInorder() << endl;

	cout << "Breadth-First for Birthdays: " << endl;
	boufile << "Breadth-First Birthdays: " << endl;

	

	// Close the file 
	infile.close();
	boufile.close();
	noufile.close();
	system("pause");
	return 0;
}
