//g++ 6.3.0

#include <iostream>
#include "Num_sys.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    NumberSystem a(228, 2);

    string in = "100102010101";
    a.set_value(in.c_str());

    return 0;
}
