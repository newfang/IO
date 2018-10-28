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

/*
Testów dokonano na dwóch maszynach: laptopie i maszynie wirtualnej. Specyfikacje i wyniki podano poni¿ej.

#1 Laptop
Hardware: Personal Notebook: i7 8th Gen, 8550U
 Start Times: 4.735, 5.187, 5.219.
 Changes commented (better/worse)
 Test 1. Linking loops outputImage: 5.449, 5.371, 5.412.
 Test 2. inline GetIndex: 3.046, 3.198, 3.261.
 Test 3. Loop reorganizing: 2.735, 2.842, 2.804.

#2 Maszyna wirtualna
Czas wykonania na maszynie wirtualnej okaza³ siê bardzo zmienny wiêc opisujemy pomys³y na optymalizacjê - nie mam jak ich zweryfikowaæ.
Punkt 6 najwa¿niejszy!!!
 
Test 5. Po³¹czenie pêtli  przeniesienie zawartoœci outputImage[GetIndex(i, j, width)] = 0; do podwójnej pêtli poni¿ej - wolniej o ok 2s.
Test 6. Dodanie inline do GetIndex przyœpieszenie ok 0,5s
Test 7. Zamiana GetIndex  na dzia³anie "na sztywno" np. w 63l. na outputImage[i + j*width] = 0; 
        //przy testach by³y wachania o 3 sek, ale po zmianie wydawa³y siê wolniejsze
Test 8. Usuniêcie if (i != 0 && j != 0 && i != width - 1 && j != height - 1)
        i zmiana zewnêtrznych pêtli na
        for (i = 1; i < width-1; ++i)
        for (j = 1; j < height-1; ++j)
        spowolni³a z ~17 do 19,8s, ale po przywróceniu zmian 18,39-21,2s (bardzo du¿e wachania), tak¿e byæ mo¿e to zoptymalizowa³o
 
Test 9. Obliczenie wartoœci do zmiennej buf i wklejenie jej w warunek (mneij obliczeñ)
buf = inputImage[GetIndex(i + l, j + k, width)] / 28.0;
 
if ((k == 0 && l != 0) || (l == 0 && k != 0))
sum += 4.0 * buf;
else if (k == 0 && l == 0)
sum += 8.0 * buf;
else
sum += buf;
 
Test 10. Pêtle wykonuj¹ tylko po 3 iteracje, lepiej by by³o z³amaæ zasadê DRY i wklejiæ ten sam kod po 3x czyli dla 9przypadków
        for (k = -1; k <= 1; ++k)
                for (l = -1; l <= 1; ++l) 
 
        przypadki:
                k = -1;l = -1;
                k = -1;l = 0;
                k = -1;l = 1;
 
                k = 0;l = -1;
                k = 0;l = 0;
                k = 0;l = 1;
 
                k = 1;l = -1;
                k = 1;l = 0;
                k = 1;l = 1;
 
                teraz mo¿na zrezygnowaæ z konstrukcji if-elseif-else i poprostu wkleiæ fragment kodu pod przypadkami gdy jest spe³niony.
                tj:
 
                k = -1;l = -1;
                        sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;                //else
                k = -1;l = 0;
                sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
                k = -1;l = 1;
                        sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;                //else
 
                k = 0;l = -1;
                sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
                k = 0;l = 0;
                sum += 8.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;          //else if
                k = 0;l = 1;
                sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
 
                k = 1;l = -1;
                        sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;                //else
                k = 1;l = 0;
                sum += 4.0 * inputImage[GetIndex(i + l, j + k, width)] / 28.0;
                k = 1;l = 1;
                        sum += inputImage[GetIndex(i + l, j + k, width)] / 28.0;                //else
 Test 11. W pêtlach wystêpuje preinkrementacja wiêc przypadki z -1 odpadaj¹.
*/
void Filter_optimized(const BYTE *inputImage, BYTE *outputImage, const int width, const int height)
{
	int i, j, k, l;
	double sum;

	for (j = 0; j < height; ++j) //Test #3
		for (i = 0; i < width; ++i) //Test #3
			outputImage[GetIndex(i, j, width)] = 0; //Test #3

	for (i = 1; i < width - 1; ++i) //Test #3
		for (j = 1; j < height - 1; ++j) //Test #3
		{
		outputImage[GetIndex(i, j, width)] = 0; //Test #1
		//if (i != 0 && j != 0 && i != width - 1 && j != height - 1)  //Test #3
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