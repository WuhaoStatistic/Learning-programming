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
	/*常函数内不能改变类内属性
	* this 指针的本质是一个指针常量，这个指针的指向是不能被修改的，
	* 在成员函数后面+const是修饰this指针的，让this指针指向的值也不允许被修改
	Phone add(string name1) const
	{
		this->name = this->name + name1;
		return *this;
	}
	*/

	// 常函数 只能修改添加了mutable关键字的变量
	Phone add(string name1)const
	{
		this->name2 = this->name + name1;
		return *this;
	}
	//const 加在前面修饰函数的返回值
	const string add1(string name1)
	{
		this->name = this->name2 + name1;
		return this->name;
	}
	/* const 为了节省空间，传递进函数的时候尽量使用实参传递，
	* 如果这个实参是不能被修改的，那么一定要加上const,
	* 如下函数中尝试修改name，就会报错
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

	// const 修饰返回值时 不允许返回值被当作左值被修改
	//p1.add1("a") = "asd";
	return 0;

	//定义对象加上const 建立常对象 也只能修改mutable的成员属性，只能调用常函数
	const Phone p2;
	
}


