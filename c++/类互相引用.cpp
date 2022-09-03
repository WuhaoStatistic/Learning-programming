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


class B;

class A {
public:
    A(B* b) {
        aa_ = 'A';
        b_ = b;
    }
    char aa_;
    B* b_;
};

class B {
public:
    B() {
        bb_ = 'B';
    }
    char bb_;
    A a_;
};



int main()
{
    B b;
    A a = A(&b);
    
    b.a_ = a;
    cout << a.aa_ << a.b_->bb_;
    cout << b.bb_ << b.a_.aa_;
    return 0;

}


