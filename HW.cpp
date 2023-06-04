//#include <iostream>
//using namespace std;
//class Person
//{
//	int size = 20;
//	char* name = nullptr;
//	char* surname = nullptr;
//public:
//	Person()
//	{
//		name = new char[size];
//		surname = new char[size];
//	}
//
//	void input()
//	{
//		cout << "Enter name: ";
//		cin >> name;
//		cout << "Enter surname: ";
//		cin >> surname;
//	}
//
//	void output()
//	{
//		cout << "Person name: \n";
//		cout << name << endl;
//		cout << "Person surname: \n";
//		cout << surname << endl;
//	}
//
//	~Person()
//	{
//		if (name != nullptr)
//			delete[]name;
//		if (surname != nullptr)
//			delete[]surname;
//	}
//
//};
//
//class Flat
//{
//	int humanamount;
//	int flatnumber;
//	Person* pers;
//public:
//	Flat() {}
//	Flat(int numb, int amnt)
//	{
//		humanamount = amnt;
//		flatnumber = numb;
//		pers = nullptr;
//	}
//
//	void create()
//	{
//		Person* pers = new Person[humanamount];
//		for (int i = 0; i < humanamount; i++)
//		{
//			pers[i] = Person();
//			pers[i].input();
//			pers[i].output();
//		}
//	}
//
//	~Flat()
//	{
//		if (pers != nullptr)
//			delete[]pers;
//	}
//};
//
//
//class House
//{
//	int homenumber;
//	int fltamount;
//	Flat* flat;
//public:
//	House(int nm, int am)
//	{
//		homenumber = nm;
//		fltamount = am;
//		flat = nullptr;
//	}
//
//	void makeh()
//	{
//		int nmb, amnt;
//		Flat* flat = new Flat[fltamount];
//		for (int i = 0; i < fltamount; i++)
//		{
//			cout << "Enter flat number: ";
//			cin >> nmb;
//			cout << "Enter humans amount: ";
//			cin >> amnt;
//			flat[i] = Flat(nmb, amnt);
//			flat[i].create();
//		}
//	}
//	~House()
//	{
//		if (flat != nullptr)
//			delete[]flat;
//	}
//};
//
//
//int main()
//{
//	int amnt;
//	int nmb;
//	cout << "Enter house number: ";
//	cin >> nmb;
//	cout << "Enter amount of flat: ";
//	cin >> amnt;
//	House a1(nmb, amnt);
//	a1.makeh();
//	return 0;
//}
#include <iostream>
using namespace std;
class Mystring
{
	int lenth;
	char* strng;
	static int count;
public:
	Mystring()
	{
		lenth = 80;
		strng = new char[lenth+1];
		strng[lenth] = '\0';
		count++;
	}
	Mystring(int size)
	{
		lenth = size;
		strng = new char[lenth + 1];
		
		input();
		output();
		count++;
	}
	Mystring(char* arr)
	{
		int charcount = 0;
		for (int i = 0; arr[i] != '\0'; i++)
		{
			charcount++;
		}
		strng = new char[charcount + 1];
		for (int i = 0; i <= charcount; i++)
			strng[i] = arr[i];
		lenth = charcount + 1;
		cout << endl;
		output();
		count++;
	}

	void input()
	{
		char strng[20];
		cout << "Enter inp string:\n";
		cin >> strng;
		lenth = strlen(strng);
		if (this->strng != nullptr)
			delete[] this->strng;
		this->strng = new char[strlen(strng) + 1];
		strcpy_s(this->strng, strlen(strng) + 1, strng);
	}

	void output()
	{
		cout << "Input string: " << strng << endl;
	}

	int Mystrlen()
	{
		int charcount = 0;
		for (int i = 0; strng[i] != '\0'; i++)
		{
			charcount++;
		}
		return charcount;
	}

	int MyChr(char symb)
	{
		int i = 0; bool match = false;
		for (; i < Mystrlen(); i++)
		{
			if (strng[i] == symb)
			{
				match = true;
				return i;
			}
		}
		if (match == false)
			return -1;
	}

	void MyDelChr(char sm)
	{
		bool mt = false;
		for (int i = 0; i < Mystrlen(); i++)
		{
			if (strng[i] == sm)
			{
				mt = true;
				for (int j = i; j < Mystrlen(); j++)
				{
					strng[i] = strng[j + 1];
					i++;
				}
			}
			else continue;
		}
		output();
		if (mt == false)
			cout << "This symbol is absent\n";
	}

	int MyStrCmp(Mystring obj)
	{
		if (Mystrlen() > obj.Mystrlen())
			return 1;
		else if (Mystrlen() == obj.Mystrlen())
			return 0;
		else if (Mystrlen() < obj.Mystrlen())
			return -1;
	}

