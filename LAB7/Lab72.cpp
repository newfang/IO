// Lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mutex>
#include <thread>
#include <ctime>

using namespace std;
/*
int const thread_size = 4;
int const tab_size = 1000;
int thread_part = tab_size / thread_size;
int minVal;
thread myThread[thread_size];
mutex mtx;

void tabSearch(int* tab, int start, int end) {
	mtx.lock();
	for (int i = start; i < end; i++)
	{
		if (tab[i] < minVal)
		{
			minVal = tab[i];
			mtx.unlock();
		}
	}
}

int mainold()
{
	srand(time(NULL));
	int* tabA = new int[tab_size];

	for (int i = 0; i < tab_size; i++) {
		tabA[i] = rand() % tab_size;
	}

	tabA[500] = -200;
	minVal = tabA[0];

	for (int i = 0; i < thread_part; i++) {
		myThread[i] = thread(tabSearch, tabA, i * thread_part, (i + 1) * thread_part);
		myThread[i].join();
	}

	for (int i = 0; i < thread_part; i++) {
		myThread[i].join();
	}

	cout << "Min: " << minVal << endl;

	delete[] tabA;
	return 1;
}
*/