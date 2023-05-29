#include "MyString.h"
#include <iostream>
using namespace std;


char* MyString::getData()
{
	return data;
}

void MyString::inputString()
{
	cout << "Введіть потрібні символи: ";
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

void MyString::MyStrcpy(MyString& obj)// копіювання рядків
{
	delete[] data;
	length = obj.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, obj.data);

}
bool MyString::MyStrStr(const char* str)// Пошук підрядка у рядку
{
	return strstr(data, str) != nullptr;
}
int  MyString::MyChr(char c) //Пошук символу в рядку (індекс знайденого символу, або -1)
{
	char lowercaseC = tolower(c); // перетворюємо введений символ у нижній регістр, бібліотека cctype
	char uppercaseC = toupper(c); // перетворюємо введений символ у верхній регістр бібліотека cctype
	for (int i = 0; i < length; i++)
	{
		if (data[i] == lowercaseC || data[i] == uppercaseC)
			return i;
	}
	return -1;

}
int MyString::MyStrLen()// повертає довжину строки
{
	int len = 0;
	for (int i = 0; data[i] != '\0'; i++)

	{
		len++;
	}
	return len;
}
void MyString::MyStrCat(MyString& b) // об'єднання рядків
{
	int associationLength = length + b.length;
	char* newData = new char[associationLength + 1];
	strcpy_s(newData, length + 1, data);// Копіюємо рядок this->data в newData
	strcat_s(newData, associationLength + 1, b.data);// Об'єднуємо рядки		
	delete[] data;
	data = newData;
	length = associationLength;
}
void MyString::MyDelChr(char c) // видаляє вказаний символ
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
int MyString::MyStrCmp(MyString& b) // порівняння рядків   
{
	return strcmp(data, b.data);
}
//-1 – перший рядок менший за другий
//1 – перша більше ніж друга
//	0 – рядки рівні!
int MyString::count(0);
