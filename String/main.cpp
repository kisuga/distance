#include <iostrem>
using namespace std;

class String
{
	int size; //������ ������
	char* str; //����� ������ � ������������ ������
public:

	//			Constructor

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size]{};
		cout << "Constructor:\t" << this << endl;
	}

	~String()

};

void main()
{
	setlocale (LC_ALL, "Russian");
	cout << "Hello String" << endl;

}