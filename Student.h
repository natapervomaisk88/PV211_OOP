#pragma once
class Student
{
	int id;
	int age;
	char* name = nullptr;
public:
	Student();
	Student(int id, int age, char* name);
	Student(const Student& obj); //конструктор копирования
	void show() const;
	int getAge() const;
	int getId() const;
	~Student();
};

