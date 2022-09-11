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


//类模板基本语法
template<class NameType, class AgeType = int>
class Person
{
public:
    NameType name;
    AgeType age;
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

    static void showPerson()
    {
        cout << "Person show" << endl;
    }
};

// 类模板对象作为参数传递
// 方法1
void print1(Person<int, int>& p)
{
    p.showPerson();
}
// 方法2
template<class T1, class T2>
void print2(Person<T1, T2>p)
{
    p.showPerson();
}
// 方法3
template<class T>
void print3(T& p)
{
    p.showPerson();
}
int main()
{
    // 类模板使用语法，必须要用参数列表，他没有自动类型推导
    // 参数列表允许的默认类型，但这一点在函数模板中是不能用的
    Person<int> a = Person<int>(5, 6);
    print1(a);
    print2(a);
    print3(a);
    return 0;
}
