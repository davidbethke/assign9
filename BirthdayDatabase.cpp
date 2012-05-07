#include "StdAfx.h"
#include "BirthdayDatabase.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

BirthdayDatabase::BirthdayDatabase() {
	string fname;
	cout << "Enter filename to read database (blank to use default): ";
	getline(cin, fname);
	if (fname.length() == 0)
		fname = "Birthdays.txt";

	Birthday s, *sptr;
	// read Birthday information in from file
	ifstream inFile(fname.data());
	if (inFile) {
		while(readBirthday(inFile,s)) {
			sptr = new Birthday(s);
			birthdaysByDate.insert(sptr);
			birthdaysByName.insert(sptr);
			birthdaysByMonth.insert(sptr);
		}
		inFile.close();
	}
	else
		cout << "Couldn't open Birthdays.txt file. Starting with empty database." << endl;
}

BirthdayDatabase::~BirthdayDatabase() {
	string fname;
	cout << "Enter filename to save database (blank to use default): ";
	getline(cin, fname);
	if (fname.length() == 0)
		fname = "Birthdays.txt";
	ofstream outFile(fname.data());
	if (!outFile)
		cout << "Unable to save Birthday database." << endl;
	DateSet::iterator it;
	for (it = birthdaysByDate.begin(); it != birthdaysByDate.end(); ++it) {
		if (outFile) {
			writeBirthday(outFile, **it);
			delete *it;
		}
	}
	birthdaysByDate.clear();
	birthdaysByName.clear();
}

void BirthdayDatabase::run() {
	char choice;
	Birthday s;
	choice = displayMenuReadChoice();
	do {
		switch(tolower(choice)) {
			case 'a':
				cin >> s;
				birthdaysByDate.insert(new Birthday(s));
				break;
			case 'i':
			{
				s.readIDNumber();
				DateSet::iterator it = birthdaysByDate.find(&s);
				cout << endl << **it << endl << endl;
				break;
			}
			case 'l':
			{
				s.readLastName();
				pair<NameSet::iterator, NameSet::iterator> itpair;
				itpair = birthdaysByName.equal_range(&s);
				NameSet::iterator it;
				for (it = itpair.first; it != itpair.second; ++it)
					cout << endl << **it << endl;
				cout << endl;
				break;
			}
			case 'm':
				break;
			case 'q':
				break;
			default:
				cout << "Invalid choice" << endl;
		}
		choice = displayMenuReadChoice();
	} while(tolower(choice) != 'q');
}

char BirthdayDatabase::displayMenuReadChoice() {
	char ch;
	cout << "Enter your choice: " << endl;
	cout << "A - Add a Birthday" << endl;
	cout << "I - Search by Date" << endl;
	cout << "L - Search by last name" << endl;
	cout << "M - Search by Month" << endl;
	cout << "Q - Quit" << endl;
	cout << "? ";
	cin >> ch;
	cin.ignore();
	return ch;
}