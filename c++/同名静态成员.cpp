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


class A {
public:
    int m = 5;
    static int p;
    static void print()
    {
        cout << "A static" << endl;
    }
};
int A::p = 5;

class B : public A
{
public:
    int m = 6;
    static int p;
    static void print()
    {
        cout << "B static" << endl;
    }
};
int B::p = 6;





int main()
{
    A a;
    B b;

    //�ͽ�ԭ�� ����ͬ��������������򼴿�
    cout << b.m << endl;
    cout << b.A::m << endl;

    // ͬ����̬��Ա������ͬ��
    cout << b.p << endl;
    cout << b.A::p << endl;

    cout << B::p << endl;
    cout << B::A::p << endl;


    // ͬ����̬��Ա����
    B::print();
    B::A::print();

    return 0;
}

