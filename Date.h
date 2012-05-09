#pragma once
#include <fstream>
#include <string>
using namespace std;
struct Date 
{
//public:
	//friend istream & operator>>(istream & in, Date & s);
	//friend bool writeDate(ofstream & out, const Date & s);
	friend bool readDate(ifstream & in, Date & s);
	Date();
	Date(int , int , int);
	~Date(){}
	void display() const;
	bool operator<(const Date&) const;
	static int length[13];//={0,31,28,30,31,30,31,30,31,30,31,30,31}; //skip month 0
//private:
	int month, day, year;

};
istream & operator>>(istream & in, Date&  s);
ostream & operator<<(ostream & out, const  Date&  s);
bool writeDate(ofstream & out, const Date & s);
bool readDate(ifstream & in, Date & s);