#ifndef IMAGE_H
#define IMAGE_H
#include <fstream>
#include <cstring>
#include <math.h>
#include "matrix.h"

typedef unsigned char BYTE;

class Image : public Matrix
{
private:
    char* fileName;
    BYTE** pixels;
    int sobelX[3][3] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1},
    };
    int sobelY[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1},
    };
    void setPixels(BYTE* pixels);
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);
    void setPixelValue(unsigned int x, unsigned int y, BYTE value);
    
public:
    BYTE getPixelValue(unsigned int x, unsigned int y);
    unsigned int getHeight();
    unsigned int getWidth();

    void threshold(unsigned int thresholdValue);
    void sobel();

    void setFileName(char* fileName);
    char* getFileName();

    Image operator+ (const Image& image) const;
    Image operator* (const Image& image) const;

    friend ostream& operator<< (char* fileName, const Image& image);
    friend istream& operator>> (char* fileName, Image& image);

    ~Image();
};

#endif