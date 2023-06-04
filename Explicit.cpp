//#include <iostream>
//
//class MyClass 
//{
//private:
//    int data;
//public:
//    explicit MyClass(int value) : data(value) 
//    {
//        std::cout << "Explicit constructor called" << std::endl;
//    }
//
//    void printData() 
//    {
//        std::cout << "Data: " << data << std::endl;
//    }
//};
//
//int main() 
//{
//    // Явное создание объекта с использованием конструктора
//    MyClass obj1(10);
//    obj1.printData();
//
//    // Ошибка компиляции! Неявное преобразование запрещено.
//    MyClass obj2 = 20;
//    obj2.printData();
//
//    // Явное преобразование типа разрешено
//    MyClass obj3 = MyClass(30);
//    obj3.printData();
//
//    return 0;
//}


#include <iostream> 


class Drob
{
private:
	int m_numerator;
	int m_denominator;

public:
	// Конструктор по умолчанию
	/*explicit */Drob(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		std::cout << m_numerator << " " << m_denominator << std::endl;
	}

	// Конструктор копирования
	Drob(const Drob& copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществлена в конструкторе по умолчанию
		std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
	}

	void print()
	{
		std::cout << m_numerator << " " << m_denominator << std::endl;
	}
	
	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

Drob makeNegative(Drob d)
{
	d.setNumerator(-d.getNumerator());
	return d;
}


Drob test()
{
	return 2;
}

int main()
{
	//Drob dr; //0 1
	//Drob dr2(7); //7 1
	//Drob dr3(2, 6); //2 6
	Drob dr;

	makeNegative(test()).print();
	//makeNegative(dr2).print(); // передаем целочисленное значение

	return 0;
}

//#include <iostream> 
//#include <string>
//
//class SomeString
//{
//private:
//	std::string m_string;
//public:
//	explicit SomeString(int a) // выделяем строку размером a
//	{
//		m_string.resize(a);
//	}
//
//	SomeString(const char* string) // выделяем строку для хранения значения типа string
//	{
//		m_string = string;
//	}
//
//	friend std::ostream& operator<<(std::ostream& out, const SomeString& s);
//
//};
//
//std::ostream& operator<<(std::ostream& out, const SomeString& s)
//{
//	out << s.m_string;
//	return out;
//}
//
//int main()
//{
//	SomeString mystring = 'A'; // выполняется копирующая инициализация
//	std::cout << mystring;
//	return 0;
//}