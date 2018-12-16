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
		tab[i] = (rand() % 2000)-1000;
	}

	tab[400] = -1200;
	int minVal = tab[0];

#pragma omp parallel for
	for (int i = 0; i < tab_size; i++)
	{
		if (tab[i] < minVal)
		{
			minVal = tab[i];
		}
	}

	cout << "min: " << minVal << endl;
	system("PAUSE");
}