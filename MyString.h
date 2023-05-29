#pragma once
class MyString
{
private:

	char* data;
	int length;
	static int count;

public:

	char* getData();

	void inputString();

	void printString();

	static int getCount();

	~MyString();

	MyString();

	MyString(int size);

	MyString(const char* user);

	void MyStrcpy(MyString& obj);// копіювання рядків
	
	bool MyStrStr(const char* str);// Пошук підрядка у рядку
	;
	int  MyChr(char c); //Пошук символу в рядку (індекс знайденого символу, або -1)
	
	int MyStrLen();// повертає довжину строки
	
	void MyStrCat(MyString& b); // об'єднання рядків
	
	void MyDelChr(char c); // видаляє вказаний символ
	
	int MyStrCmp(MyString& b); // порівняння рядків   

	//-1 – перший рядок менший за другий
	//1 – перша більше ніж друга
	//	0 – рядки рівні!


};

