#include<iostream>
#include <initializer_list>

using namespace std;

class A
{
	int* str;
	int size;
public:
	A()
	{
		str = nullptr;
	}
	A(initializer_list<int> a)
	{
		cout << "Initializer_list constructor\n";
		cout << a.size() << endl;
		size = a.size(); // получаем размер 
		str = new int[size];
		for (auto x = a.begin(); x != a.end(); x++)
		{
			*str = *x;
			str++;
		}
		str -= size;// смещение указателя на начало массива 

	}
	A(int ar[], int Size)
	{
		cout << "Construct array\n";
		size = Size;
		str = new int[size];
		for (int i = 0; i < size; i++)
		{
			str[i] = ar[i];
		}
	}
	void Output()
	{
		for (int i = 0; i < size; i++)
		{
			//cout << str[i] << "\t";
			//cout << *(str + i) << "\t";

			cout << *str << "\t";
			str++;
		}
		str -= size;
		cout << endl;
	}
	~A()
	{
		delete[] str;
	}
};
void main()
{
	/*initializer_list<int> li = { 3,4,5,-10 };
	cout << *(li.begin()) << endl;
	cout << li.size() << endl;
	cout << *(li.end()-1) << endl;
	for (auto i = li.begin(); i != li.end(); i++)
	{
		cout << *i << endl;
	}*/

	A obj{ 1,2,3,4,5 };
	obj.Output();
	//int mas[]{ 2,4,6,8 };
	//A b { mas,4 };
	//b.Output();


	system("pause");
}