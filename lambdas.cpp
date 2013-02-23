#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;

vector<double> createNumbers(double from, double to, double step);

int main(int argc, char** argv)
{
	double from = 0.0;
	double to = 10.0;
	double step = 1.0;
	
	if(argc > 1)
	{
		from = strtod(argv[1],NULL);
	}

	if(argc > 2)
	{
		to = strtod(argv[2],NULL);
	}

	if(argc > 3)
	{
		step = strtod(argv[3],NULL);
	}

	auto square = [](double a){return a*a;};
	auto numbers = createNumbers(from,to,step);

	cout << "Squares for ["<< from << ", " << to << "). (Step is " << step << ")." << endl;
	for_each(
		numbers.begin(),
		numbers.end(),
		[=](double n)
		{
			cout << n << " squared is " << square(n) << endl;
		});

	return 0;
}

vector<double> createNumbers(double from, double to, double step)
{
	vector<double> numbers;

	if((to-from)*step <= 0.0)
		return numbers;

	for(double i = from; abs(i) < abs(to); i += step)
	{
		numbers.push_back(i);
	}
	return numbers;
}
