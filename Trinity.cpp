
#include "Matrix.h"
#include <iostream>
using namespace std;


int main()
{
    Matrix matrix(3, 3);
    matrix.set_el(0, 0, 0);
    matrix.set_el(0, 1, 1);
    matrix.set_el(0, 2, 2);
    matrix.set_el(1, 0, 3);
    matrix.set_el(1, 1, 4);
    matrix.set_el(1, 2, 5);
    matrix.set_el(2, 0, 6);
    matrix.set_el(2, 1, 7);
    matrix.set_el(2, 2, 8);
    Matrix matrix1(2, 3);
    cin >> matrix1;
    matrix = matrix1 * matrix;
    cout << matrix;
    return 0;
}

