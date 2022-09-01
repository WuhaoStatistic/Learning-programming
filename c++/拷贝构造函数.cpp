# include <iostream>
# include "ListNode.h"
# include <vector>
# include <unordered_map>
# include <string>
# include <set>
# include <math.h>
# include <stack>
# include <iterator>
# include <algorithm>
# include <queue>
using namespace std;

class Person
{
public:
	int age;
	Person()
	{

	}
	Person(int age)
	{
		this->age = age;
	}
	Person(const Person& p1)
	{
		this->age = p1.age;
	}

	Person(Person* p1)
	{
		this->age = p1->age;
	}
};

int main()
{
	const int& ref = 1;
	Person a = Person(10);
	Person b = Person(a);
	cout << "a,b 地址不同，是独立的两个对象" << endl;
	cout << &a << endl;
	cout << &b << endl;

	Person* c = new Person(15);
	Person e = Person(c);

	cout << "将C的age从15改为2 e的属性不发生变化,二者地址也不相同，也是独立的" << endl;
	c->age = 2;
	cout << e.age << endl;
	cout << c << endl;
	cout << &e << endl;
	return 0;
}
