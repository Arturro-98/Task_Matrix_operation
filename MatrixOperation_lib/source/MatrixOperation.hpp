#pragma once

#include "Matrix.hpp"
#include "MatrixContainer.hpp"

#include <algorithm>

namespace MatrixHandling
{

//Implementeation sceleton yet, not ready, if somebody find any error, welcome to fix it.
template<typename t_MatrixContainer>
struct TMatrixOperation
{
	using MatrixContainer_t = t_MatrixContainer;

	//TODO: the inputs should be const
	void operator()(MatrixContainer_t left, MatrixContainer_t right);

	const MatrixContainer_t& DestinationMatrixes() const { return *this->destinationMatrixes; }
	MatrixContainer_t& DestinationMatrixes() { return *this->destinationMatrixes; }
	void DestinationMatrixes(const MatrixContainer_t& value) { this->destinationMatrixes = const_cast<MatrixContainer_t*>(&value); }

protected:
	MatrixContainer_t* destinationMatrixes;
};

template<typename t_MatrixContainer>
inline void TMatrixOperation<t_MatrixContainer>::operator()(MatrixContainer_t left, MatrixContainer_t right)
{
	for (std::size_t matrixIndex = 0; matrixIndex < std::min(left.size(), right.size()); matrixIndex++)
	{
		for (std::size_t n = 0; n < typename MatrixContainer_t::value_type::CollumnCount; n++)
		{
			for (std::size_t m = 0; m < typename MatrixContainer_t::value_type::RowCount; m++)
			{
				this->DestinationMatrixes()[matrixIndex][m][n] = left[matrixIndex][m][n] + right[matrixIndex][m][n];
			}
		}
	}

	for (std::size_t matrixIndex = 0; matrixIndex < std::min(left.size(), right.size()); matrixIndex++)
	{
		for (std::size_t m = 0; m < typename MatrixContainer_t::value_type::RowCount; m++)
		{
			for (std::size_t n = 0; n < typename MatrixContainer_t::value_type::CollumnCount; n++)
			{
				this->DestinationMatrixes()[matrixIndex][m][n] = left[matrixIndex][m][n] + right[matrixIndex][m][n];
			}
		}
	}
}

}