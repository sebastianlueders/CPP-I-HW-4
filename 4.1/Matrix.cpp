#include "Matrix.h"
#include <iostream>
#include <chrono>
using namespace mpcs51044;
using namespace std;

static void expect(bool cond, const char* msg) {
    if (!cond) {
        cerr << "TEST FAILED: " << msg << "\n";
        std::exit(1);
    }
}

int main()
{
	Matrix<3, 3> A = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    Matrix<3, 3> B = {
        { 10, 20, 30 },
        { 40, 50, 60 },
        { 70, 80, 90 }
    };

    Matrix<3, 3> C = A + B;   // test +
    Matrix<3, 3> D = A;       // copy A
    D += B;                   // test +=

    // Check a couple entries
    expect(C(0,0) == 11, "A+B (0,0) should be 11");
    expect(C(2,2) == 99, "A+B (2,2) should be 99");
    expect(D(0,0) == 11, "A+=B (0,0) should be 11");
    expect(D(2,2) == 99, "A+=B (2,2) should be 99");

    // Check C and D match everywhere
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            expect(C(i,j) == D(i,j), "operator+ result should match operator+=");

    cout << "operator+ and operator+= tests passed.\n\n";
	
	auto start = chrono::system_clock::now();
	Matrix<3, 3> m = { 
			{ 1, 2, 3, }, 
			{ 4, 5, 6, }, 
			{ 7, 8, 9, } 
	};
	static double total;
	for (int i = 0; i < 100'000'000; i++) {
		m(1, 1) = i;
		total += m.determinant();
	}
	cout << chrono::duration<double>(chrono::system_clock::now() - start).count() << " seconds\n";
}