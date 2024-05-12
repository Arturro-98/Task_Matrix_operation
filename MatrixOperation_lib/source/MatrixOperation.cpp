// Include the necessary header files
#include "MatrixOperation.hpp"
#include "Matrix.hpp"
#include "MatrixContainer.hpp"

int main() {
    // Define the type of your MatrixContainer
    using MyMatrix = Matrix<double, 3, 3>;  // Assuming Matrix is a template that takes value type, row count, and column count
    using MyMatrixContainer = Containers::TMatrixContainer<MyMatrix>;  // Assuming MatrixContainer is a template that takes a Matrix type

    // Create some MatrixContainers and fill them with data
    MyMatrixContainer myLeftContainer = {
        MyMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9})  // First matrix
        // ... more matrices
    };
    MyMatrixContainer myRightContainer = {
        MyMatrix({9,8,7,6,5,4,3,2,1})  // Second matrix
        // ... more matrices
    };

    // Create a TMatrixOperation object
   MatrixHandling::TMatrixOperation<MyMatrixContainer> operation;

    // Use the TMatrixOperation object
    operation(myLeftContainer, myRightContainer);

    const MyMatrixContainer& result = operation.DestinationMatrixes();
    for (const auto& matrix : result) {
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                std::cout << element << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}


