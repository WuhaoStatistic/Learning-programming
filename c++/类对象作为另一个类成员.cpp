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

class Phone
{
public:
	string name;
	Phone()
	{
		cout << "手机构造默认" << endl;
	}
	Phone(string name)
	{
		this->name = name;
		cout << "手机构造" << endl;
	}
};

class Person
{
public:

	// 使用这个构造要求手机类必须有默认的构造函数，且使用这个构造时
	// 打印结果
	// 手机默认构造
	// 人构造
	//手机构造
	Person(int age, string na)
	{
		cout << "人构造" << endl;
		this->age = age;
		this->p = Phone(na);
	}

	//使用参数列表构造时只会先调用一次手机的带参构造，然后再调用自己的构造
	// 打印结果
	// 手机构造
	// 人参数列表构造
	Person(int age, string na) : age(age), p(na)
	{
		cout << "人参数列表构造" << endl;
	}
	int age;
	Phone p;
};

int main()
{
	Person p1 = Person(10, "100");
	
	return 0;
}

