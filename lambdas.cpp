#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	char * name = argc < 2 ? "stranger" : argv[1];

	cout << "Hello, " << name << "!" << endl;


	auto square = [](double a){return a*a;};

	for(int i = 0; i < 10; ++i)
	{
		cout << i << " squared is " << square(i) << endl;
	}

	cout << "9.5 squared is " << square(9.5) << endl;

	return 0;
}