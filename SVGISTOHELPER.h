#pragma once
#include <string>
#include <vector>
using namespace std;

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, double fill_opacity = 1, string stroke = "black", string fill = "green");

void show_histogram_svg(const vector<size_t>& bins);