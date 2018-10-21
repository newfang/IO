#include <stdlib.h>
#include <stdio.h>
#include "OptLab.h"
#include <iostream>
bool CompareResults(const BYTE* image1, const BYTE* image2, const int width, const int height)
{
	for (int i = 0; i < width * height; ++i)
		if (abs((int)image1[i] - (int)image2[i]) > 1)
			return false;				
	return true;
}


void Filter(const BYTE *inputImage, BYTE *outputImage, const int width, const int height)
{
	int i, j, k, l;
	double sum;

	for (j = 0; j < height; ++j)
		for (i = 0; i < width; ++i)
			outputImage[GetIndex(i, j, width)] = 0;

	for (i = 0; i < width; ++i)
		for (j = 0; j < height; ++j)
		{
		if (i != 0 && j != 0 && i != width - 1 && j != height - 1)
		{
			sum = 0.0;

			for (k = -1; k <= 1; ++k)
				for (l = -1; l <= 1; ++l)
				{
				if ((k == 0 && l != 0) || (l == 0 && k != 0))
					sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				else if (k == 0 && l == 0)
					sum += 8.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				else
					sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				}

			outputImage[GetIndex(i, j, width)] = (BYTE)sum;
		}
		}
}

// Hardware: Personal Notebook: i7 8th Gen, 8550U
// Start Times: 4.735, 5.187, 5.219.
// Changes commented (better/worse)
// Test #1, Linking loops outputImage: 5.449, 5.371, 5.412.
// Test #2, inline GetIndex: 3.046, 3.198, 3.261.
void Filter_optimized(const BYTE *inputImage, BYTE *outputImage, const int width, const int height)
{
	int i, j, k, l;
	double sum;

	//for (j = 0; j < height; ++j)
	//	for (i = 0; i < width; ++i)
	//		outputImage[GetIndex(i, j, width)] = 0;

	for (i = 0; i < width; ++i)
		for (j = 0; j < height; ++j)
		{
		outputImage[GetIndex(i, j, width)] = 0;
		if (i != 0 && j != 0 && i != width - 1 && j != height - 1)
		{
			sum = 0.0;

			for (k = -1; k <= 1; ++k)
				for (l = -1; l <= 1; ++l)
				{
				if ((k == 0 && l != 0) || (l == 0 && k != 0))
					sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				else if (k == 0 && l == 0)
					sum += 8.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				else
					sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;
				}

			outputImage[GetIndex(i, j, width)] = (BYTE)sum;
		}
		}
}



inline int GetIndex(int x, int y, int w)
{
	return x + y * w;
}

void PrintImage(const BYTE *image, const int N, const int M)
{
	int i, j;

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < M; ++j)
			printf("%d ", image[GetIndex(i, j, M)]);
		printf("\n");
	}
}