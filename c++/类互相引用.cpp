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
    // 这样不会出问题的原因在于 首先已经声明了B 编译器认识B
    // 在编译的时候因为我们定义的是指针B， 编译器只需要给他分配一个指针应该有的空间(int)即可
    // 
    B* b_;
};

class B {
public:
    B() {
        bb_ = 'B';
    }
    char bb_;
    //在这里就无所谓指针不指针了，因为编译器走到这一步已经认识了A
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


