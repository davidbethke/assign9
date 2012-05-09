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
	MonthSet::iterator it;
	for (it = birthdaysByMonth.begin(); it != birthdaysByMonth.end(); ++it) {
		if (outFile) {
			writeBirthday(outFile, **it);
			cout << "Writing:"<<**it<<endl;
			getchar();
			delete *it;
		}
	}
	birthdaysByDate.clear();
	birthdaysByName.clear();
	birthdaysByMonth.clear();
}

void BirthdayDatabase::run() {
	char choice;
	Birthday s;
	Birthday *sptr=NULL;
	choice = displayMenuReadChoice();
	do {
		switch(tolower(choice)) {
			case 'a':
				cin >> s;
				sptr= new Birthday(s);
				//cout << "adding by date"<<endl;
				birthdaysByDate.insert(sptr);
				//cout << "adding by Name"<<endl;
				birthdaysByName.insert(sptr);
				//cout << "adding by Month"<<endl;
				birthdaysByMonth.insert(sptr);
				//birthdaysByDate.insert(new Birthday(s));
				break;
			case 'i':
			{
				s.readDateMonthDay();
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
			case 'p':
			{
				s.readLastName();
				string searchFor=s.lastName;
				pair<NameSet::iterator, NameSet::iterator> itpair;
				itpair.first = birthdaysByName.lower_bound(&s);
				itpair.second = birthdaysByName.end();
				NameSet::iterator it;
				for (it = itpair.first; it != itpair.second; ++it)
					if(!(**it).lastName.compare(0,searchFor.length(),searchFor))
						cout << endl << **it << endl;
				cout << endl;
				break;
			}
			case 'm':
			{
				s.readMonth();
				pair<MonthSet::iterator, MonthSet::iterator> itpair;
				itpair = birthdaysByMonth.equal_range(&s);
				MonthSet::iterator it;
				for (it = itpair.first; it != itpair.second; ++it)
					cout << endl << **it << endl;
				cout << endl;
			}
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
	cout << "P - Partial Last Name Match" << endl;
	cout << "Q - Quit" << endl;
	cout << "? ";
	cin >> ch;
	cin.ignore();
	return ch;
}