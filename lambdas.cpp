#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	char * name = argc < 2 ? "stranger" : argv[1];

	cout << "Hello, " << name << "!" << endl;

	return 0;
}