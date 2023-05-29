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

	void MyStrcpy(MyString& obj);// ��������� �����
	
	bool MyStrStr(const char* str);// ����� ������� � �����
	;
	int  MyChr(char c); //����� ������� � ����� (������ ���������� �������, ��� -1)
	
	int MyStrLen();// ������� ������� ������
	
	void MyStrCat(MyString& b); // ��'������� �����
	
	void MyDelChr(char c); // ������� �������� ������
	
	int MyStrCmp(MyString& b); // ��������� �����   

	//-1 � ������ ����� ������ �� ������
	//1 � ����� ����� �� �����
	//	0 � ����� ���!


};

