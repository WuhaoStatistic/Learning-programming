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


// ����������д������ظ����������⣬sptr2��3���������ü���ֵ����Ϊ1 
// �о�����Ϊ���Ƕ��Ǵ���ָͨ�빹�����ģ������sptr��Ϊshared_ptr�Ͳ�������� ֻ�����ü�������1
void test()
{
    //int *sptr = new int(3); //�������
    shared_ptr<int> sptr(new int(3)); //û���� �����������ü���
    {
        shared_ptr<int> sptr2(sptr);
        {
            shared_ptr<int> sptr3(sptr);
        }
    }
}
// shared ptr��ǿָ�룬��ʱ��������Ҫ��ָ�������ѭ������ �����쳣����
class B;
class A
{
public:
    A() {}
    void set(shared_ptr<B> b) {
        this->b = b;
    }
    //�����Ϊ��ָ��
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
    //ͨ�������ڴ� ����ȷʵ�������������������Ժ������ģ�ԭ����
    //���ü�����ѭ�������Ժ��Ϊ��2����ô�������������Ժ� ���ü��������1.������������1�Ժ� ��ʣ��1 ���Զ��޷�������
    //��ʱ��ֻҪ��һ�������� ��һ���ͻ��������������������Ҫ������һ������ָ���Ϊweak_ptr����
    {
        shared_ptr<A> pa(new A());
        //shared_ptr<B> pb(new B());
        shared_ptr<B> pb(new B());
        pa->set(pb);
        pb->set(pa);
        //��Ϊ��ָ���Ժ� ������Ϊ1 2.
        cout << pa->b.use_count() << endl;
        cout << pb->a.use_count();
    }
    return 0;
}