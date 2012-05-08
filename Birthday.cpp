#include "StdAfx.h"
#include "Birthday.h"


bool writeBirthday(ofstream & out, const Birthday & s) {
	out << s.lastName << "#" << s.firstName << "#";
	out << s.idNumber << "#";
	writeDate(out,s.date);
	return (out != NULL);
}

bool readBirthday(ifstream & in, Birthday & s) {
	getline(in, s.lastName, '#');
	getline(in, s.firstName, '#');
	string str;
	getline(in, str, '#');
	stringstream ss(str);
	ss >> s.idNumber;
	//getline(in, s.emailAddress);
	return (in != NULL);
}
ofstream & operator<<(ofstream & out, const Birthday & s) {
	out << s.lastName << "#" << s.firstName << "#";
	out << s.idNumber << "#" << s.emailAddress << endl;
	return out;
}

ifstream & operator>>(ifstream & in, Birthday & s) {
	getline(in, s.lastName, '#');
	getline(in, s.firstName, '#');
	string str;
	getline(in, str, '#');
	stringstream ss(str);
	ss >> s.idNumber;
	getline(in, s.emailAddress);
	return in;
}

ostream & operator<<(ostream & out, const Birthday & s) {
	out << s.firstName << " " << s.lastName << ", id number: " << s.idNumber;
	//out << ", email: " << s.emailAddress;
	out << s.date<<endl;
	return out;
}

istream & operator>>(istream & in, Birthday &s) {
	if (&in == &cin)
		cout << "Enter the Birthday's first name: ";
	getline(in, s.firstName);
	if (&in == &cin)
		cout << "Enter the Birthday's last name: ";
	getline(in, s.lastName);
	
	if(&in == &cin)
		in >> s.date;
	return in;
}

void Birthday::readIDNumber(istream & in) {
	if (&in == &cin)
		cout << "Enter Birthday's ID number: ";
	in >> idNumber;
	in.ignore();
}

void Birthday::readLastName(istream & in) {
	if (&in == &cin)
		cout << "Enter last name: ";
	getline(in, lastName);
}