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
    //����
    A& operator++()
    {
        this->m++;
        return *this;
    }
    // ��ռλ����������ǰ�úͺ�������
    // ����++��Ϊ���ص��Ǿֲ��ı��� �ֲ������������û������
    // ��������ֻ�ܷ���ֵ��
    A operator++(int)
    {
        A a = *this;
        this->m++;
        return a;
    }

    A& operator=(A& a)
    {
        // ���������ж���ָ�������ʱ�򣬸�ֵ��Ҫ������У���������ָ��ָ��ͬһ���ڴ棬
        // һ������֮����һ���ͻ�����⡣
        // =��ֵ������ͬ��������죬��һ�������Ѿ����������������Ȼ������Ҫ���и�ֵ����
        // ���ʱ����������һ�¶������ڴ棬��ô��Ȼ�Ǹ�ָ�뱻�����ˣ�����ָ����ָ����Ǹ��ڴ�ռ���Ȼ��ռ��
        if (this->n != NULL)
        {
            delete this->n;
            this->n = NULL;//��׼�ͷ��ڴ����
        }
        this->n = new int(*a.n);//�����ò������µĿռ�
        this->m = a.m;
        return *this;
    }

    A& operator*(A a1)
    {
        this->m = a1.m * this->m;
        return *this;
    }
};



//cout ȫ��ֻ����һ�� ����һ��Ҫ���ã�����ᴴ��һ���µ�
// cout ����һ��Ҫ����cout����������������׷�� << ��
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

    //������ͨ�Ӻ�
    cout << (a1 + a2) + a2 << endl;

    // ������غ������Ƿ������õĻ�����仰�ᱨ����Ϊ���ص�ʱ�����ÿ������캯������һ��copy�����copy����ʱ�ģ���ʱ��ֻ����Ϊ��ֵ
    // ��͵����� ++(++a1)ֻ���޸�һ�� a1����Ϊ�ڶ��β���������ʱ�ı����Ͻ��в���
    cout << ++(++a1) << endl;;

    cout << a1++ << endl;;
    cout << a1 << endl;

    //����= *
    a3 = a2 = a1;
    a3 = a1 * a2 * a2;
    cout << *a3.n << endl;
    cout << a3 << endl;
    return 0;

}



