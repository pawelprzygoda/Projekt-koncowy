#include <iostream>
using namespace std;

class Wektor
{
public:
	Wektor()
	{
		cout << "Konstruktor wywolany" << endl;
	}

	virtual ~Wektor()
	{
		cout << "Destruktor wywolany" << endl;
	}

	virtual void print() = 0;
};
