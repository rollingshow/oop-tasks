//g++ 6.3.0

#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    String x("pancake");

    String a = x.right(4);
    cout << "[" << a.to_char() << "] length=" << a.length() << endl;

    String b = x.left(3);
    cout << "[" << b.to_char() << "] length=" << b.length() << endl;

    String c = x.mid(2);
    cout << "[" << c.to_char() << "] length=" << c.length() << endl;

    String d = x.mid(1, 2);
    cout << "[" << d.to_char() << "] length=" << d.length() << endl;

    String e = a.concat(b);
    cout << "[" << e.to_char() << "] length=" << e.length() << endl;

    return 0;
}
