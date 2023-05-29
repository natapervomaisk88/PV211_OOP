#pragma once
class Student
{
	int id;
	int age;
	char* name;
public:
	Student(int id, int age, char* name);
	Student(const Student& obj); //конструктор копирования
	void show();
	~Student();
};

