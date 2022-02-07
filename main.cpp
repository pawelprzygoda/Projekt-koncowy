#include <iostream>
#include "wektor3D.hpp"

using namespace std;

int main()
{
	wektor3D<> a(1, 1, 1);
	wektor3D<> b(1, 1, 1);


	a.print();
	b.print();

	//cout << a.dlugosc() << endl;
	//cout << (a * b) << endl;

	a - b;
	//a + b;
	//a % b;
	
	//operator/(a, b);

	return 0;
}
