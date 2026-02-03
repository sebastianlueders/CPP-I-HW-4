#include "PSMatrix.h"
#include <iostream>
#include <chrono>
using namespace mpcs51044;
using namespace std;

int main()
{
    using clock = chrono::steady_clock;

    auto start = clock::now();

    Matrix<double, 3, 3> m = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    volatile double total = 0.0;

    for (int i = 0; i < 100'000'000; ++i) {
        m(1, 1) = i;
        total += m.determinant();
    }

    cout << chrono::duration<double>(clock::now() - start).count()
         << " seconds\n";
}