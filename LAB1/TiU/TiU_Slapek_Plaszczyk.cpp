// grupa: Kamil Słapek zad (obwod koła i pole) i Tomasz Płaszczyk (reszta)
// Bardzo przepraszam że nie marge'owaliśmy poprawnie, przesyłam swoją część (2 ststnie testy - Kamil Słapek)
#define _USE_MATH_DEFINES
#include "stdafx.h"
#include "bib-1.h"
#include <iostream>
#include <cmath>

using namespace std;

bool eqDouble(double q1, double q2) {
	return fabs(q1 - q2) < (double)0.01;
}

bool testPoleKola(double promien, double wynik) {
	double prawidlowy;
	bool blad=0;
	prawidlowy = M_PI * promien * promien;
	if (!eqDouble(prawidlowy, wynik)) blad=1;
	if(promien<0) blad = 1;
	if (wynik<0) blad = 1;
	cout << "test pole kola: \n";
	cout << "promien:" << promien << "\n";
	cout << "prawidlowy:" << prawidlowy << "\n";
	cout << "wynik:" << wynik << "\n";
	cout << "eqd:" << eqDouble(prawidlowy, wynik) << "\n";
	cout << "blad:" << blad << "\n";
	cout << "--- \n";
	return blad;
}

bool testObwodKola(double promien, double wynik) {
	double prawidlowy;
	bool blad = 0;
	prawidlowy = 2*M_PI * promien;
	if (!eqDouble(prawidlowy, wynik)) blad=1;
	if (promien<0) blad = 1;
	if (wynik<0) blad = 1;
	cout << "test obwod kola: \n";
	cout << "promien:" << promien << "\n";
	cout << "prawidlowy:" << prawidlowy << "\n";
	cout << "wynik:" << wynik << "\n";
	cout << "eqd:" << eqDouble(prawidlowy, wynik) << "\n";
	cout << "blad:" << blad << "\n";
	cout << "--- \n";
	return blad;
}

int main(int argc, char * argv[])
{
	
	
	calculator casio;

	double wynik;
	cout << "testy polekola \n";
	wynik = casio.poleKola(2);
	testPoleKola(2, wynik);
	wynik = casio.poleKola(4);
	testPoleKola(4, wynik);
	cout << "zero\n";
	wynik = casio.poleKola(0);
	testPoleKola(0, wynik);
	cout << "minus\n";
	wynik = casio.poleKola(-2);
	testPoleKola(-2, wynik);
	/*
	Blad w poleKola()
	Fukcja zwraca mniejszy wynik tak jakbt r nie było podniesione do kwadratu. Dodac walidacje wartosci ujemnych.
	*/
	cout << "\n testy obwodkola \n";
	wynik = casio.obwodOkregu(2);
	testObwodKola(2, wynik);
	wynik = casio.obwodOkregu(4);
	testObwodKola(4, wynik);
	wynik = casio.obwodOkregu(1);
	 testObwodKola(1, wynik);
	cout << "zero\n";
	wynik = casio.obwodOkregu(0);
	testObwodKola(0, wynik);
	cout << "minus\n";
	wynik = casio.poleKola(-2);
	 testPoleKola(-2, wynik);
	/*
	Blad w funkcji obwodOkregu()
	Funkcja zwraca mniejszy wynik. Prawdopodobnie bledna stala 2pi 5,97 a nie 6,28. Dodac walidacje wartosci ujemnych.
	*/
	return 0;
}

