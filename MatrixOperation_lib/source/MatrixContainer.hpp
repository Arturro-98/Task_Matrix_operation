

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

    // Get the number of matrices in the container
    std::size_t size() const {
        return matrices.size();
    }
    
};

}