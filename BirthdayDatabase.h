#ifndef BIRTHDAY_DATABASE_H
#define BIRTHDAY_DATABASE_H
// gratuitously inspired by StudentDatabase
#include "Birthday.h"
#include <set>

class BirthdayDatabase {
public:
	BirthdayDatabase();
	~BirthdayDatabase();
	void run();
private:
	char displayMenuReadChoice();

	typedef set<Birthday*, Birthday::ByDate> DateSet;
	DateSet birthdaysByDate;
	typedef multiset<Birthday*, Birthday::ByName> NameSet;
	NameSet birthdaysByName;
	typedef multiset<Birthday*, Birthday::ByMonth> MonthSet;
	MonthSet birthdaysByMonth;
};

#endif
