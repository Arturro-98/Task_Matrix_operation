#pragma once    // Added because of compiler error
#include <vector> // as above
#include <stdexcept> // for std::out_of_range

namespace Containers
{

template<typename t_ValueType>
struct TMatrixContainer
{
    std::vector<t_ValueType> matrices;

    // Add a matrix to the container
    void add(const t_ValueType& matrix) {
        matrices.push_back(matrix);
    }

    // Get a matrix from the container
    const t_ValueType& get(std::size_t index) const {
        return matrices[index];
    }

    // Get a matrix from the container with bounds checking
    t_ValueType& at(std::size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return matrices[index];
    }

    const t_ValueType& at(std::size_t index) const {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return matrices[index];
    }

    // Get the number of matrices in the container
    std::size_t size() const {
        return matrices.size();
    }

    // Added begin and end functions
    auto begin() { return matrices.begin(); }
    auto end() { return matrices.end(); }
    auto begin() const { return matrices.begin(); }
    auto end() const { return matrices.end(); }
};

}
