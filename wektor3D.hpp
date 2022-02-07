#include <iostream>
#include <math.h>
#include "wektor.hpp"
using namespace std;


template <typename T = double> 
class wektor3D : public Wektor // dziedziczenie po klasie wektor
{

public:

	
	wektor3D() //konstruktor domyslny
	{
		x = 0;
		y = 0;
		z = 0;
	}
	

	wektor3D(T cord_x, T cord_y, T cord_z) //konstruktor parametryczny
	{
		x = cord_x;
		y = cord_y;
		z = cord_z;
	}

	~wektor3D() {}; //destruktor 


	virtual void print() // wirtualna metoda wypisujaca wsp. wektora
	{
		cout << "wektor = [" << x << "; " << y << "; " << z << "]" << endl;
	}

	
	T dlugosc() // funkcja zwracajaca dlugosc wektora
	{ 
		return sqrt(x * x + y * y + z * z); 
	} 


	//iloczyn skalarny
	template <typename T>
	T operator*(const wektor3D<T>& a)
	{
		T il_skalarny;
		il_skalarny = (a.x * this->x) + (a.y * this->y) + (a.z * this->z);
		return il_skalarny;
	}



	//tworzenie "friend" wektorow aby template spoza ciala klasy mogly korzystac z elementów z Private
	template <typename T>
	friend wektor3D<T> operator+(const wektor3D<T>& a, const wektor3D<T>& b);
	template <typename T>
	friend wektor3D<T> operator-(const wektor3D<T>& a, const wektor3D<T>& b);
	template <typename T>
	friend wektor3D<T> operator%(const wektor3D<T>& a, const wektor3D<T>& b);


protected:
	T x;
	T y;
	T z;
};


//operatory (dwuargemuntowe) 
	//suma
	template <typename T>
	wektor3D<T> operator+(const wektor3D<T>& a, const wektor3D<T>& b)
	{
		wektor3D<T> wektor_wyn;
		wektor_wyn.x = a.x + b.x;
		wektor_wyn.y = a.y + b.y;
		wektor_wyn.z = a.z + b.z;
		cout << "suma wektorow = [ "<< wektor_wyn.x << " ; " << wektor_wyn.y << " ; " << wektor_wyn.z << " ]" << endl;
		return wektor_wyn;
	}

	//roznica
	template <typename T>
	wektor3D<T> operator-(const wektor3D<T>& a, const wektor3D<T>& b)
	{
		wektor3D<T> wektor_wyn;
		wektor_wyn.x = a.x - b.x;
		wektor_wyn.y = a.y - b.y;
		wektor_wyn.z = a.z - b.z;
		cout << "roznica wektorow = [ " << wektor_wyn.x << " ; " << wektor_wyn.y << " ; " << wektor_wyn.z << " ]" << endl;
		return wektor_wyn;
	}

	//iloczyn wektorowy
	template <typename T>
	wektor3D<T> operator%(const wektor3D<T>& a, const wektor3D<T>& b) 
	{
		wektor3D<T> wektor_wyn;
		wektor_wyn.x = a.y * b.z - a.z * b.y;
		wektor_wyn.y = a.z * b.x - a.x * b.z;
		wektor_wyn.z = a.x * b.y - a.y * b.x;
		cout << "iloczyn wektorowy = [ " << wektor_wyn.x << " ; " << wektor_wyn.y << " ; " << wektor_wyn.z << " ]" << endl;
		return wektor_wyn;
	}

