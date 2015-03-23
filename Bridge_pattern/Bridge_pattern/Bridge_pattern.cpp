#include<iostream>
#include<string>
using namespace std;

class Shape
{


};

class Rectangle : public Shape
{

};
class circle : public Shape
{

};

class Draw
{
public:
	virtual void Draw_something();

};

class Draw1 : public Draw
{
public:
	void Draw_something()
	{
		cout << "Draw1 is Drawing" << endl;
	}
};


class Draw2 : public Draw
{
public:
	void Draw_something2()
	{
		cout << "Draw2 is Drawing" << endl;
	}
};


