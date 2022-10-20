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


class Point {
public:
    int* x = nullptr;
    int* y = nullptr;
    Point()
    {
        alloc();
    }
    Point(int xx = 0, int yy = 0)
    {
        alloc(); //使用前需要allocate 否则x,y 为空指针，无法赋值
        *x = xx;
        *y = yy;
    }
    void alloc()
    {
        if (x == nullptr)
        {
            x = new int;
            memset(x, 0, sizeof(int));
        }
        if (y == nullptr)
        {
            y = new int;
            memset(y, 0, sizeof(int));
        }
    }
    Point(const Point& a)
    {
        cout << "copy constructor" << endl;
        if (x == nullptr || y == nullptr) alloc();
        memcpy(x, a.x, sizeof(int));
        memcpy(y, a.y, sizeof(int));
    }
    Point& operator=(const Point& a)
    {
        cout << "= construct" << endl;
        if (this == &a)
            return *this;
        if (x == nullptr || y == nullptr) alloc();
        memcpy(x, a.x, sizeof(int));
        memcpy(y, a.y, sizeof(int));
        return *this;
    }
    Point(Point&& a)
    {
        cout << "move constructor" << endl;
        if (x != nullptr)delete x;
        if (y != nullptr)delete y;
        x = a.x;
        y = a.y;
        a.x = nullptr;
        a.y = nullptr;
    }
    Point& operator=(Point&& a)
    {
        cout << "move =" << endl;
        if (this == &a)
            return *this;
        if (x == nullptr || y == nullptr) alloc();
        memcpy(x, a.x, sizeof(int));
        memcpy(y, a.y, sizeof(int));
        a.x = nullptr;
        a.y = nullptr;
        return *this;
    }
    ~Point()
    {
        if (x != nullptr) {
            delete x; x = nullptr;
        }
        if (y != nullptr) {
            delete y; y = nullptr;
        }
    }
};

void displayPoint(const Point& p)
{
    cout << "(" << *p.x << ","
        << *p.y << ")" << endl;
}

//完美转发 perfect forwarding
void func1(int&& a)
{
    cout << "right value" << endl;
}

void func1(int& a)
{
    cout << "left value" << endl;
}

//一下为使用move的方法，使用move和使用statistic_cast
//move 将左值变成右值
//这里接收的是右值引用，但是传入之后就会变成一个左值,需要用move将a重新转为右值

void func2(int&& a)
{
    func1(move(a));

}
void func2(int& a)
{
    func1(a);
}




template<typename T>
void func2(T&& a)
{
    cout << "template right";
    func1(a);
}

template<typename T>
void func2(T& a)
{
    cout << "template left";
    func1(a);
}
//使用模板触发C++11新特性
//模板右值 可以接收左值参数，可以通过把下面那个func2注释进行测试
//forward可以识别左值右值，并完美转发
template<typename T>
void func3(T&& ii)
{
    func1(forward<T>(ii));
}
int main()
{
    //普通构造
    Point P1(1, 2);
    //对于左值，使用拷贝构造
    Point P2 = P1;

    //移动语义可以解释为什么C++11中函数局部变量再被返回时可以有一次追溯他地址的机会
    // 这一次的追溯就是为了方便让移动语义能够找到右值，这个右值可以称为将亡值。 其他如常量也是右值但不是将亡值。

    // lambda 函数 中括号内存放当前域内可用的变量，小括号参数
    auto f = [](int aa, int b) { Point a(aa, b); return a; };
    //lambda返回右值 移动构造
    Point P3(f(2, 3));
    //lambda返回右值 移动赋值
    Point P4 = f(2, 3);

    //完美转发，我们现在有一个函数a 对于左值和右值有不同的操作，我们通过一个函数b去调用他，我们需要确保函数b在参数传递的过程中能保证左右值的属性。
    int ii = 3;
    func2(ii);
    func2(3);
    func3(ii);
    func3(3);
    return 0;
}