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
    //д�ļ�
    ofs.open("a.txt", ios::out);// Ĭ���Ǹ��� ׷����ios::app

    ofs << "This is a test" << endl;
    ofs << "sdssss" << endl;
    ofs.close();

    //���ļ�
    ifstream ifs;
    ifs.open("a.txt", ios::in | ios::out);
    if (ifs.is_open())
    {
        /*��ȡ��ʽһ������ÿһ���ո��������һ��
        char buf[1024] = { 0 };
        while (ifs >> buf)
            cout << buf << endl;
        */

        //��ȡ��ʽ��
        /*
        char buf[1024] = { 0 };
        while (ifs.getline(buf, sizeof(buf)))
        {
            cout << buf<<endl;
        }
        */

        /*��ȡ��ʽ��
        string buf;
        while (getline(ifs, buf))
            cout << buf << endl;
        */

        /*��ȡ��ʽ��
        * ���ַ�ʽ�ܶ������з� �����Բ���Ҫendl�������Ǻ��Ƽ�
        * Ч�ʵ�
        char c;
        while ((c = ifs.get()) != EOF)
            cout << c;
        */


    }
    else
        cout << "false open" << endl;

    return 0;
}
