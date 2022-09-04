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
    char name[64]; // 二进制读写时最好不要使用string，底层还是c写的 c没有string
    int age;
};

int main()
{
    //二进制写文件
    ofstream ofs("person.txt", ios::out | ios::binary);
    Person p = Person("asd", 16);
    ofs.write((const char*)&p, sizeof(Person)); //写要强转为const char*
    ofs.close();


    //二进制读文件
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (ifs.is_open())
    {
        Person p1;
        ifs.read((char*)&p1, sizeof(Person)); //读要将对象转为 char*
        cout << p1.age << endl;
        cout << p1.name;
        ifs.close();
    }
    else
        cout << "fail to open file" << endl;

    return 0;
}
