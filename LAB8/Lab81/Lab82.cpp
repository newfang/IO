// Lab81.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <omp.h>
#include <ctime>

using namespace std;

int const thread_size = 4;
int const tab_size = 1000;

int main()
{

	srand(time(NULL));
	int* tab = new int[tab_size];

	for (int i = 0; i < tab_size; i++) {
		tab[i] = (rand() % 2000) - 1000;
	}

	tab[400] = -900;
	int minVal = tab[0];
	int minLocal = minVal;

#pragma omp for nowait
	for (int i = 0; i < tab_size; i++)
	{
		if (tab[i] < minLocal)
		{
			minLocal = tab[i];
		}
	}
#pragma omp critical 
	if (minLocal < minVal) {
		minVal = minLocal;
	}

	cout << "min: " << minVal << endl;
	system("PAUSE");
}
