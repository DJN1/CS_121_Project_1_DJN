/*
File: Source.cpp
Name: David Niederweis
Date: 09/12/2019
Course: CS121-03 - Computer Science I
Description: Program to calculate pay based on wage and hours.
*/

// imports for main functionality, strings, file I/O, I/O manipulation
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// main function
int main()
{
	// variables to store employee info
	ifstream inFile; 
	string returnStr;
	string id;
	string name;
	string hours;
	string wage;
	float pay;
	
	// set for floats to be non-scientific
	cout << fixed;
	// sets 2 decimals for floats
	cout << setprecision(2);

	// open file with employee data
	inFile.open("hours.txt");
	
	// check that file opened successfully
	if (!inFile) {
		cout << "Failed to open input file" << endl;
	}

	// print header
	cout << "      Payouts for previous pay period      " << endl;
	cout << "-------------------------------------------" << endl;

	// loops through file while not at end of file
	while (!inFile.eof()) {
		// get employee id
		getline(inFile, id);
		//get employee name
		getline(inFile, name);
		//get employee hours 
		getline(inFile, hours);
		// get employee wage
		getline(inFile, wage);

		// calculate employee pay
		pay = (stof(hours) * stof(wage));

		// double check if at end of file, otherwise c++ double prints
		if (!inFile.eof()) {
			// print out employee id, name and pay for pay period
			cout << id + "\t\t" << name + "\t" << pay << endl;
		}

	}
	// close file after dont with processing
	inFile.close();
	// avoid the immediate closing of the output terminal on windows
	system("pause");
	// return 0 because main has int return type
	return 0;
}