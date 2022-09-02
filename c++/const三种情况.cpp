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
	Phone& add(string name1)
	{
		this->name = this->name + name1;
		return *this;
	}
};



int main()
{
	Phone p1 ;
	p1 = p1.add("sds").add("sdd");
	return 0;
}

