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

    //就近原则 访问同名父类加上作用域即可
    cout << b.m << endl;
    cout << b.A::m << endl;

    // 同名静态成员变量，同上
    cout << b.p << endl;
    cout << b.A::p << endl;

    cout << B::p << endl;
    cout << B::A::p << endl;


    // 同名静态成员函数,需要注意的是，子类会把父类中所有的同名函数都隐藏掉，即父类中的其他重载版本也不能用了
    // 这一点不止是静态成员函数，普通成员函数也都是一样的.
    B::print();
    B::A::print();

    return 0;
}

