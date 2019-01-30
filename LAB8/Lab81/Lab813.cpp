// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <omp.h>

using namespace std;

//zadania 1 i 3 oddane na lab

/* zad1 */
/*

constexpr int milion = 1000000;
int war = 0;

int main()
{
#pragma omp parallel sections num_threads(2) shared(war)
{
#pragma omp section
{
for (int i = 0; i < milion; ++i)
{
#pragma omp critical
war++;
}
}

#pragma omp section
{
for (int i = 0; i < milion; ++i)
{
#pragma omp critical
war--;
}
}
}

std::cout << war;
}

*/
/* /zad1 */


/* zad3 */
/*
float fkw(float x) {
return x*x;
}
float f(float x)
{
return x;
}

float oblicz_fragm(int w_od, int w_do) {
//dla funkcji x*x
float h1 = fkw((float)w_od);
float h2 = fkw((float)w_do);
float p1 = h1 * 1.0;
float p2 = ((h2 - h1)*1.0) / 2;
float wynik = (float)p1 + p2;
//cout << wynik << endl;
return wynik;
}



int main() {
int rozmiar = 1000000;
float sum = 0;

#pragma omp parallel for reduction(+:sum)
for (int i = 0; i <= rozmiar-1; i++) {
//cout << "i: " << i << endl;
sum += oblicz_fragm(i, i + 1);

}

cout << "wynik: " << sum << endl;
return 0;
}
*/
/* /zad3 */