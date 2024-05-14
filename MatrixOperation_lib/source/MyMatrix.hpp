#pragma once

#include "Matrix.hpp"

// Define a derived class from Matrix
template<typename t_ValueType, size_t t_CollumnCount, size_t t_RowCount>
struct MyDerivedMatrix : public Matrix<t_ValueType, t_CollumnCount, t_RowCount>
{
    using Base = Matrix<t_ValueType, t_CollumnCount, t_RowCount>;
    using Base::Base;  // Inherit constructors

    const double* getValues() const {
        return this->values;
    }
};

// Then use MyDerivedMatrix instead of Matrix
using MyMatrix = MyDerivedMatrix<double, 3, 3>;
