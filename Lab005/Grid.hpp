//	Grid class implementation

//	Empty constructor
template <typename T>
Grid<T>::Grid() : data(nullptr), y_size(0), x_size(0) { }

//	Constructor for 1D Grid
//	Arguments:
//		t (T const&): value that will be in the only cell of this Grid
template <typename T>
Grid<T>::Grid(T const& t) : data(new T(t)), y_size(1), x_size(1) { }

//	Constructor from given size
//	Arguments:
//		y_size, x_size (size_type): dimensions of this Grid
template <typename T>
Grid<T>::Grid(Grid<T>::size_type y_size, Grid<T>::size_type x_size) :
	data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) { }

//	Constructor for one value
//	Arguments:
//		y_size, x_size (size_type): dimensions of this Grid
//		t (T const&): value that will fill all the cells of this Grid
template <typename T>
Grid<T>::Grid(Grid<T>::size_type y_size, Grid<T>::size_type x_size, T const& t) :
	data(new T[y_size * x_size](t)), y_size(y_size), x_size(x_size) { }

//	Constructor from given data
//	Arguments:
//		data (T*): a pointer to the data, that this Grid will consist of
//		y_size, x_size (size_type): dimensions of this Grid
template <typename T>
Grid<T>::Grid(T* data, Grid<T>::size_type y_size, Grid<T>::size_type x_size) :
	data(data), y_size(y_size), x_size(x_size) { }

//	Destructor
template <typename T>
Grid<T>::~Grid()
{
	if (data)
		delete[] data;
}

//	Copy constructor
//	Arguments:
//		src (Grid<T> const&): a source Grid, whose data and dimensions are copied to this Grid
template <typename T>
Grid<T>::Grid(Grid<T> const& src) : Grid(src.y_size, src.x_size)
{
	for (Grid<T>::size_type idx = 0; idx != y_size * x_size; ++idx)
		data[idx] = src.data[idx];
}

//	Copy assignment operator
//	Arguments:
//		src (Grid<T> const&): a source Grid, whose data and dimensions are copied to this Grid
//	Return value:
//		Grid<T>&: a link to the assigned element
template <typename T>
Grid<T>& Grid<T>::operator=(Grid<T>& src)
{
	//	Note: wont work with overloaded operator&
	if (this == &src)
		return *this;

	Grid<T> tmp(src);
	std::swap(data, tmp.data);
	std::swap(y_size, tmp.y_size);
	std::swap(x_size, tmp.x_size);
}

//	Move constructor
//	Arguments:
//		src (Grid<T> const&): a source Grid, whose data and dimensions are moved to this Grid
template <typename T>
Grid<T>::Grid(Grid<T>&& src) : Grid()
{
	std::swap(data, src.data);
	std::swap(y_size, src.y_size);
	std::swap(x_size, src.x_size);
}

//	Move assignment operator
//	Arguments:
//		src (Grid<T> const&): a source Grid, whose data and dimensions are moved to this Grid
//	Return value:
//		Grid<T>&: a link to the assigned element
template <typename T>
Grid<T>& Grid<T>::operator=(Grid<T>&& src)
{
	Grid<T> tmp(std::move(src));
	std::swap(data, tmp.data);
	std::swap(y_size, tmp.y_size);
	std::swap(x_size, tmp.x_size);
}

//	Value access operator
//	Arguments:
//		y_idx, x_idx (size_type): indices of desired element
//	Return value:
//		T: value of desired element
template <typename T>
T Grid<T>::operator()(Grid<T>::size_type y_idx, Grid<T>::size_type x_idx) const
{
	return data[y_idx * x_size + x_idx];
}

//	Link access operator
//	Arguments:
//		y_idx, x_idx (size_type): indices of desired element
//	Return value:
//		T&: link to the value of desired element
template <typename T>
T& Grid<T>::operator()(Grid<T>::size_type y_idx, Grid<T>::size_type x_idx)
{
	return data[y_idx * x_size + x_idx];
}

//	Index operator
//	Arguments:
//		y_idx (size_type): index of the line in this Grid to access
//	Return value:
//		T*: a pointer to the begin of array with accessed line
template <typename T>
T* Grid<T>::operator[](Grid<T>::size_type y_idx)
{
	return data + y_idx * x_size;
}

//	Assignment operator for one value
//	Arguments:
//		t (T const&): a value that will fill all the cells of this Grid
//	Return value:
//		Grid<T>&: a link to the assigned element
template <typename T>
Grid<T>& Grid<T>::operator=(T const& t)
{
	for (auto it = data, end = data + x_size * y_size; it != end; ++it)
		*it = t;
	return *this;
}

//	y_size getter
//	Return value:
//		size_type: y axis dimension
template <typename T>
typename Grid<T>::size_type Grid<T>::get_y_size() const
{
	return y_size;
}

//	x_size getter
//	Return value:
//		size_type: x axis dimension
template <typename T>
typename Grid<T>::size_type Grid<T>::get_x_size() const
{
	return x_size;
}