#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix
{

protected:
    unsigned int height;
    unsigned int width;
    virtual void setHeight(unsigned int height) = 0;
    virtual void setWidth(unsigned int width) = 0;

public:
    virtual unsigned int getHeight() = 0;
    virtual unsigned int getWidth() = 0;
};

#endif
