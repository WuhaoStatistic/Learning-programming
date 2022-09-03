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


int& test()
{
	static int a = 20;
	return a;
}
//对于某些不允许重新创建的变量,
//比如在重载左移运算符时，全局只能有一个ostream类的cout，但是我们重载的函数又必须返回cout，这个时候就得使用
//引用做函数的返回值来确保我们始终在修改原先的那个cout而不是创建了一个新的.
int main()
{   
	int &b = test();
	cout << b<<endl;
	test() = 1000;
	cout << b;
	return 0;
}

