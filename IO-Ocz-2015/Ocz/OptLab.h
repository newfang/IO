#ifndef _OPTLAB_H_
#define _OPTLAB_H_
typedef unsigned char BYTE;

void Filter(const BYTE *inputImage, BYTE *outputImage, const int N, const int M);
void Filter_optimized(const BYTE *inputImage, BYTE *outputImage, const int width, const int height);
int GetIndex(int x, int y, int w);
void PrintImage(const BYTE *image, const int N, const int M);
bool CompareResults(const BYTE* image1, const BYTE* image2, const int width, const int height);
#endif