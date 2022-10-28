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
# include <chrono>

using namespace std;


// 像下面这样写会出现重复析构的问题，sptr2和3在这里引用计数值都会为1 
// 感觉是因为他们都是从普通指针构造来的，如果将sptr改为shared_ptr就不会出问题 只会引用计数减少1
void test()
{
    //int *sptr = new int(3); //会出问题
    shared_ptr<int> sptr(new int(3)); //没问题 析构减少引用计数
    {
        shared_ptr<int> sptr2(sptr);
        {
            shared_ptr<int> sptr3(sptr);
        }
    }
}
// shared ptr是强指针，有时候我们需要弱指针来解决循环引用 析构异常问题
class B;
class A
{
public:
    A() {}
    void set(shared_ptr<B> b) {
        this->b = b;
    }
    //将其变为弱指针
    weak_ptr<B> b;
};

class B
{
public:
    B() {}
    void set(shared_ptr<A> a) {
        this->a = a;
    }
    shared_ptr<A> a;
};

int main()
{
    //通过访问内存 他是确实不会在这个作用域结束以后析构的，原因是
    //引用计数在循环调用以后变为了2，那么两个都析构了以后 引用计数会减少1.但是两个减完1以后 还剩下1 所以都无法析构，
    //这时候只要有一个析构了 另一个就会跟着析构，所以我们需要将其中一个类内指针变为weak_ptr即可
    {
        shared_ptr<A> pa(new A());
        //shared_ptr<B> pb(new B());
        shared_ptr<B> pb(new B());
        pa->set(pb);
        pb->set(pa);
        //变为弱指针以后 输出结果为1 2.
        cout << pa->b.use_count() << endl;
        cout << pb->a.use_count();
    }
    return 0;
}