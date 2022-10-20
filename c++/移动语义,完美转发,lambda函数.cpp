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
        alloc(); //ʹ��ǰ��Ҫallocate ����x,y Ϊ��ָ�룬�޷���ֵ
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

//����ת�� perfect forwarding
void func1(int&& a)
{
    cout << "right value" << endl;
}

void func1(int& a)
{
    cout << "left value" << endl;
}

//һ��Ϊʹ��move�ķ�����ʹ��move��ʹ��statistic_cast
//move ����ֵ�����ֵ
//������յ�����ֵ���ã����Ǵ���֮��ͻ���һ����ֵ,��Ҫ��move��a����תΪ��ֵ

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
//ʹ��ģ�崥��C++11������
//ģ����ֵ ���Խ�����ֵ����������ͨ���������Ǹ�func2ע�ͽ��в���
//forward����ʶ����ֵ��ֵ��������ת��
template<typename T>
void func3(T&& ii)
{
    func1(forward<T>(ii));
}
int main()
{
    //��ͨ����
    Point P1(1, 2);
    //������ֵ��ʹ�ÿ�������
    Point P2 = P1;

    //�ƶ�������Խ���ΪʲôC++11�к����ֲ������ٱ�����ʱ������һ��׷������ַ�Ļ���
    // ��һ�ε�׷�ݾ���Ϊ�˷������ƶ������ܹ��ҵ���ֵ�������ֵ���Գ�Ϊ����ֵ�� �����糣��Ҳ����ֵ�����ǽ���ֵ��

    // lambda ���� �������ڴ�ŵ�ǰ���ڿ��õı�����С���Ų���
    auto f = [](int aa, int b) { Point a(aa, b); return a; };
    //lambda������ֵ �ƶ�����
    Point P3(f(2, 3));
    //lambda������ֵ �ƶ���ֵ
    Point P4 = f(2, 3);

    //����ת��������������һ������a ������ֵ����ֵ�в�ͬ�Ĳ���������ͨ��һ������bȥ��������������Ҫȷ������b�ڲ������ݵĹ������ܱ�֤����ֵ�����ԡ�
    int ii = 3;
    func2(ii);
    func2(3);
    func3(ii);
    func3(3);
    return 0;
}