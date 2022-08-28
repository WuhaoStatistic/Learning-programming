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
int main()
{   
	int &b = test();
	cout << b<<endl;
	test() = 1000;
	cout << b;
	return 0;
}

