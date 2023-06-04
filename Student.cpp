#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	name = nullptr;
	id = 0;
	age = 0;
}

Student::Student(int id, int age, char* name)
{
	if (this->name != nullptr)
		delete[] this->name;
	if (name != nullptr)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name)+1, name);
	}
	cout << "Address: " << this << " ";
	cout << "I am construct\n";
	this->id = id; 
	this->age = age;
}

Student::Student(const Student& obj)
{
	cout << "Address" << this << " ";
	cout << "I am construct COPY\n";
	this->id = obj.id;
	this->age = obj.age;
	if (obj.name != nullptr)
	{
		this->name = new char[strlen(obj.name) + 1];
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	}
}



void Student::show() const 
{
	cout << "Address Object " << this << endl;
	cout << "ID: " << id << " Age: " << age << endl;
	if (this->name != nullptr)
		cout << "Name: " << this->name << endl;
}

int Student::getAge() const
{
	return age;
}

int Student::getId() const
{
	return id;
}

Student::~Student()
{
	cout << "Address: " << this << " ";
	cout << "I am destruct\n";
	if (this->name != nullptr)
		delete[] this->name;
}
