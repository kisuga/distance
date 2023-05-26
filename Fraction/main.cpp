#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

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

	//������������

	Fraction() //����������� �� ���������
	{
		this->integer = 0;
		this->numenator = 0;
		this->denominator = 0;
		cout << "DefaultConstruct:\t" << this << endl;
	}

	explicit Fraction(int integer) // ����������� � ����� ����������
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout << "1ArgCjnstructor:\t" << this << endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;  // ���� � ��� ���������� ����� � ������� (2,76 ��������)
		this->integer = decimal;	// ����� ����� �����. �����
		decimal -= integer;			//������� ����� ����� �� �����.�����
		//4 000 000 000 - ������ ��������
		denominator = 1e9;	//1 000 000 000  ���������� �����������-��������� �����������(���������������� ����� ������)
		//1e10 = 1*10^10 - 
		numenator = decimal * denominator;	//����������� ��� ������� ����� � ���������
		reduce(); //���������� ����� �� ��������� �������
	}

	Fraction(int numerator, int denominator) // ���������� � ����� �����������
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator); // ����� � ����������� �� ����� ����
		cout << "Constructor:\t\t" << this << endl;
	}


	// ����������� �������������
	Fraction(int numenator, int denominator, int integer)
	{
		this->numenator = numenator;
		set_denominator(denominator); // ����� ����� ���������� ����� ����������������, ����� � 
										//����������� �� ����� ���� � ������� ������ set - �����
		this->integer = integer;
		cout << "Constructor:\t\t" << this << endl;
	}
	
	 	// ����������� �����������

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


	//���������:

	Fraction& operator()(int integer, int numenator, int denominator)
	{
		set_integer(integer);
		set_numenator(numenator);
		set_denominator(denominator);
		return *this;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	// �������� ��������

	Fraction& operator+=(const Fraction& other)
	{
				return *this = *this + other;
	}
	
	// �������� ���������

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	// �������� ��������� � ��������� ���� ����������
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a /= b;*/
		//a == 2;
		return *this = *this * other;
	}

	// �������� ��������� � �������� ��� ����������
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	} 


	//				Increment/Decrement:
	//   ���������� ��������� ���������/��������� 

	Fraction& operator++()	// ���������� ��������� ���������� ++i
	{
		to_proper();
		integer++;
		return *this;
	}

	Fraction operator++(int)//Postfix (Suffix) increment
	{
		//������ ��������� ���� � ������ ���� �������� ���� 'int', � ������ 'int'
		//��� ��������� ����������� �� ������ ���������� ������� �������� ����������� ��������� �� �����������
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--()	// ���������� ��������� ���������� ++i
	{
		to_proper();
		integer--;
		return *this;
	}

	Fraction operator--(int)//Postfix ���������
	{
		
		to_proper();
		Fraction old = *this;
		integer--;
		return old;
	}



	//				������
	
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
	 // ����� ��������� ����� - ��������� � ����������� �������� �������

	Fraction inverted()const
	{
		//���� ����� �������� �����.
		Fraction inverted = *this;
		inverted.to_improper();
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Compound%20assignment%20(%2B%3D%2C%20%2D%3D%2C%20*%3D%2C%20/%3D%2C%20%25%3D%2C%20%3E%3E%3D%2C%20%3C%3C%3D%2C%20%26%3D%2C%20%5E%3D%2C%20%7C%3D)
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Bitwise%20operators%20(%20%26%2C%20%7C%2C%20%5E%2C%20~%2C%20%3C%3C%2C%20%3E%3E%20)
		inverted.numenator ^= inverted.denominator;
		inverted.denominator ^= inverted.numenator;
		inverted.numenator ^= inverted.denominator;
		return inverted;
	}
	// ����� ���������� ����� - ����� ������� �������
	// more  - ������    less - ������     rest - ������� �� �������
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
		int GCD = more;	//GCD - Greaatest Common Divisor (���������� ����� ��������)
		numenator /= GCD;
		denominator /= GCD;
		return *this;
	}

	Fraction& poz_denominator()
	{
		if(denominator<0)
			denominator=denominator*(-1);
			return*this;
	}


	// ����� ������ ����� �� �����
	void print()const
	{
		if (integer)cout << integer; // ���� � ����� ����� ����� ���� - ������� ��
		if (numenator)// ���� ���� ������� �����
		{
			if (integer)cout << "(";//������� ����� �����
			cout << numenator << "/" << denominator; //������� ������� ����� ����� �����
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;// ���� ��� �� ����� �����, �� ����� - ������� ����
		cout << endl;
	}
};

