#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int numenator;
	int denominator;
	int integer;

public:

	int get_numenator() const
	{
		return numenator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_integer() const
	{
		return integer;
	}

	void set_numenator(int numenator)
	{
		this->numenator = numenator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}

	//конструкторы

	Fraction() //конструктор по умолчанию
	{
		this->integer = 0;
		this->numenator = 0;
		this->denominator = 0;
		cout << "DefaultConstruct:\t" << this << endl;
	}

	explicit Fraction(int integer) // конструктор с одним параметром
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout << "1ArgCjnstructor:\t" << this << endl;
	}

	Fraction(int numerator, int denominator) // консруктор с двумя параметрами
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator); // чтобы в знаменатель не попал ноль
		cout << "Constructor:\t\t" << this << endl;
	}


	// Конструктор универсальный
	Fraction(int numenator, int denominator, int integer)
	{
		this->numenator = numenator;
		set_denominator(denominator); // здесь лучше пропустить через фильтрациюданных, чтобы в 
										//знаменатель не попал ноль и поэтому ставис set - метод
		this->integer = integer;
		cout << "Constructor:\t\t" << this << endl;
	}
	
	 	// конструктор копирования

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//операторы:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}


	// оператор умножения и присления кода перегрузки
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a /= b;*/
		//a == 2;
		return *this = *this * other;
	}

	// оператор разделить и присоить код перегрузки
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	} 


	//				Increment/Decrement:
	//   перегрузка оператоар инктремент/декремент 

	Fraction& operator++()	// префиксный инкремент перегрузка ++i
	{
		to_proper();
		integer++;
		return *this;
	}

	Fraction operator++(int)//Postfix (Suffix) increment
	{
		//Всегда принимает один и только один параметр типа 'int', и только 'int'
		//Это позволяет компилятору на уровне перегрузки функций отличить постфиксный инкремент от префиксного
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}


	//				методы
	
	Fraction& to_improper()
	{
		numenator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numenator / denominator;
		numenator %= denominator;
		return *this;
	}
	 // метод обращения дроби - числитель и знаменатель меняются местами

	Fraction inverted()const
	{
		//Этот метод обращает дробь.
		Fraction inverted = *this;
		inverted.to_improper();
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Compound%20assignment%20(%2B%3D%2C%20%2D%3D%2C%20*%3D%2C%20/%3D%2C%20%25%3D%2C%20%3E%3E%3D%2C%20%3C%3C%3D%2C%20%26%3D%2C%20%5E%3D%2C%20%7C%3D)
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Bitwise%20operators%20(%20%26%2C%20%7C%2C%20%5E%2C%20~%2C%20%3C%3C%2C%20%3E%3E%20)
		inverted.numenator ^= inverted.denominator;
		inverted.denominator ^= inverted.numenator;
		inverted.numenator ^= inverted.denominator;
		return inverted;
	}
	// метод сокращения дроби - через алгорим Евклида
	// more  - больше    less - меньше     rest - остаток от деления
	Fraction& reduce()
	{
		int more, less, rest;
		if (numenator > denominator)more = numenator, less = denominator;
		else less = numenator, more = denominator;
		if (less == 0)return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greaatest Common Divisor (Наибольший Общий делитель)
		numenator /= GCD;
		denominator /= GCD;
		return *this;
	}

	// метод вывода дроби на экран
	void print()const
	{
		if (integer)cout << integer; // если в дроби толко целая чать - выволим ее
		if (numenator)// если есть дробная часть
		{
			if (integer)cout << "(";//выводим целую часть
			cout << numenator << "/" << denominator; //выводим дробную часть через дробь
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;// если нет ни целой части, ни дроби - выводим ноль
		cout << endl;
	}
};

// перегружаем класс Fraction  за классом
//оператор умножения

Fraction operator*(Fraction left, Fraction right) // передача по значению
{
	left.to_improper(); // объекты скопируются в функцию
	right.to_improper();
	/*Fraction result; // создает объект в котором сохраняется результат
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	//Прямо в 'return' создаем временный безымянный объект типа 'Fraction'
	//Временные безымянные объекты существуют в пределах одного выражения, 
	//и удаляются из памяти по завершении выражения
	return Fraction
	(
		left.get_numenator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numenator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numenator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}



// #define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	int a;
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	//объявление операндов
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2;
	double b = 5;
	double c = a * b;
	
	
	Fraction C = A * B; // оператор умножения вывод на экран
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();*/


	A *= B;
	A.print(); 

	A /= B; 
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_DECREMENT

	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // INCREMENT_DECREMENT


	//Fraction A(2, 3, 4);
	//cout << A << endl;;

	//cout << (2 == 2) << endl;
	//cout << (Fraction(1, 4) <= Fraction(5, 10)) << endl;
}
 



	
	




