//	!!!		Do not modify this file unless you cannot solve the task in any other way, please.	!!!

#include <exception>

//This class designed to represent a 2 dimension matrix.
//This class will be used in a safty critical area,
//in these places its values must always be predefined.
//Therefore the using of default constructor isn't recommended.
//Because of safety critical requirements, the dynamic allocation isn't allowed.
template<typename t_ValueType, size_t t_CollumnCount, size_t t_RowCount>
struct Matrix
{
	static constexpr size_t CollumnCount = t_CollumnCount;
	static constexpr size_t RowCount = t_CollumnCount;
	using value_type = t_ValueType;

	Matrix() = delete;

	Matrix(value_type values[RowCount * CollumnCount])
	{
		constexpr size_t fullSize = RowCount * CollumnCount;
		for (size_t index = 0; index < fullSize; ++index)
		{
			this->values[index] = values[index];
		}
	}

	value_type* operator[] (size_t rowIndex)
	{
		return values + rowIndex * CollumnCount;
	}

	const value_type* operator[] (size_t rowIndex) const
	{
		return values + rowIndex * CollumnCount;
	}

	void* operator new(size_t)
	{
		throw std::exception("Dynamic allocation isn't allowed.");
	}

	void operator delete(void*)
	{}

	void* operator new(size_t, void* where)
	{
		return where;
	}

	void operator delete(void*, void*)
	{}

	void* operator new[](size_t)
	{
		throw std::exception("Dynamic allocation isn't allowed.");
	}

	void operator delete[](void*)
	{}

	void* operator new[](size_t, void* where)
	{
		return where;
	}

	void operator delete[](void*, void*)
	{}

protected:
	value_type values[RowCount * CollumnCount];
};