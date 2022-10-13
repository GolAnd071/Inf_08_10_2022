#pragma once

#include <algorithm>

//	Grid class declaration

template <typename T>
class Grid final
{
public:
	using value_type = T;
	using size_type = unsigned;

private:
	//	Grid data and dimensions
	T* data;
	size_type y_size, x_size;

public:
	//	Empty constructor
	Grid();

	//	Constructor for 1D Grid
	Grid(T const&);

	//	Constructor from given size
	Grid(size_type, size_type);

	//	Constructor for one value
	Grid(size_type, size_type, T const&);

	//	Constructor from given data
	Grid(T*, size_type, size_type);

	//	Destructor
	~Grid();

	//	Copy constructor
	Grid(Grid<T> const&);

	//	Copy assignment operator
	Grid<T>& operator=(Grid<T>&);

	//	Move constructor
	Grid(Grid<T>&&);

	//	Move assignment operator
	Grid<T>& operator=(Grid<T>&&);

	//	Value access operator
	T operator()(size_type, size_type) const;
	
	//	Link access operator
	T& operator()(size_type, size_type);

	//	Index operator
	T* operator[](size_type);

	//	Assignment operator for one value
	Grid<T>& operator=(T const&);

	//	y_size getter
	size_type get_y_size() const;

	//	x_size getter
	size_type get_x_size() const;
};

//	Repair template export in C++2a
#include "Grid.hpp"