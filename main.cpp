#include <iostream>
#include "linear-algebra.h"

using  namespace std;

int main() {

    Matrix A{{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}};

    Point x{1, 2, 3};

    cout << Point(A * x) << endl;


}