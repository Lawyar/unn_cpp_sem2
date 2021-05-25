#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction A(1, 2);
    Fraction B(6, 8);
    A.showme();
    B.showme();
    Fraction C = A + B;
    C.showme();
    C = A * B;
    C.showme();
    C = A / B;
    C.showme();
    Fraction D = B - A;
    D.showme();
    cout << D;
    std::cout << "Hello World!\n";
    return 0;
}
