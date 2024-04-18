//	!!!		Do not modify this file unless you cannot solve the task in any other way, please.	!!!
// Requirement base tests

#include <gtest/gtest.h>
#include <MatrixOperation.hpp>

namespace MatrixOperation_RequirementBase_UT
{
using MatrixOperation_t = MatrixHandling::TMatrixOperation<>;
using Matrix_t = MatrixOperation_t::MatrixContainer_t::value_type;

TEST(MatrixOperation, OperationWithSameSizeArguments_then_ResultIsTheSumOfArguments)
{
	//Preparation
	typename MatrixOperation_t::MatrixContainer_t leftMatrixes;
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size; ++i)
	{
		typename Matrix_t::value_type insertableMatrixValues[Matrix_t::RowCount * Matrix_t::CollumnCount] = { 0 };
		typename MatrixOperation_t::MatrixContainer_t::value_type insertableMatrix(insertableMatrixValues);
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				insertableMatrix[j][k] = static_cast<int>(i * k * j);
			}
		}
		leftMatrixes.push_back(insertableMatrix);
	}
	typename MatrixOperation_t::MatrixContainer_t rightMatrixes = leftMatrixes;


	MatrixOperation_t underTestInst;
	MatrixOperation_t::MatrixContainer_t resultMatrixes;
	underTestInst.DestinationMatrixes(resultMatrixes);

	//Action
	underTestInst(leftMatrixes, rightMatrixes);

	//Expectations
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size; ++i)
	{
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				EXPECT_EQ(leftMatrixes[i][j][k] + rightMatrixes[i][j][k], resultMatrixes[i][j][k]);
			}
		}
	}
}

TEST(MatrixOperation, OperationWithRightLessSize_then_ResultIsTheSumOfArgumentsWithLesserSize)
{
	//Preparation
	typename MatrixOperation_t::MatrixContainer_t leftMatrixes;
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size; ++i)
	{
		typename Matrix_t::value_type insertableMatrixValues[Matrix_t::RowCount * Matrix_t::CollumnCount] = { 0 };
		typename MatrixOperation_t::MatrixContainer_t::value_type insertableMatrix(insertableMatrixValues);
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				insertableMatrix[j][k] = static_cast<int>(i * k * j);
			}
		}
		leftMatrixes.push_back(insertableMatrix);
	}

	typename MatrixOperation_t::MatrixContainer_t rightMatrixes = leftMatrixes;
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size - 1; ++i)
	{
		typename Matrix_t::value_type insertableMatrixValues[Matrix_t::RowCount * Matrix_t::CollumnCount] = { 0 };
		typename MatrixOperation_t::MatrixContainer_t::value_type insertableMatrix(insertableMatrixValues);
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				insertableMatrix[j][k] = static_cast<int>(i * k * j);
			}
		}
		rightMatrixes.push_back(insertableMatrix);
	}


	MatrixOperation_t underTestInst;
	MatrixOperation_t::MatrixContainer_t resultMatrixes;
	underTestInst.DestinationMatrixes(resultMatrixes);

	//Action
	underTestInst(leftMatrixes, rightMatrixes);

	//Expectations
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size - 1; ++i)
	{
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				EXPECT_EQ(leftMatrixes[i][j][k] + rightMatrixes[i][j][k], resultMatrixes[i][j][k]);
			}
		}
	}
}

TEST(MatrixOperation, OperationWithLeftLessSize_then_ResultIsTheSumOfArgumentsWithLesserSize)
{
	//Preparation
	typename MatrixOperation_t::MatrixContainer_t leftMatrixes;
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size - 1; ++i)
	{
		typename Matrix_t::value_type insertableMatrixValues[Matrix_t::RowCount * Matrix_t::CollumnCount] = { 0 };
		typename MatrixOperation_t::MatrixContainer_t::value_type insertableMatrix(insertableMatrixValues);
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				insertableMatrix[j][k] = static_cast<int>(i * k * j);
			}
		}
		leftMatrixes.push_back(insertableMatrix);
	}

	typename MatrixOperation_t::MatrixContainer_t rightMatrixes = leftMatrixes;
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size; ++i)
	{
		typename Matrix_t::value_type insertableMatrixValues[Matrix_t::RowCount * Matrix_t::CollumnCount] = { 0 };
		typename MatrixOperation_t::MatrixContainer_t::value_type insertableMatrix(insertableMatrixValues);
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				insertableMatrix[j][k] = static_cast<int>(i * k * j);
			}
		}
		rightMatrixes.push_back(insertableMatrix);
	}


	MatrixOperation_t underTestInst;
	MatrixOperation_t::MatrixContainer_t resultMatrixes;
	underTestInst.DestinationMatrixes(resultMatrixes);

	//Action
	underTestInst(leftMatrixes, rightMatrixes);

	//Expectations
	for (size_t i = 0; i < MatrixOperation_t::MatrixContainer_t::max_size - 1; ++i)
	{
		for (size_t j = 0; j < MatrixOperation_t::MatrixContainer_t::value_type::RowCount; ++j)
		{
			for (size_t k = 0; k < MatrixOperation_t::MatrixContainer_t::value_type::CollumnCount; ++k)
			{
				EXPECT_EQ(leftMatrixes[i][j][k] + rightMatrixes[i][j][k], resultMatrixes[i][j][k]);
			}
		}
	}
}
}