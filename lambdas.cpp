#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::setw;
using std::function;

vector<double> createNumbers(double from, double to, double step);
function<double (double)> getPowerer(int power);

void printNumbersWithPowers(vector<double> numbers, int power);

int main(int argc, char** argv)
{
	int power = 2;
	double from = 0.0;
	double to = 10.0;
	double step = 1.0;
	
	if(argc > 1)
	{
		power = atoi(argv[1]);
	}

	if(argc > 2)
	{
		from = strtod(argv[2],NULL);
	}

	if(argc > 3)
	{
		to = strtod(argv[3],NULL);
	}

	if(argc > 4)
	{
		step = strtod(argv[4],NULL);
	}

	auto numbers = createNumbers(from,to,step);

	cout << "For ["<< from << ", " << to << "). (Step is " << step << ")." << endl;
	printNumbersWithPowers(numbers,power);
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

function<double (double)> getPowerer(int power)
{
	return [power](double a){return pow(a,power);};
}

void printNumbersWithPowers(vector<double> numbers, int power)
{
	const int outFieldW = 8;
	
	auto powered = getPowerer(power);

	double powerSum = 0.0;

	cout << std::setiosflags(std::ios::left) << setw(outFieldW) << "x" << "x^" << power << endl;
	for_each(
		numbers.begin(),
		numbers.end(),
		[&](double n)
		{
			double pwd = powered(n);
			cout << setw(outFieldW) << n << setw(outFieldW) << pwd << endl;
			powerSum += pwd;
		});

	cout << endl << "Sum is " << powerSum << endl;
}