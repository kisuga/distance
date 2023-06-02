#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//////////////////////////////////////////////////////////////////////////
////////////// ���������� ������ - class declaration       //////////////
class String;
String operator+(const String& left, const String& right);
class String
{
	
	// ������ � ����� � - ��� ������ ��������� ���� "char",  ��������� ������� ������� ������ 
	//�������� ASCII -������ � ����� "0"
	// " 0" �������� ������ ����� ������
	int size; //������ ������ � ������
	char* str; //����� ������ � ������������ ������
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//			Constructor

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	// operators

	String& operator=(const String& other);

	String& operator+=(const String& other);



	char operator[](int i)const;
	char& operator[](int i);
	
	//				Methods:

	void print()const;
};

//////////////////////////////////////////////////////////////////////////
////////////// ����� ���������� ������ - class declaration end      //////////////



//////////////////////////////////////////////////////////////////////////
////////////// ���������� ������ - CLASS DEFINITION     //////////////

// ������� ��������� :: - ��� �������� ���������� ��������� Scope Operator
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructor

String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char str[]) :size(strlen(str) + 1), str(new char[size] {}) // � ������ ������� � ������������  
{
	for (int i = 0; i < size; i++) this->str[i] = str[i];// ��������� ������
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other) :String(other.str) // const ����� ������������������� ������ � ���������
{
	cout << "CopyConsrtuctor:" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str) // ��� ����� �������������� � ��������� 
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}


String::~String()
{
	delete[] str;
	cout << "Destructor" << this << endl;
}

// operators

String& String::operator=(const String& other)
{
	if (this == &other)return*this; // ������ ������ � �������� �� ����������
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}



char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:

void String::print()const
{
	cout << "Size: " << size << endl;
	cout << "Str:  " << str << endl;
}




String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i]; // �������� []  - ��� ��������� ����� � ��������������� ������� ������� - 
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////////////////////////////////////////////////////////////
////////////// ����� ���������� ������ - CLASS DEFINITION END     //////////////


#define HOME_WORK
#define CONSTRUCTORS_CALLING

// �������� [] ���������� �������� �� �������


void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Hello String" << endl;
#ifdef HOME_WORK
	
	String str1 = "Hello";
	//str.print();
	cout << str1 << endl;
	
	
	String str2 = "World";
	cout << str2 << endl;
	//String str3 = str1 + str2;
	String str3;
	str3 = str1 +" " + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;

	String str4 = str3;
	cout << str4 << endl;

#endif  HOME_WORK

#ifdef CONSTRUCTORS_CALLING
	String str1; // Default Constractor
	str1.print();

	String str2(22);// Single-Argument constractor 'int'
	str2.print();

	String str3 = "Hello";// Single-Argument Constractor 'const char*'
	str3.print();

	String str4();// Default Constractor ���������� ������������ �������
	// � ���� ������ ����������� �������  str4, ������� ������ �� ���������
	// � ���������� ������ ������ String
	//str4.print();
	// ���� ����� ���� ������ ����������� �� ���������,  �� ��� ����� ������� ���:
	String str5{}; // Default constractor
	str5.print();

	String str6{"World"};
	str6.print();

	String str7 = str3; // Copy Constractor (����� ��������� ������, ������� ���������� ����-������������,
	//�������� ���� ��� �� ���������� �������� "="
	str7.print();

	String str8;
	str8 = str6;// ����� ����������� CopyAssigment
	str8.print();

#endif CONSTRUCTORS_CALLING
};