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
    bool operator==(A& a)
    {
        return this->m == a.m;
    }
    bool operator!=(A& a)
    {
        return this->m != a.m;
    }
    bool operator>(A& a)
    {
        return this->m > a.m;
    }
    bool operator<(A& a)
    {
        return this->m < a.m;
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
    A a2(2);
    cout << (a1 < a2);
    return 0;

}


