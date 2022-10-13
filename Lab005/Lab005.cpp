﻿#include <cassert>

#include "Grid.h"

void test_1()
{
	Grid<float> g(3, 2, 0.0f);
	assert(3 == g.get_y_size());
	assert(2 == g.get_x_size());

	using gsize_t = Grid<int>::size_type;

	for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
		for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
			assert(0.0f == g[y_idx][x_idx]);

	for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
		for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
			g[y_idx][x_idx] = 1.0f;

	for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
		for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
			assert(1.0f == g[y_idx][x_idx]);
}

/*
void test_2()
{
	Grid<float, 3> const g3(2, 3, 4, 1.0f);
	assert(1.0f == g3(1, 1, 1));

	Grid<float, 2> const g2(2, 5, 2.0f);
	assert(2.0f == g2(1, 1));

	g2 = g3[1];
	assert(1.0f == g2(1, 1));
}
*/

int main()
{
	//	Test for index operator
	test_1();

	//	Test for multidimensional Grid
	//test_2();

	return 0;
}