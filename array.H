#ifndef ARRAY_H
#define ARRAY_H

#include <limits>
#include <vector>
#include <iostream>
#include <cassert>

// a contiguous 2-d array

// here the data is stored in row-major order in a 1-d memory space
// managed as a vector.  We overload () to allow us to index this as
// a(irow, icol)

class Array {

private:

    std::size_t _rows;
    std::size_t _cols;
    std::vector<double> _data;

public:

    Array (std::size_t rows, std::size_t cols, double val=0.0)
        : _rows{rows},
          _cols{cols},
          _data(rows * cols, val)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        assert (rows > 0);
        assert (cols > 0);

    }

    // copy constructor
    Array (const Array& src) = default;

    // assignment operator
    Array& operator= (const Array& src) = default;

    // destructor
    ~Array() = default;

    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array

    inline std::size_t ncols() const { return _cols;}
    inline std::size_t nrows() const { return _rows;}

    inline std::size_t nelements() const { return _cols * _rows;}

    inline double& operator()(int row, int col) {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    inline const double& operator()(int row, int col) const {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    inline double & flat(int element) {
        assert (element >= 0 && element < _rows * _cols);
        return _data[element];
    }

    inline const double & flat(int element) const {
        assert (element >= 0 && element < _rows * _cols);
        return _data[element];
    }

    double min() const {
        double arr_min{std::numeric_limits<double>::max()};
        for (const double& e : _data) {
            arr_min = std::min(arr_min, e);
        }
        return arr_min;
    }

    double max() const {
        double arr_max{std::numeric_limits<double>::lowest()};
        for (const double& e : _data) {
            arr_max = std::max(arr_max, e);
        }
        return arr_max;
    }

    inline Array& operator*= (double a) {
        for (auto & e : _data) {
            e *= a;
        }
        return *this;
    }


};

// the << operator is not part of the of the class, so it is not a member

inline
std::ostream& operator<< (std::ostream& os, const Array& a) {

    for (std::size_t row=0; row < a.nrows(); ++row) {
        for (std::size_t col=0; col < a.ncols(); ++col) {
            os << a(row, col) << " ";
        }
        os << std::endl;
    }

    return os;
}

#endif