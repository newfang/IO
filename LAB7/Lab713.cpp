/*
zad.1

*/

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <condition_variable>
using namespace std;


condition_variable CV;
bool enable = false;
mutex m;
long int wart = 0;


void zwieksz() {
	for (long int i = 0; i < 8000000; i++) {
		m.lock();
		wart++;
		m.unlock();
	}

}

void zmniejsz() {
	for (long int i = 0; i < 8000000; i++) {
		m.lock();
		wart--;
		m.unlock();
	}
}



int main()
{
	thread inkThread(zwieksz);
	thread dekThread(zmniejsz);

	inkThread.join();
	dekThread.join();
	cout << wart;

	return 0;
}

//bez synchronizacji liczba wacha siÄ o nawet ~2mln



/*
zad. 3
Koncepcja juĹź jest dobra, ale zabrakĹo czasu na warunki itp.

*/
float tablica[8];

void oblicz_fragm(int w_od, int w_do) {

	//dla funkcji x*x
	//obliczanie pola kwadratu i trojkata. dlogosci odcinkow zawsze = 1
	for () { // ilosc wykonan dla kazdego pola z paczki - czyli w tym przypadku 50 przebiegow
		float local_sum = 0;

		float h1 = w_od * w_od;
		float h2 = w_do * w_do;
		float h3 = h2 - h1;
		float p1 = h1 * 1;
		float p2 = (h3 * 1) / 2;

		float p = p1 + p2;
		local_sum += p;
	}
	//zapisz wynik lokalnego pola do globalnej tablicy
	tablica[(w_do + 1) / c] = local_sum;
}

int main() {

	int watki = 4;
	int rozmiar = 200;
	int c = rozmiar / watki;
	int w_od = 0;
	int w_do = 0;
	float sum;

	//dzielenie tablicy na paczki
	for (int i = 1; i <= watki; i++) {
		w_od = c * (i - 1);
		w_od = (c * i) - 1;

		thread oblicz(oblicz_fragm, w_od, w_do);

	}

	//pÄtla joinujÄ	ca
		for () {
			oblicz.join();
		}

	//dodaj wartosci z globalnej tablicy
	for () {
		sum = sum + tablica[i];
	}

}