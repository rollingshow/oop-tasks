//g++ 6.3.0

#include <iostream>
#include "Num_sys.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Initializing 2 objects, first with value 228(10) -> (2)" << endl;
    NumberSystem a(228, 2);
    NumberSystem b;

    cout << "Second object with value 100101010101(2)" << endl;
    string in = "100101010101";
    b.set_value(in.c_str());

    cout << "Changing num.sys. of first object to 8" << endl;
    a.set_system(8);

    NumberSystem c;
    c = a + b;
    cout << "obj1 + obj2 = " << c.get_value() << "(" << c.get_system() << ")" << endl;
    c = a - b;
    cout << "obj1 - obj2 = " << c.get_value() << "(" << c.get_system() << ")" << endl;
    c = a * b;
    cout << "obj1 * obj2 = " << c.get_value() << "(" << c.get_system() << ")" << endl;
    c = a / b;
    cout << "obj1 / obj2 = " << c.get_value() << "(" << c.get_system() << ")" << endl;

    return 0;
}
