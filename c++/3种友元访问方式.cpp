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


void test_friend(Phone p)
{
	cout << p.series_name;
}

class Phone
{
	friend void test_friend(Phone p); //ȫ����Ԫ������������ʽ
	friend class Me;  //��Ԫ��
	friend void You::visit(Phone p1);
public:
	Phone()
	{
		this->name = "public";
		this->series_name = "private";
	}
	string name;


private:
	string series_name;
};
//��Ԫ��
class Me
{
public:
	void visit(Phone p1);

};

void Me::visit(Phone p1)
{
	cout << p1.series_name;
}

// ��Ԫ�ຯ��
// ���û������ ������˵
class You
{
public:
	void visit(Phone p1)
	{
		cout << p1.series_name;
	}
};
int main()
{
	Phone p1;
	You u;
	u.visit(p1);
	return 0;

}


