#pragma once

#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//////////////////////////////////////////////////////////////////////////
////////////// объявление класса - class declaration       //////////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{

	// строка в языке С - это массив элементов типа "char",  последний элемент котрого всегда 
	//содержит ASCII -СИМВОЛ с кодом "0"
	// " 0" является знаком конца строки
	int size; //размер строки в Байтах
	char* str; //адрес строки в динамической памяти
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
////////////// конец объявления класса - class declaration end      //////////////