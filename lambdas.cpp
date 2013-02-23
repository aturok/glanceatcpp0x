#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

vector<int> createNumbers(int from, int to);

int main(int argc, char** argv)
{
	char * name = argc < 2 ? "stranger" : argv[1];

	cout << "Hello, " << name << "!" << endl;


	auto square = [](double a){return a*a;};

	auto numbers = createNumbers(0,20);

	for_each(
		numbers.begin(),
		numbers.end(),
		[=](int n)
		{
			cout << n << " squared is " << square(n) << endl;
		});

	return 0;
}

vector<int> createNumbers(int from, int to)
{
	vector<int> numbers;
	for(int i = from; i < to; ++i)
	{
		numbers.push_back(i);
	}
	return numbers;
}
