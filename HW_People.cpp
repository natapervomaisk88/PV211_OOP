// flatdz03.06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

class People
{
private:
    char* fam;
    char* name;
    char* otche;
    char* mobilephone;
    char* wyz;

public:

    People()
    {
        fam = new char[100];
        fam[0] = '\0';
        name = new char[100];
        name[0] = '\0';
        otche = new char[100];
        otche[0] = '\0';
        mobilephone = new char[100];
        mobilephone[0] = '\0';
        wyz = new char[100];
        wyz[0] = '\0';
    }

    People(const People& obj)
    {
        fam = obj.fam;
        name = obj.name;
        otche = obj.otche;
        mobilephone = obj.mobilephone;
        wyz = obj.wyz;
    }

    ~People()
    {
        delete[] fam;
        fam = NULL;
        delete[] name;
        name = NULL;
        delete[] otche;
        otche = NULL;
        delete[] mobilephone;
        mobilephone = NULL;
        delete[] wyz;
        wyz = NULL;
    }
    void Show()
    {
        cout << "Фамилия: " << fam << endl;
        cout << "Имя: " << name << endl;
        cout << "Отчество: " << otche << endl;
        cout << "Мобильный телефон: " << mobilephone << endl;
        cout << "Дополнительная информация: " << wyz << endl;
        cout << "\n";
    }

    void Inpfam()
    {
        cout << "Введите фамилию жильца: \n";
        cin >> (fam);
        OemToCharA(fam, fam);
    }

    void Inpname()
    {
        cout << "Введите имя жильца: \n";
        cin >> (name);
        OemToCharA(name, name);
    }

    void Inpotche()
    {
        cout << "Введите отчество жильца: \n";
        cin >> (otche);
        OemToCharA(otche, otche);
    }

    void Inpmobilephone()
    {
        cout << "Введите мобильный телефон: \n";
        cin >> (mobilephone);
        OemToCharA(mobilephone, mobilephone);
    }

    void Inpwyz()
    {
        cout << "Введите дополнительную инф-цию: \n";
        cin >> (wyz);
        OemToCharA(wyz, wyz);
    }

    int Inp(char* str1, char* str2, char* str3)
    {
        if (strcmp(str1, fam) == 0 && strcmp(str2, name) == 0 && strcmp(str3, otche) == 0)
        {

            return 1;
        }
        else
            return 0;
    }
};



class Rooms
{
public:
    People* students;

    Rooms()
    {
        students = new People[100];
    }
    ~Rooms()
    {
        delete[] students;
        students = NULL;
    }
    void See(int x)
    {
        cout << "Квартира №" << x << "\n";
    }
};

class Dom
{
private:
    int StudentsAmo;
    char* GroupName;

public:
    Rooms* stu;


    Dom(int ccc, char* sss)
    {
        stu = new Rooms[ccc];
        StudentsAmo = ccc;
        GroupName = new char[25];
        strcpy_s(GroupName, 25, sss);
        cout << " \n Создан многоквартирный дом " << GroupName << " на " << StudentsAmo << " квартир(ы).\n" << endl;
    }
    ~Dom()
    {
        delete[] stu;
        stu = NULL;
        delete[]GroupName;
        GroupName = NULL;
    }
};


void main()
{
    setlocale(LC_CTYPE, "Rus");
    system("cls");
    int n = 0;
    int q = 0;
    int a = 0;
    int num, num1 = 0;
    int key, count = 0;

    char grname[25];
    cout << "Введите название дома: \n";
    cin >> (grname);
    OemToCharA(grname, grname);

    cout << "Введите количество квартир в доме: ";
    cin >> num;
    while (getchar() != '\n');

    Dom gr(num, grname);

    do
    {
        cout << "1. Добавить человека в квартиру\n";
        cout << "2. Показать список жильцов.\n";
        cout << "0. Выход\n";
        cin >> key;
        while (getchar() != '\n');
        switch (key)
        {
        case 1:
            cout << "Какую квартиру будем заселять?(выберите от 1 до " << num << ")\n ";
            cin >> q;
            getchar();
            while (q > num || q < 0)
            {
                cout << "Некорректно введен номер квартиры\n ";
                cout << "Какую квартиру будем заселять?(выберите от 1 до " << num << ")\n ";
                cin >> q;
                getchar();
            }
            q--;
            gr.stu[q].students[n].Inpfam();
            gr.stu[q].students[n].Inpname();
            gr.stu[q].students[n].Inpotche();
            gr.stu[q].students[n].Inpmobilephone();
            gr.stu[q].students[n].Inpwyz();
            n++;
            system("pause");
            system("cls");
            break;
        case 2:
            if (n == 0)
                cout << "Дом пуст, заселиту его\n";
            else
            {
                for (int j = 0; j < num; j++)
                    for (int i = 0; i < n; i++)
                    {
                        gr.stu[j].students[i].Show();
                    }
            }
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "До свидания\n";
            break;
        default:
            cout << "Выбран неправильный пункт меню\n";
            break;
        }
    } while (key != 0);
    system("pause");
}