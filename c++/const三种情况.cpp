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

class Phone
{
public:
	string name;
	mutable string name2;
	/*�������ڲ��ܸı���������
	* this ָ��ı�����һ��ָ�볣�������ָ���ָ���ǲ��ܱ��޸ĵģ�
	* �ڳ�Ա��������+const������thisָ��ģ���thisָ��ָ���ֵҲ�������޸�
	Phone add(string name1) const
	{
		this->name = this->name + name1;
		return *this;
	}
	*/

	// ������ ֻ���޸������mutable�ؼ��ֵı���
	Phone add(string name1)const
	{
		this->name2 = this->name + name1;
		return *this;
	}
	//const ����ǰ�����κ����ķ���ֵ
	const string add1(string name1)
	{
		this->name = this->name2 + name1;
		return this->name;
	}
	/* const Ϊ�˽�ʡ�ռ䣬���ݽ�������ʱ����ʹ��ʵ�δ��ݣ�
	* ������ʵ���ǲ��ܱ��޸ĵģ���ôһ��Ҫ����const,
	* ���º����г����޸�name���ͻᱨ��
	string add2(const string& name)
	{
		name = this->name;
		return name;
	}
	*/
};



int main()
{
	Phone p1;
	p1 = p1.add("sds").add("sdd");

	// const ���η���ֵʱ ��������ֵ��������ֵ���޸�
	//p1.add1("a") = "asd";
	return 0;

	//����������const ���������� Ҳֻ���޸�mutable�ĳ�Ա���ԣ�ֻ�ܵ��ó�����
	const Phone p2;
	
}


