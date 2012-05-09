#include "StdAfx.h"
#include "Date.h"
#include <iostream>
#include <sstream>

int Date::length[13]={0,31,28,30,31,30,31,30,31,30,31,30,31};
bool writeDate(ofstream & out, const Date & s) {
	out << s.month << "#" ;
	out << s.day << "#" << s.year << endl;
	return (out != NULL);
}
ostream & operator<<(ostream & out, const Date& s)
{
	s.display();
	return out;
}

bool readDate(ifstream & in, Date & s) {
	/*TODO readDate*/
	string m,d,y;
	
	getline(in, m, '#');
	stringstream ss(m);
	ss >> s.month;
	getline(in, d, '#');
	stringstream ssd(d);
	ss >> s.day;
	getline(in, y, '#');
	stringstream ssy(y);
	ss >> s.year;
	
	

	return (in != NULL);
}
istream & operator>>(istream & in, Date& s) {
	if (&in == &cin)
		cout << "Enter the Birthday's month: ";
	in >> s.month;
	if (&in == &cin)
		cout << "Enter the Birthday's day: ";
	in >>s.day;
	if (&in == &cin)
		cout << "Enter the Birthday's year: ";
	in >> s.year;
	in.ignore(); // ignore '\n'
	return in;
}
Date::Date():month(1),day(1),year(1)
{
}
Date::Date(int mn,int dy,int yr)
{
	
	month=max(1,mn);
	month=min(month,12);
	day=max(1,dy);
	day=min(dy,length[month]);
	year=max(1,yr);

}
//TODO const
void Date::display() const
{
	static char * name[]={"nothing","January","February","March","April",
						"May","June","July","August","September","October",
						"November","December"};
	cout << name[month]<<" "<<day<<","<<year;
}
bool Date::operator<(const Date& other) const
{
	if(month != other.month)
		return month < other.month;
	else if (month < other.month && day!=other.day)
		return day < other.day;
	else
		return false;

}