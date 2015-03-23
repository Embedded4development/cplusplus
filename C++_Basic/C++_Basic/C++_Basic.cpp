#include<iostream>
using namespace std;

/*
Delegate to a sister class concept
*/
/*
in Diamond shape of Inheritance,when it is Required to talk between Derived class,
then follow below Procedure & understand the concept....
*/

class Base
{
public:
	virtual void foo() = 0;
	virtual void bar() = 0;

};

class Der1:public virtual Base
{
public:
	virtual void foo()
	{
		bar();
	}
};

class Der2 :public virtual Base
{
public:
	virtual void bar()
	{
		cout << "Der2" << endl;
	}
};


class Join :public Der1, public Der2
{
	//.....
};

int main()
{

	Join *p1 = new Join();
	Der1 *p2 = p1;
	Base *p3 = p1;

	p1->foo();
	p2->foo();
	p3->foo();
	return 0;
}
