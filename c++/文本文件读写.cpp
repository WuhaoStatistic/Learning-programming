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
using namespace std;


int main()
{
    ofstream ofs;
    //写文件
    ofs.open("a.txt", ios::out);// 默认是覆盖 追加用ios::app

    ofs << "This is a test" << endl;
    ofs << "sdssss" << endl;
    ofs.close();

    //读文件
    ifstream ifs;
    ifs.open("a.txt", ios::in | ios::out);
    if (ifs.is_open())
    {
        /*读取方式一，这样每一个空格隔开的是一行
        char buf[1024] = { 0 };
        while (ifs >> buf)
            cout << buf << endl;
        */

        //读取方式二
        /*
        char buf[1024] = { 0 };
        while (ifs.getline(buf, sizeof(buf)))
        {
            cout << buf<<endl;
        }
        */

        /*读取方式三
        string buf;
        while (getline(ifs, buf))
            cout << buf << endl;
        */

        /*读取方式四
        * 这种方式能读到换行符 ，所以不需要endl，但不是很推荐
        * 效率低
        char c;
        while ((c = ifs.get()) != EOF)
            cout << c;
        */


    }
    else
        cout << "false open" << endl;

    return 0;
}
