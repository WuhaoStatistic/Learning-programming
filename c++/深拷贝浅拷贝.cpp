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
		//height = p1.height; ����ǳ������ֻ�ǽ�ָ���ֵ�����ȥ�������ǿ�����һ���µĿռ丳����ͬ����ֵ
		height = new int(*p1.height); //���
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
	// ջ����ȳ���p2���ͷŵ�ʱ��������������ͷ���height��ָ����ڴ档
	// Ȼ�� p1���ͷ�ʱҲ��ȥ�ͷ�height��ָ����ڴ棬Ȼ����һ���ڴ��Ѿ���p2������ʱ�ͷ��ˣ���ʱ�ķ��ʾͱ���˷Ƿ�����
	// ������Ҫ����������Զ�̬������ڴ���й���
	return 0;
}

