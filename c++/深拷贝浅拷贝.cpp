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
	int* height;

	Person(int age, int hei)
	{
		this->age = age;
		height = new int(hei);
	}
	Person(const Person& p1)
	{
		age = p1.age;
		//height = p1.height; 这是浅拷贝，只是将指针的值赋予过去，并不是拷贝了一份新的空间赋予其同样的值
		height = new int(*p1.height); //深拷贝
	}
	~Person()
	{
		if (height != NULL)
		{
			delete height;
			height = NULL;
		}

	}

};

int main()
{
	Person p1 = Person(10, 100);
	Person p2 = Person(p1);
	// 栈后进先出，p2在释放的时候调用析构函数释放了height所指向的内存。
	// 然后 p1在释放时也会去释放height所指向的内存，然而那一块内存已经在p2被销毁时释放了，此时的访问就变成了非法操作
	// 所以需要深拷贝操作来对动态分配的内存进行管理
	return 0;
}

