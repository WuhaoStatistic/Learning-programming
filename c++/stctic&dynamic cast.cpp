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
# include <fstream>
# include "Myarray.hpp"
# include <functional>
using namespace std;


class Base
{
public:
    int m;
    Base() = default;
    Base(int x) : m(x) {};
};

class H1 : public Base
{
public:
    int n = 10;
    H1(int x) : n(x) {};
    H1(int x, int y) :Base(x), n(y) {};
};


int main()
{
    Base a = Base(5);
    H1 b = H1(6);

    //static_cast���԰�ԭ��ֻ������ת���ĳ����������˫��ת��,����ת���޷�ȷ����ȫ ���׳������߰���Ĳ���
    Base* p = static_cast<Base*>(&b);
    H1* q = static_cast<H1*>(&b);
    //dynamic case ���Ӱ�ȫ ֻ��������������ת��
    Base* q = dynamic_cast<Base*>(&b);
    int bb = 5;
    int* c = &bb;

    void* d;
    d = static_cast<void*>(c);
    return 0;
}