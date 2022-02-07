#include <iostream>
using namespace std;

class Wektor
{
public:
	Wektor()
	{
		std::cout << "Konstruktor" << std::endl;
	}

	virtual ~Wektor()
	{
		std::cout << "Destruktor" << std::endl;
	}

	virtual void print() = 0;
};
