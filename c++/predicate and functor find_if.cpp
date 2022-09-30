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
using namespace std;

//返回bool类型的 仿函数称为谓词
//               functor predicate
class GreaterFive
{
public:
    bool operator()(int a)
    {
        return a > 5;
    }
};
int main()
{
    vector<int> a = { 2,3,4,5,6,7,8,9 };
    vector<int>::iterator it = find_if(a.begin(), a.end(), GreaterFive());
    cout << *it;
    return 0;
}