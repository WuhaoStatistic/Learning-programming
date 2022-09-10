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


//使用时 模板必须能推导出具体的类型
template<class T> //template<class T>  用typename或者用class是一样的
void myswap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void mySort(T arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        int max = i;
        for (size_t j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;

            }
        }
        if (max != i)
            myswap(arr[max], arr[i]);
    }
}
template<typename T>
void mySort2(T arr[], int len)
{
    for (size_t i = 0; i < len - 1; i++)
    {

        for (size_t j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])

                myswap(arr[j], arr[j + 1]);
        }
    }
}
template<typename T>
void print(T a[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << a[i] << ' ';
    }
}
int main()
{
    int a[6] = { 2,5,3,6,74,4 };
    mySort2(a, 6);
    print(a, 6);
    return 0;
}
