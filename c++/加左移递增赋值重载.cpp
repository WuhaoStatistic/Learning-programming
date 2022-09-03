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
    int* n = new int(10);
    A operator+(A a)
    {
        A tmp;
        tmp.m = this->m + a.m;
        return tmp;
    }
    //返回
    A& operator++()
    {
        this->m++;
        return *this;
    }
    // 用占位参数来区分前置和后置自增
    // 后置++因为返回的是局部的变量 局部变量返回引用会出问题
    // 所以这里只能返回值。
    A operator++(int)
    {
        A a = *this;
        this->m++;
        return a;
    }

    A& operator=(A& a)
    {
        // 当对象中有东西指向堆区的时候，赋值需要深拷贝才行，否则两个指针指向同一块内存，
        // 一个析构之后另一个就会出问题。
        // =赋值操作不同于深拷贝构造，他一般用于已经创建了这个变量，然后我们要进行赋值操作
        // 这个时候如果不清空一下堆区的内存，那么虽然那个指针被销毁了，但是指针所指向的那个内存空间仍然被占用
        if (this->n != NULL)
        {
            delete this->n;
            this->n = NULL;//标准释放内存操作
        }
        this->n = new int(*a.n);//解引用并创建新的空间
        this->m = a.m;
        return *this;
    }

    A& operator*(A a1)
    {
        this->m = a1.m * this->m;
        return *this;
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
    A a1;
    A a2;
    A a3;

    //测试普通加号
    cout << (a1 + a2) + a2 << endl;

    // 如果重载函数不是返回引用的话，这句话会报错，因为返回的时候会调用拷贝构造函数返回一个copy，这个copy是临时的，临时的只能作为右值
    // 这就导致了 ++(++a1)只会修改一次 a1，因为第二次操作是在临时的变量上进行操作
    cout << ++(++a1) << endl;;

    cout << a1++ << endl;;
    cout << a1 << endl;

    //测试= *
    a3 = a2 = a1;
    a3 = a1 * a2 * a2;
    cout << *a3.n << endl;
    cout << a3 << endl;
    return 0;

}



