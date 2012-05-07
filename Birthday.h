#ifndef Birthday_H
#define Birthday_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
using namespace std;

class Birthday {
	friend bool writeBirthday(ofstream & out, const Birthday & s);
	friend bool readBirthday(ifstream & in, Birthday & s);
	// functions for reading/writing object to a file
	friend ofstream & operator<<(ofstream & out, const Birthday & s);
	friend ifstream & operator>>(ifstream & in, Birthday & s);
	// functions for reading/writing object to other input/output stream (like console)
	friend ostream & operator<<(ostream & out, const Birthday & s);
	friend istream & operator>>(istream & in, Birthday &s);
public:
	Birthday() : idNumber(0) {} ;
	Birthday(ifstream & in);
	void readIDNumber(istream & in = cin);
	int getIDNumber() const {return idNumber;}
	void readLastName(istream & in = cin);
	string getLastName() const {return lastName;}
	string getFirstName() const {return firstName;}
	bool operator<(const Birthday & rhs) const {
		return idNumber < rhs.idNumber;
	}
private:
	string lastName;
	string firstName;
	int idNumber;
	string emailAddress;
	int month;
	Date date;
public:
	class ByDate {
	public:
		bool operator()(const Birthday * s1, const Birthday * s2) {
			return s1->date < s2->date;
		}
	};
	class ByMonth {
	public:
		bool operator()(const Birthday * s1, const Birthday * s2) {
			//return s1->idNumber < s2->idNumber;
			return s1->date.month < s2->date.month;
		}
	};

	class ByName {
	public:
		bool operator()(const Birthday * s1, const Birthday * s2) {
			return s1->lastName < s2->lastName;
		}
	};
};

class CompareBirthdaysByDate {
public:
	// overload operator() to be a lessThan comparison function
	// that is, return true if left-hand argument is less than
	// right-hand argument (and false otherwise).  In this case
	// we will compare Birthdays by their id numbers.
	bool operator()(const Birthday & s1, const Birthday & s2) {
		return (s1.getIDNumber() < s2.getIDNumber());
	}
};

// This one compare Birthdays by their last names
class CompareBirthdaysByLastName {
public:
	bool operator()(const Birthday & s1, const Birthday & s2) {
		return (s1.getLastName() < s2.getLastName());
	}
};
class CompareBirthdaysByMonth {
public:
	bool operator()(const Birthday & s1, const Birthday & s2) {
		return (s1.getLastName() < s2.getLastName());
	}
};

#endif