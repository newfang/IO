// TiU.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include "stdafx.h"
#include "bib-1.h"
#include <math.h>
#include <iostream>

using namespace std;

bool sprTol(double d1, double d2)
{
	if (fabs(d1 - d2) < 0.1)
		return 1;
	else
		return 0;
}

bool polTroj1T(double a, double h, double wynik)
{
	double polTroj1 = a*h;
	return sprTol(polTroj1, wynik);
}

bool polTroj2T(double a, double b, double c, double wynik)
{
	double polTroj2 = (pow((a + b + c)*(a + b - c)*(a - b + c)*(-a + b + c), 0.5))/4;
	return sprTol(polTroj2, wynik);
}

bool obwTroj(double a, double b, double c, double wynik)
{
	double obwTroj = a+b+c;
	return sprTol(obwTroj, wynik);
}

bool poleKola(double r, double wynik)
{
	double PI = M_PI;
	double poleKola = PI*pow(r,2);
	return sprTol(poleKola, wynik);
}

bool obwKola(double r, double wynik)
{
	double PI = M_PI;
	double obwKola = 2*PI*r;
	return sprTol(obwKola, wynik);
}

/*

*/
void testPoleKola()
{
	calculator casio;
	double wynik;
	bool check1 = 1, check2 = 1, check3 = 1, check4 = 1;

	wynik = casio.poleTrojkata(14.5, 12);
	check1 = polTroj1T(14.5, 12, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci dodatnich pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci dodatnich niepomyslny" << endl;

	wynik = casio.poleTrojkata(0, 0);
	check2 = polTroj1T(0, 0, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci zero pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci zero niepomyslny" << endl;

	wynik = casio.poleTrojkata(-5, -5);
	check3 = polTroj1T(0, 0, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci ujemnych pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci ujemnych niepomyslny" << endl;

	wynik = casio.poleTrojkata(14.5, 12, 13);
	check1 = polTroj2T(14.5, 12, 13, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci dodatnich pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci dodatnich niepomyslny" << endl;

	wynik = casio.poleTrojkata(0, 0, 0);
	check2 = polTroj2T(0, 0, 0, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci zero pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci zero niepomyslny" << endl;

	wynik = casio.poleTrojkata(-5, -5, -5);
	check3 = polTroj2T(-5, -5, -5, wynik);
	if (check1)
		cout << "Test Pole Trojkata 1 dla wartosci ujemnych pomyslny" << endl;
	else
		cout << "Test Pole Trojkata 1 dla wartosci ujemnych niepomyslny" << endl;

	wynik = casio.poleKola(14.5);
	check1 = poleKola(14.5, wynik);
	if (check1)
		cout << "Test Pole Kola dla wartosci dodatnich pomyslny" << endl;
	else
		cout << "Test Pole Kola 1 dla wartosci dodatnich niepomyslny" << endl;

	wynik = casio.poleKola(0);
	check2 = poleKola(0, wynik);
	if (check1)
		cout << "Test Pole Kola dla wartosci zero pomyslny" << endl;
	else
		cout << "Test Pole Kola dla wartosci zero niepomyslny" << endl;

	wynik = casio.poleKola(-5);
	check3 = poleKola(-5, wynik);
	if (check1)
		cout << "Test Pole Kola dla wartosci ujemnych pomyslny" << endl;
	else
		cout << "Test Pole Kola dla wartosci ujemnych niepomyslny" << endl;


	if (check1 && check2)
	{
		cout << "Testy przebiegly pomyslnie" << endl;
	}
	else
	{
		cout << "Testy przebiegly niepomyslnie" << endl;
	}
}

int main(int argc, char * argv[])
{
	testPoleKola();
	return 0;
}