// ����������� ����� Fraction  �� �������


// �������� ��������
Fraction operator+(Fraction left, Fraction right) // �������� �� ��������
{
	left.to_improper(); // ������� ����������� � �������
	right.to_improper();
	
	return Fraction
	(
		left.get_numenator() * right.get_numenator()
		+
		right.get_numenator()* left.get_numenator(),
		left.get_denominator() + right.get_denominator()
	).to_proper().reduce();

	// �������� ���������

	Fraction operator-(Fraction left, Fraction right) // �������� �� ��������
	{
		left.to_improper(); 
		right.to_improper();

		return Fraction
		(
			left.get_numenator() * right.get_numenator()
			-
			right.get_numenator() * left.get_numenator(),
			left.get_denominator() + right.get_denominator()
		).to_proper().reduce().poz_denominator();
		cout << 2 << endl;
	} 


//�������� ���������

Fraction operator*(Fraction left, Fraction right) // �������� �� ��������
{
	left.to_improper(); // ������� ����������� � �������
	right.to_improper();
	
	
	/*Fraction result; // ������� ������ � ������� ����������� ���������
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	
	return Fraction 
	(
		left.get_numenator()*right.get_numenator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
	
	//����� � 'return' ������� ��������� ���������� ������ ���� 'Fraction'
	//��������� ���������� ������� ���������� � �������� ������ ���������, 
	//� ��������� �� ������ �� ���������� ���������
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

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator()) // ���� ��� �������� ����� ����� , ��� � ������� ���� ����
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numenator() * right.get_denominator() == right.get_numenator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numenator() * right.get_denominator() >
		right.get_numenator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numenator() * right.get_denominator() <
		right.get_numenator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);				// �� ������� ������ ��� ����� ����� �����������, ��� " - ��� �� ������"
	//return left > right || left == right;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
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

std::istream& operator>>(std::istream& is, Fraction& obj)
{
#ifdef SIMPLE_INPUT
	int integer, numenator, denominator;
	is >> integer >> numenator >> denominator;
	/*obj.set_integer(integer);
	obj.set_numenator(numenator);
	obj.set_denominator(denominator);*/
	obj(integer, numenator, denominator); // ��� ����� ������� ������ ������������ ��� ���������
#endif // SIMPLE_INPUT

	const int SIZE = 256;// ������� ������ �� ������� ����� �������� ������ �����
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int number[3] = {}; // ������� ������ �� 3 �������� ��� �������� �����
	int n = 0;	//���������� ��������� �����
	char delimiters[] = "() /";
	//https://legacy.cplusplus.com/reference/cstring/strtok/ // ��� ����� �������, ������ ��������� �������� ����� � ����������� ��� ���������� �����
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = atoi(pch);
	}
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numenator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]); break;
	}
	return is;
}


// #define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT
//#define ISTREAM_OPERATOR
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
#define HOME_WORK_1


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
	//���������� ���������
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2;
	double b = 5;
	double c = a * b;
	
	
	Fraction C = A * B; // �������� ��������� ����� �� �����
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();*/

	Fraction E = A + B;
	E.print();

	Fraction F = A - B;
	F.print();


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
	//cout << (Fraction(1, 4) > Fraction(5, 10)) << endl;

#ifdef ISTREAM_OPERATOR
	Fraction A(2, 3, 4);
	cout << "������� ������� �����: "; cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR

#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value;	C-like notation - �������� �������
	//type(value);	Functional notation - �������� ��������

	//Conversion from 'type1' to 'type2' possible loss of data. - �������� ��������

	int a = 2;		//No conversions - ��� ��������������
	double b = 3;	//Conversion from less to more - ���� ��������������  �� ��������  � ��������
	int c = a + b;	//Conversion from more to less with no data loss  - ������. �� �������� � �������� ��� ������ ������
	cout << c << endl;
	int d = 8.3;	//Conversion from more to less with data loss - �������� �� �������� � �������� � ������� ������
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS



#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	//cout << sizeof(Fraction) << endl;
	Fraction A = (Fraction)5;		//Conversion from 'int' to 'Fraction'
	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;			//Default constructor
	B = Fraction(8);
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	//type-cast operators
/*
------------------------
[explicit] operator type()
{
	......;
	return value;
}
------------------------
*/

	Fraction A(2, 3, 4);
	//A.to_improper();
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double b = A;
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK_1
	Fraction A = 2.75;
	cout << A << endl;
#endif // HOME_WORK_1
}
 



	
	




