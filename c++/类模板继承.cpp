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

//��ģ��̳з�ʽһ ָ��base����
class Son :public Base<int>
{
public:
    int n;
};

//��ģ��̳з�ʽ��������Ҳ��Ϊ��ģ�����ʽ
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
