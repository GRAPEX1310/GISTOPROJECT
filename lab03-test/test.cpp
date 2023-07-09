#include "histogram.h"
#include "SVGISTOHELP.h"
#include <cassert>

//Tests for find_minmax()
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

//Tests for svg_rect()

void test_rect_full_opacity()
{
	const auto IMAGE_WIDTH = 400;
	const auto IMAGE_HEIGHT = 300;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;
	const auto SCREEN_WIDTH = 80;
	const auto MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
	const double fill_opacity = 1;

	svg_rect(TEXT_WIDTH, 0, BLOCK_WIDTH * 100, BIN_HEIGHT, fill_opacity);
	assert(fill_opacity == 1);
}

void test_rect_zero_opacity()
{
	const auto IMAGE_WIDTH = 400;
	const auto IMAGE_HEIGHT = 300;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;
	const auto SCREEN_WIDTH = 80;
	const auto MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
	const double fill_opacity = 0;
	
	svg_rect(TEXT_WIDTH, 0, BLOCK_WIDTH * 100, BIN_HEIGHT, fill_opacity);
	assert(fill_opacity == 0);
}

void test_rect_default_opacity()
{
	const auto IMAGE_WIDTH = 400;
	const auto IMAGE_HEIGHT = 300;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;
	const auto SCREEN_WIDTH = 80;
	const auto MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
	
	svg_rect(TEXT_WIDTH, 0, BLOCK_WIDTH * 100, BIN_HEIGHT);
	assert(fill_opacity == 0);
}

int main() 
{
	//Tests for find_minmax()
	test_positive();
	test_below_zero();
	test_empty_array();
	test_one_number();
	test_same_numbers();
	test_multi_numbers();

	//Tests for svg_rect()
	test_rect_full_opacity();
	test_rect_zero_opacity();
	test_rect_default_opacity();
}