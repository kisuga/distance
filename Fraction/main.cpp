#include<iostream>
using namespace std;

class Franction
{
	int num;
	int denom;
	double result;

public:

	int get_num() const
	{
		return num;
	}
	int get_denom()const
	{
		return denom;
	}
	double get_result() const
	{
		return result;
	}

	void set_num(int x)
	{
		this->num = num;
	}
	void set_denom(int denom)
	{
		this->denom = denom;
	}
	void set_result(double z)
	{
		this->result = result;
	}

	Fraction (int num, int denom, double result)
	{
		this->num = num;
		this->denom = denom;
		this->result = result;
		cout << "Части дроби:\t\t" << this << endl;
	}
	~Fraction()
	{
		this;
	}

};

double FRAN(const Fraction) const
{
		return result;
}