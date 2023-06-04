#include <iostream>
#include "MyString.h"
#include "Student.h"
#include <windows.h>;
#include "Fraction.h"
using namespace std;

void print(Student& obj)
{
    obj.show();
}
Student createStudent(int age)
{
    char name[] = "No name";
    Student std1 = { 112, age, name };
    return std1;
}

int operator + (int val, Fraction fr)
{
    return 0;
}


int main()
{
    Fraction fr;
    fr.setNumerator(10);
    fr.setDenumerator(5);

    Fraction fr2;
    fr2.setNumerator(100);
    fr2.setDenumerator(25);

   int result = fr + fr2;
   int result2 = fr.operator+(fr2);

   int result3 = fr + 10 ;

   int result4 = 10 + fr;

   cout << result3 << endl;


   cout << result;
















  /*  char name[10];
    cout << "Enter name: ";
    cin >> name;
    Student std1 = { 111,30, name};
    cout << "Address: " << &std1 << endl;
    print(std1);*/
  /*  Student std = createStudent(20);
    std.show();*/
 /*   
    Student std2 = std1;
    std2.show();*/

   /* Student std3 = { 234,20,name };
    std3 = std1;*/

    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MyString a;
    a.inputString();
    a.printString();

    MyString b(50);
    b.inputString();
    b.printString();

    MyString c("Корустувач ініціалізує ");
    c.printString();

    MyString d;
    d.inputString();
    d.printString();
    d.MyStrLen();
    cout << d.MyStrLen() << endl;

    c.MyStrCat(b);
    c.printString();

    MyString e;
    MyString j;
    e.inputString();
    j.MyStrcpy(e);
    j.printString();

    MyString str;
    str.inputString();
    MyString str1;
    str1.inputString();
    bool found = str.MyStrStr(str1.getData());
    if (found)
        cout << "Підрядок знайдено!" << endl;
    else
        cout << "Підрядок не знайдено!" << endl;

    MyString str5;
    str.inputString();
    char ch;
    cout << "Введіть потрібний символ:";
    cin >> ch;
    int index = str5.MyChr(ch);
    if (index != -1)
        cout << "Символ знайдено на позиції " << index << endl;
    else
        cout << "Символ не знайдено!" << endl;

    MyString str2;
    str2.inputString();
    char ch1;
    cout << "Введіть символ, який потрібно видалити: ";
    cin >> ch1;
    str2.MyDelChr(ch1);
    cout << "Рядок після видалення символу: " << str2.getData() << endl;

    MyString str3, str4;
    str3.inputString();
    str4.inputString();
    int result = str3.MyStrCmp(str4);
    if (result < 0)
        cout << "Рядок 1 менше рядку 2" << endl;
    else if (result > 0)
        cout << "Рядок 2 менше рядку 1" << endl;
    else
        cout << "Рядки рівні" << endl;

    cout << "Загальна кількість рядків: " << MyString::getCount() << endl << endl;*/

	return 0;
}