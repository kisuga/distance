#include"String.h"



//////////////////////////////////////////////////////////////////////////
////////////// ОПРЕДЕЛНИЕ КЛАССА - CLASS DEFINITION     //////////////


//////////////////////////////////////////////////////////////////////////
////////////// КОНЕЦ ОПРЕДЕЛНИЯ КЛАССА - CLASS DEFINITION END     //////////////


#define HOME_WORK
#define CONSTRUCTORS_CALLING

// оператор [] возварщает значение по индексу


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

	String str4();// Default Constractor НЕВОЗМОЖНО вызватьтаким образом
	// В этой строке объявляется функция  str4, которая ничего не принимает
	// и возвращает объект класса String
	//str4.print();
	// Если нужно явно вызать конструктор по умолчанию,  то это можно сделать так:
	String str5{}; // Default constractor
	str5.print();

	String str6{"World"};
	str6.print();

	String str7 = str3; // Copy Constractor (здесь создается объект, поэтому вызывается копи-констрауктор,
	//несмотря нато что мы использует оператор "="
	str7.print();

	String str8;
	str8 = str6;// здест вызыввается CopyAssigment
	str8.print();

#endif CONSTRUCTORS_CALLING
};