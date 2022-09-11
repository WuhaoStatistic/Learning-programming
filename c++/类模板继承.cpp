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
using namespace std;


template<class T>
class Base
{
public:
    T m;
};

//类模板继承方式一 指定base类型
class Son :public Base<int>
{
public:
    int n;
};

//类模板继承方式二，子类也作为类模板的形式
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
    T1 obj;
    int b;
};

int main()
{
    Son2<int, char> p;
    cout << typeid(p.m).name() << endl;
    cout << typeid(p.obj).name() << endl;
    return 0;
}