	bool MyStrStr(char* arr)
	{
		int charcount = 0; int chk = 0;
		for (int i = 0; arr[i] != '\0'; i++)
		{
			charcount++;
		}
		if (Mystrlen() < charcount)
			cout << "Substring greater then original";
		else
		{
			for (int i = 0; i < Mystrlen(); i++)
				if (strng[i] == arr[0])
				{
					for (int j = 0; j < charcount; j++)
					{
						if (strng[i + j] == arr[j])
							chk++;
					}
				}
		}
		if (chk == charcount)
			return 1;
		else if (chk != charcount)
			return 0;
	}

	void MyStrcpy(Mystring& obj)
	{
		delete[]obj.strng;
		obj.strng = new char[lenth];
		int i = 0;
		for (; strng[i] != '\0'; i++)
			obj.strng[i] = strng[i];
		obj.strng[i] = '\0';


	}

	void MyStrCat(Mystring& obj)
	{

		int tmpsz = (Mystrlen() + obj.Mystrlen());
		char* tmp = new char[tmpsz + 1];
		int i = 0;
		cout << endl;
		while (strng[i] != '\0')
		{
			tmp[i] = strng[i];
			i++;
		}
		int j = 0;
		while (obj.strng[j] != '\0')
		{
			tmp[i] = obj.strng[j];
			i++;
			j++;
		}
		tmp[tmpsz] = '\0';
		delete[]obj.strng;
		obj.strng = tmp;
		obj.lenth = tmpsz;


	}

	static int countercount()
	{
		return count;
	}
	~Mystring()
	{
		if(strng!=nullptr)
			delete[]strng;
	}

};
int Mystring::count = 0;

int main()
{
	int size;

	//cout << "\n-----This is defoult constructor -----\n";
	//Mystring a1;
	//a1.input();
	//a1.output();



	//cout << "\n-----This will show string lenth-----\n";
	//cout << "Enter amount of elements in string: ";
	//cin >> size;
	//while (size <= 0)
	//{
	//	cout << "Error! Enter amount: ";
	//	cin >> size;
	//}
	//Mystring a2(size);
	//cout << "Amount: " << a2.Mystrlen() << endl;
	//cout << "\n-----This will find symbol-----\n";
	//char symb;
	//cout << "Enter symbol to find: ";
	//cin >> symb;
	//cout << "\nIndex number: " << a2.MyChr(symb) << endl;
	//cout << "\n-----This will delete symbol-----\n";
	//cout << "Enter symbol to delete: ";
	//cin >> symb;
	//a2.MyDelChr(symb);



	cout << "\n-----This will compare strings-----\n";
	cout << "Enter amount of elements in string: ";
	cin >> size;
	while (size <= 0)
	{
		cout << "Error! Enter amount: ";
		cin >> size;
	}
	Mystring a5(size);
	Mystring a4(size);
	cout << "String compare: " << a5.MyStrCmp(a4) << endl;



	//cout << "\n-----This is 3rd constructor work -----\n";
	//cout << "Enter amount of elements in string: ";
	//cin >> size;
	//while (size <= 0)
	//{
	//	cout << "Error! Enter amount: ";
	//	cin >> size;
	//}
	//char* strng = new char[size + 1];
	//cout << "Enter string: ";
	//cin >> strng;
	//Mystring a3(strng);
	//delete[]strng;
	//strng = nullptr;



	//cout << "\n-----This will show if string is substring of original string -----\n";
	//cout << "Enter new amount of elements in string: ";
	//cin >> size;
	//while (size <= 0)
	//{
	//	cout << "Error! Enter amount: ";
	//	cin >> size;
	//}
	//Mystring a6(size);
	//strng = new char[size + 1];
	//cout << "Enter string to check belong (1-string is substring, 0-not): ";
	//cin >> strng;
	//cout << endl << "Compare result: " << a6.MyStrStr(strng) << endl;
	//delete[]strng;
	//strng = nullptr;




	//cout << "\n-----This will copy one string to enother-----\n";
	//cout << "Enter amount of elements in string: ";
	//cin >> size;
	//while (size <= 0)
	//{
	//	cout << "Error! Enter amount: ";
	//	cin >> size;
	//}
	//Mystring a8(size);
	//cout << "\nNow make string you want to copy.\n";
	//Mystring a7(size);
	//a7.MyStrcpy(a8);
	//cout << "Now string copyed. First string changed.\n";
	//a8.output();
	//cout << endl;


	//cout << "\n-----This will join two strings-----\n";
	//cout << "Enter amount of elements in string: ";
	//cin >> size;
	//while (size <= 0)
	//{
	//	cout << "Error! Enter amount: ";
	//	cin >> size;
	//}
	//Mystring a9(size);
	//cout << "\nNow make string you want to join.\n";
	//Mystring a10(size);
	//a9.MyStrCat(a10);
	//cout << "\nJoining string\n";
	//a10.output();
	//cout << endl;


	cout << Mystring::countercount() << " object were created";
	return 0;
}
