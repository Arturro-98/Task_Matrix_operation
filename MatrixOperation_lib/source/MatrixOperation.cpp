// Include the necessary header files
#include "MatrixOperation.hpp"
#include "Matrix.hpp"
#include "MatrixContainer.hpp"
#include "MyMatrix.hpp"

#include <iostream>

// Define a derived class from Matrix
//template<typename t_ValueType, size_t t_CollumnCount, size_t t_RowCount>

int main() {
    // Define the type of your MatrixContainer
    using MyMatrixContainer = Containers::TMatrixContainer<MyMatrix>;  // Assuming MatrixContainer is a template that takes a Matrix type

    // Create some MatrixContainers and fill them with data
    MyMatrixContainer myLeftContainer = {
        {MyMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9})}  // First matrix
        // ... more matrices
    };
    MyMatrixContainer myRightContainer = {
        {MyMatrix({9,8,7,6,5,4,3,2,1})}  // Second matrix
        // ... more matrices
    };

    // Create a TMatrixOperation object
    MatrixHandling::TMatrixOperation<MyMatrixContainer> operation;

    // Use the TMatrixOperation object
    operation(myLeftContainer, myRightContainer);

    const MyMatrixContainer& result = operation.DestinationMatrixes();
    for (const auto& matrix : result) {
        for (const auto* row = matrix.getValues(); row != matrix.getValues() + MyMatrix::RowCount * MyMatrix::CollumnCount; ++row) {
            std::cout << *row << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}