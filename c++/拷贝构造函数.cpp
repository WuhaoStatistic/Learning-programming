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
	cout << "a,b ��ַ��ͬ���Ƕ�������������" << endl;
	cout << &a << endl;
	cout << &b << endl;

	Person* c = new Person(15);
	Person e = Person(c);

	cout << "��C��age��15��Ϊ2 e�����Բ������仯,���ߵ�ַҲ����ͬ��Ҳ�Ƕ�����" << endl;
	c->age = 2;
	cout << e.age << endl;
	cout << c << endl;
	cout << &e << endl;
	return 0;
}
