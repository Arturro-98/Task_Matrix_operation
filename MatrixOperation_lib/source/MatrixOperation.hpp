#pragma once

#include "Matrix.hpp"
#include "MatrixContainer.hpp"

#include "MyMatrix.hpp"
#include <algorithm>

namespace MatrixHandling
{

//Implementeation sceleton yet, not ready, if somebody find any error, welcome to fix it.
template<typename t_MatrixContainer>
struct TMatrixOperation
{
    using MatrixContainer_t = t_MatrixContainer;

	void operator()(MatrixContainer_t left, MatrixContainer_t right) {
		for (std::size_t matrixIndex = 0; matrixIndex < std::min(left.size(), right.size()); matrixIndex++)
		{
			for (std::size_t m = 0; m < MyMatrix::RowCount; m++)
			{
				for (std::size_t n = 0; n < MyMatrix::CollumnCount; n++)
				{
					this->DestinationMatrixes().at(matrixIndex)[m][n] = left.at(matrixIndex)[m][n] + right.at(matrixIndex)[m][n];
				}
			}
		}
	}


    const MatrixContainer_t& DestinationMatrixes() const { return *this->destinationMatrixes; }
    MatrixContainer_t& DestinationMatrixes() { return *this->destinationMatrixes; }
    void DestinationMatrixes(const MatrixContainer_t& value) { this->destinationMatrixes = const_cast<MatrixContainer_t*>(&value); }

protected:
    MatrixContainer_t* destinationMatrixes;
};



}