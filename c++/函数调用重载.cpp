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
    int m;
    int* n = new int(10);
    A(int a)
    {
        this->m = a;
    }
    //�º���functorû�й̶��ĸ�ʽ��һ�и�����Ҫ����ʵ��
    //
    void operator()(string test)
    {
        cout << test << endl;
    }
};



//cout ȫ��ֻ����һ�� ����һ��Ҫ���ã�����ᴴ��һ���µ�
// cout ����һ��Ҫ����cout����������������׷�� << ��
ostream& operator<<(ostream& out, A a)
{
    out << "a.m is" << a.m;
    return out;
}


int main()
{
    A a1(1);
    //�ڵ���ʱ���� ���󣨲�����������ʹ��
    a1("wuhao");
    return 0;

}

