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
		cout << "�ֻ�����Ĭ��" << endl;
	}
	Phone(string name)
	{
		this->name = name;
		cout << "�ֻ�����" << endl;
	}
};

class Person
{
public:

	// ʹ���������Ҫ���ֻ��������Ĭ�ϵĹ��캯������ʹ���������ʱ
	// ��ӡ���
	// �ֻ�Ĭ�Ϲ���
	// �˹���
	//�ֻ�����
	Person(int age, string na)
	{
		cout << "�˹���" << endl;
		this->age = age;
		this->p = Phone(na);
	}

	//ʹ�ò����б���ʱֻ���ȵ���һ���ֻ��Ĵ��ι��죬Ȼ���ٵ����Լ��Ĺ���
	// ��ӡ���
	// �ֻ�����
	// �˲����б���
	Person(int age, string na) : age(age), p(na)
	{
		cout << "�˲����б���" << endl;
	}
	int age;
	Phone p;
};

int main()
{
	Person p1 = Person(10, "100");
	
	return 0;
}

