#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>

using namespace std;

struct OwnerOfDocument
{
	string name, surname, username, email;
	int yearOfBirthdate;
};

struct CreatedDateOfDocument
{
	int year, month, day, hour, minute, second;
};

struct Document
{
	string name;
	int size, pageCount;
	OwnerOfDocument owner;
	CreatedDateOfDocument createdDate;
};

#endif