#ifndef Birthday_H
#define Birthday_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
using namespace std;

class Birthday {
	friend class BirthdayDatabase;
	friend class CompareBirthdaysByDate;
	friend bool writeBirthday(ofstream & out, const Birthday & s);
	friend bool readBirthday(ifstream & in, Birthday & s);
	// functions for reading/writing object to a file
	friend ofstream & operator<<(ofstream & out, const Birthday & s);
	friend ifstream & operator>>(ifstream & in, Birthday & s);
	// functions for reading/writing object to other input/output stream (like console)
	friend ostream & operator<<(ostream & out, const Birthday & s);
	friend istream & operator>>(istream & in, Birthday &s);
public:
	//Birthday() : idNumber(0) {} ;
	Birthday() {} ;
	Birthday(ifstream & in);
	//void readIDNumber(istream & in = cin);
	void readDate(istream & in = cin);
	void readDateMonthDay(istream & in = cin);
	//int getIDNumber() const {return idNumber;}
	void readLastName(istream & in = cin);
	string getLastName() const {return lastName;}
	string getFirstName() const {return firstName;}
	void readMonth(istream & in =cin);
	bool operator<(const Birthday & rhs) const {
		//return idNumber < rhs.idNumber;
		return date.month< rhs.date.month;
	}
	
private:
	string lastName;
	string firstName;
	Bir
	//int idNumber;
	//string emailAddress;
	//int month;
	//TODO const Date
	 Date date; //only one birthday
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
		return (s1.date< s2.date);
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