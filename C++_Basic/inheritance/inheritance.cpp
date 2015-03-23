#include<iostream>
using namespace std;


class Base
{
public:
	virtual void fun()
	{
		cout << "fun" << endl;
	}

};


class child : public Base
{
public:
	void fun1()
	{
		cout << "Fun1" << endl;
	}
	void fun()
	{
		cout << "child fun" << endl;
	}
};

int main()
{

	Base *base;
	child ch2;
	base = &ch2;
	base->fun();
	return 0;
}