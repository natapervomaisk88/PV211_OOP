#include "MyString.h"
#include <iostream>
using namespace std;


char* MyString::getData()
{
	return data;
}

void MyString::inputString()
{
	cout << "������ ������ �������: ";
	cin.getline(data, length);
}

void MyString::printString()

{
	cout << data << endl << endl;

};

int MyString::getCount()
{
	return count;
}

MyString::~MyString()
{
	count--;
	if (data != nullptr)

		delete[] data;
}

MyString::MyString() : MyString::MyString(80) {}

MyString::MyString(int size)
{
	length = size;
	data = new char[length + 1];
	count++;
}

MyString::MyString(const char* user) : MyString::MyString(strlen(user))
{
	if (user != nullptr)
	{
		strcpy_s(data, length + 1, user);
	}
}

void MyString::MyStrcpy(MyString& obj)// ��������� �����
{
	delete[] data;
	length = obj.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, obj.data);

}
bool MyString::MyStrStr(const char* str)// ����� ������� � �����
{
	return strstr(data, str) != nullptr;
}
int  MyString::MyChr(char c) //����� ������� � ����� (������ ���������� �������, ��� -1)
{
	char lowercaseC = tolower(c); // ������������ �������� ������ � ����� ������, �������� cctype
	char uppercaseC = toupper(c); // ������������ �������� ������ � ������ ������ �������� cctype
	for (int i = 0; i < length; i++)
	{
		if (data[i] == lowercaseC || data[i] == uppercaseC)
			return i;
	}
	return -1;

}
int MyString::MyStrLen()// ������� ������� ������
{
	int len = 0;
	for (int i = 0; data[i] != '\0'; i++)

	{
		len++;
	}
	return len;
}
void MyString::MyStrCat(MyString& b) // ��'������� �����
{
	int associationLength = length + b.length;
	char* newData = new char[associationLength + 1];
	strcpy_s(newData, length + 1, data);// ������� ����� this->data � newData
	strcat_s(newData, associationLength + 1, b.data);// ��'������ �����		
	delete[] data;
	data = newData;
	length = associationLength;
}
void MyString::MyDelChr(char c) // ������� �������� ������
{
	int delCount = 0;
	char lowercaseC = tolower(c);
	char uppercaseC = toupper(c);
	for (int i = 0; i < length; i++)
	{
		if (data[i] == lowercaseC || data[i] == uppercaseC)
		{
			delCount++;
		}
		else
		{
			data[i - delCount] = data[i];
		}
	}
	length -= delCount;
	data[length] = '\0';

}
int MyString::MyStrCmp(MyString& b) // ��������� �����   
{
	return strcmp(data, b.data);
}
//-1 � ������ ����� ������ �� ������
//1 � ����� ����� �� �����
//	0 � ����� ���!
int MyString::count(0);
