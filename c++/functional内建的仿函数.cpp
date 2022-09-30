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

// 内建仿函数   算术仿函数
// negate plus
void test01()
{
    negate<int>n;
    cout << n(50);
}

int main()
{
    test01();
    return 0;
}