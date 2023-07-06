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
#include "histogram.h"
#include "SVGISTOHELPER.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<char, string> pcs;

//=====================================
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

	show_histogram_svg(bins);
}