#include "OptLab.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;
#define N 200
#define M 100

int main(int argc, char **argv)
{
	BYTE *inputImage = new BYTE[M*N];
	for (int i = 0, k = 0; i < N * M; ++i)
		inputImage[i] = k++ % 255;
	
	BYTE *outputImage = new BYTE[M*N];
	BYTE *outputPattern = new BYTE[M*N];
	
	Filter(inputImage, outputPattern, N, M);
	Filter_optimized(inputImage, outputImage, N, M);
	if (CompareResults(outputPattern, outputImage, N, M))
	{
		cout << "Comparision test OK!\n";
	}
	else
	{
		cout << "Comparision test failed!!!";
		exit(1);
	}

	cout << "Starting performance test...\n";
	clock_t startTime, endTime;


	startTime = clock();
	for (int i = 0; i < 10000; ++i)
		Filter_optimized(inputImage, outputImage, N, M);
	endTime = clock();

	cout << "Execution time = " << ((float)(endTime - startTime) / CLOCKS_PER_SEC) << " s";
		
	

	delete[] inputImage;
	delete[]outputImage;
	delete[]outputPattern;
	
	return 0;
}