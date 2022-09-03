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
    A()
    {
    }
    A(int a)
    {
        this->m = a;
    }
    //仿函数functor没有固定的格式，一切根据需要进行实现
    //
    void operator()(string test)
    {
        cout << test << endl;
    }
};



//cout 全局只能有一个 这里一定要引用，否则会创建一个新的
// cout 重载一定要返回cout对象，这样才能无限追加 << ，
ostream& operator<<(ostream& out, A a)
{
    out << "a.m is" << a.m;
    return out;
}


int main()
{
    A a1(1);
    //在调用时就是 对象（参数）来进行使用
    a1("wuhao");
    //匿名对象，在当前行使用完以后直接被释放，有点类似匿名函数
    A()("abcd");
    A(7)("sdsd");
    return 0;

}

