#include<iostream>
using namespace std;

/*
ALL THINGS WRITTEN WITH RESPECT TO DIAMOND SCENARION

- Base class Constructor will be called only once.
- Der1 & Der2 constructor will not call to Base Constructor.

Flow:

- when Join object created then it will go to its own constructor
- it will find which Base class constructor to call, by-default Base class default constructor will be called
- if "Join(int x) :Der1(x), Der2(x), Base(x)" then here we are providing which constructor of Base class to call
- if above instruction not provided then it will call Default constructor of Base class
- After base class constructor called, as per below program it will go to Der1's Parameterised constructor.
- when call reaches to the Der1 Para constructor, then directly go to the Dummy's constructor,not to Base's Para constructor (NOTE)
- then call goes to Der2's Constructor,it will NOT GO to the Base's Constructor

*/

class Base
{
public: 
	int _x;
	Base(int x)
	{
		_x = x;
		cout << "Base Constructor called" << endl;
	}
	Base()
	{
		_x = 0;
		cout << "Base Default Constructor called" << endl;
	}
};

class Dummy
{
public:
	Dummy(int x)
	{
		cout << "Dummy Constructor called" << endl;
	}
	Dummy()
	{
		cout << "Default of Dummy called" << endl;
	}

};

class Der1 : public virtual Base, public Dummy
{
public:
	Der1(int x) :Base(x),Dummy(x)
	{
		cout << "Der1 _x = " << _x << endl;
		cout << "Der1 Constructor called" << endl;
	}

};

class Der2 : public virtual Base
{
public:
	Der2(int x) :Base(x)
	{
		cout << "Der2 _x = " << _x << endl;
		cout << "Der2 Constructor called" << endl;
	}

};


class Join : public Der1,public Der2
{
public:
	Join(int x) :Der1(x), Der2(x)
	{
		cout << "join _x = " << _x << endl;
		cout << "Join Constructor called" << endl;
	}

};

int main()
{
	Join J1(30);
}