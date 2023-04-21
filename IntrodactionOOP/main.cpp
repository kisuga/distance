#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;;

#define delimiter "\n--------------------------------\n"
  

class Point
{

	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void   set_y  (double y)
	{
		this->y = y;
	}

	// Constructor:
	
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout<< "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}



	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// OPERATORS

	Point& operator=(const Point& other)
	{

		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}


	//Methods:
	void print()const
	{
		cout << "X =" << x << "\tY=" << y << endl;
	}

	double distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


//#define STRUCT_POINT

//#define CONSTRUCTORS_CHECK
// #define DISTANCE_CHECK
//#define ASSIGNMENT_CHEK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef STRUCT_POINT
	//type name;
	int a; // объявление переменной а типа int
	Point A; // объявление переменой А типа Point
			// объявление объекта А структуры Point

	A.x=2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;
	
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK

	Point A;
	//A.set_x(2);//вызов  сетеров
	//A.set_y(3);//вызов  сетеров
	//cout << A.get_x() << "\t" << A.get_y() << endl;// вызов гетеров
	A.print();   

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; //CopyConstructor (Deep Copy)
					//(Shallow Copy)
	D.print();

	Point E;
	
	E = D; //оператор присваивания (copy assigment)


#endif  //CONSTRUCTORS_CHECK

	//DISTANCE_CHECK

#ifdef DISTANCE_CHECK
	Point A(2,3);
	A.print();

	Point B(7,8);
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В:" << A.distance (B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A:" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B:" << distance(A,B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A:" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif DISTANCE_CHECK

#ifdef ASSIGNMENT_CHEK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;

	A.print();
	B.print();
	C.print();

#endif ASSIGNMENT_CHEK
}
