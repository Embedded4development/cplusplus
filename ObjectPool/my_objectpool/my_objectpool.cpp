#include<iostream>
#include<string>
#include<list>

using namespace std;
class Employee
{
public:
	char *_allocation;
	int _salary;
	Employee()
	{
		_allocation = new char;
		_salary = 12,500;
	}
	
	~Employee()
	{
		delete _allocation;
		_salary = 0;
	}

	int getSalary()
	{
		return _salary;
	}

	void setSalary(int salary)
	{
		_salary = salary;
	}

};


class ObjectPool
{
private:
	list<Employee *> employees;
	static ObjectPool* manage;

	// used SINGLETON Pattern to retain one Object throughout project..
	ObjectPool(){};

public:

	static ObjectPool* GetManagePointer()
	{
		if(manage == 0)
			return new ObjectPool;
		return manage;
	}

	Employee* GetResource()
	{
		if (employees.empty())
		{
			cout << "Resource are Empty, Creating New" << endl;
			return new Employee;
		}
		else
		{
			cout << "size is:" << employees.size();
			cout << "Resource are Available, Reusing it" << endl;
			Employee* emp = employees.front();
			employees.pop_front();
			cout << "size is:" << employees.size();
			return emp;
		}
	}

	void ReleaseResource(Employee *emp)
	{
		emp->setSalary(0);
		employees.push_back(emp);
	}
};


ObjectPool* ObjectPool::manage = 0;

int main()
{
	ObjectPool *pool = ObjectPool::GetManagePointer();
	Employee *first;
	Employee *second;

	first = pool->GetResource();
	second = pool->GetResource();

	first->setSalary(20000);
	second->setSalary(20000);

	pool->ReleaseResource(first);
	pool->ReleaseResource(second);

	first = pool->GetResource();
	second = pool->GetResource();

	return 0;
}