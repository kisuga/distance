#include"String.h"



//////////////////////////////////////////////////////////////////////////
////////////// ���������� ������ - CLASS DEFINITION     //////////////


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