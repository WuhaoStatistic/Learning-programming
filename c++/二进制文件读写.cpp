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


class Person
{
public:
    Person(string a, int b)
    {
        strcpy_s(name, a.c_str());
        age = b;
    }
    Person() {}
    char name[64]; // �����ƶ�дʱ��ò�Ҫʹ��string���ײ㻹��cд�� cû��string
    int age;
};

int main()
{
    //������д�ļ�
    ofstream ofs("person.txt", ios::out | ios::binary);
    Person p = Person("asd", 16);
    ofs.write((const char*)&p, sizeof(Person)); //дҪǿתΪconst char*
    ofs.close();


    //�����ƶ��ļ�
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (ifs.is_open())
    {
        Person p1;
        ifs.read((char*)&p1, sizeof(Person)); //��Ҫ������תΪ char*
        cout << p1.age << endl;
        cout << p1.name;
        ifs.close();
    }
    else
        cout << "fail to open file" << endl;

    return 0;
}
