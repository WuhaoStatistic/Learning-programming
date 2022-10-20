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

    //static_cast可以把原来只允许单向转换的场景变成允许双向转换,但是转化无法确保安全 容易出现乱七八糟的操作
    Base* p = static_cast<Base*>(&b);
    H1* q = static_cast<H1*>(&b);
    //dynamic case 更加安全 只允许子类像父类做转换
    Base* q = dynamic_cast<Base*>(&b);
    int bb = 5;
    int* c = &bb;

    void* d;
    d = static_cast<void*>(c);
    return 0;
}