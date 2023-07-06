#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<char, string> pcs;
//=====================================
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
	min = numbers[0];
	max = numbers[0];

	for (double x : numbers)
	{
		if (x < min)
		{
			min = x;
		}

		else if (x > max)
		{
			max = x;
		}
	}
}

vector<double> input_numbers(size_t count) 
{
	vector<double> result(count);
	for (size_t i = 0; i < count; i++) 
	{
		cin >> result[i];
	}
	return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

	vector<size_t> bins(bin_count);

	double min, max;
	find_minmax(numbers, min, max);

	size_t number_count = numbers.size();

	double bin_size = (max - min) / bin_count;

	for (size_t i = 0; i < number_count; i++)
	{
		bool found = false;

		for (size_t j = 0; (j < bin_count - 1) && !found; j++)
		{
			auto lo = min + j * bin_size;
			auto hi = min + (j + 1) * bin_size;

			if ((lo <= numbers[i]) && (numbers[i] < hi))
			{
				bins[j]++;
				found = true;
			}
		}

		if (!found)
		{
			bins[bin_count - 1]++;
		}
	}

	size_t max_count = 0;

	for (size_t i = 0; i < bin_count; i++)
	{
		if (bins[i] > max_count) max_count = bins[i];
	}

	for (size_t i = 0; i < bin_count; i++)
	{
		size_t height;

		if (max_count > MAX_ASTERISK)
		{
			height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
		}

		else
		{
			height = bins[i];
		}

		bins[i] = height;
	}

	return bins;
}

void show_histogram_text(const vector<size_t>& bins)
{

	const size_t bin_count = bins.size();

	for (size_t i = 0; i < bin_count; i++)
	{
		if (bins[i] < 100)
		{
			cout << ' ';
			if (bins[i] < 10) cout << ' ';
		}

		cout << bins[i] << '|';

		for (size_t j = 0; j < bins[i]; j++)
		{
			cout << '*';
		}

		cout << '\n';
	}
}
//=====================================

void svg_begin(double width, double height) 
{
	cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
	cout << "<svg ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "viewBox='0 0 " << width << " " << height << "' ";
	cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() 
{
	cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) 
{
	cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black")
{
	cout << "<rect x='" << x << "' y='" << y
		<< "' width='" << width << "' height='" << height 
		<< "' stroke='" << stroke << "' fill='" << fill << "'/>";
}

void show_histogram_svg(const vector<size_t>& bins) 
{
	const auto IMAGE_WIDTH = 400;
	const auto IMAGE_HEIGHT = 300;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;
	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
	double top = 0;
	for (size_t bin : bins) 
	{
		string bin_num = to_string(bin);

		if (bin < 100)
		{
			bin_num = " " + bin_num;
			if (bin < 10) bin_num = " " + bin_num;
		}

		const double bin_width = BLOCK_WIDTH * bin;
		svg_text(TEXT_LEFT, top + TEXT_BASELINE, bin_num);
		svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "green");
		top += BIN_HEIGHT;
	}
	svg_end();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);

	size_t number_count;
	cin >> number_count;

	const auto numbers = input_numbers(number_count);

	size_t bin_count;
	cin >> bin_count;

	const auto bins = make_histogram(numbers, bin_count);

	//show_histogram_text(bins);
	show_histogram_svg(bins);
}