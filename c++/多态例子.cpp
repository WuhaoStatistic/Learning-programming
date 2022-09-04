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


class BaseCalculator
{
public:
    int m_num1;
    int m_num2;
    virtual int getResults()
    {
        return 0;
    }
};

class AddCalculator : public BaseCalculator
{
    int getResults()
    {
        return m_num1 + m_num2;
    }
};

class SubCalculator : public BaseCalculator
{
    int getResults()
    {
        return m_num1 - m_num2;
    }
};

class MulCalculator : public BaseCalculator
{
    int getResults()
    {
        return m_num1 * m_num2;
    }
};


int main()
{
    BaseCalculator* b = new SubCalculator;
    b->m_num1 = 10;
    b->m_num2 = 20;
    cout << b->getResults() << endl;
    delete b;

    b = new AddCalculator;
    b->m_num1 = 4;
    b->m_num2 = 6;
    cout << b->getResults() << endl;

    return 0;
}

