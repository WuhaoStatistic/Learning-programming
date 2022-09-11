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


//��ģ������﷨
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

// ��ģ�������Ϊ��������
// ����1
void print1(Person<int, int>& p)
{
    p.showPerson();
}
// ����2
template<class T1, class T2>
void print2(Person<T1, T2>p)
{
    p.showPerson();
}
// ����3
template<class T>
void print3(T& p)
{
    p.showPerson();
}
int main()
{
    // ��ģ��ʹ���﷨������Ҫ�ò����б���û���Զ������Ƶ�
    // �����б������Ĭ�����ͣ�����һ���ں���ģ�����ǲ����õ�
    Person<int> a = Person<int>(5, 6);
    print1(a);
    print2(a);
    print3(a);
    return 0;
}
