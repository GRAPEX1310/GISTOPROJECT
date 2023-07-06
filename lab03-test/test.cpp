#include "histogram.h"
#include <cassert>

void test_positive() 
{
	double min = 0;
	double max = 0;
	find_minmax({ 1, 2, 3 }, min, max);
	assert(min == 1);
	assert(max == 3);
}

void test_below_zero()
{
	double min = 0;
	double max = 0;
	find_minmax({ -1, -2, -3 }, min, max);
	assert(min == -3);
	assert(max == -1);
}

void test_empty_array()
{
	double min = 0;
	double max = 0;
	find_minmax({}, min, max);
	assert(min == 0);
	assert(max == 0);
}

void test_one_number()
{
	double min = 0;
	double max = 0;
	find_minmax({ 1 }, min, max);
	assert(min == 1);
	assert(max == 1);
}

void test_same_numbers()
{
	double min = 0;
	double max = 0;
	find_minmax({ 3, 3, 3 }, min, max);
	assert(min == 3);
	assert(max == 3);
}

void test_multi_numbers()
{
	double min = 0;
	double max = 0;
	find_minmax({ -100, 0, 234 }, min, max);
	assert(min == -100);
	assert(max == 234);
}


int main() 
{
	test_positive();
	test_below_zero();
	test_empty_array();
	test_one_number();
	test_same_numbers();
}