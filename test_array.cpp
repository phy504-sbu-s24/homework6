#include "array.H"

int main() {

    // create an array A and initialize it with the sequence 0, ..., 35

    Array A(6, 6);

    assert(A.nelements() == 36);

    for (int i = 0; i < A.nelements(); ++i) {
        A.flat(i) = static_cast<double>(i);
    }

    // create a copy of A

    const Array B = A;

    // multiply all of the elements in A by 2

    A *= 2.0;

    std::cout << A << std::endl;

    // some assertion checks

    assert(A(2, 2) == 28);
    assert(A(5, 5) == 70);

    assert(A.min() == 0);
    assert(A.max() == 70);

    // B should be unchanged

    std::cout << B << std::endl;

}
