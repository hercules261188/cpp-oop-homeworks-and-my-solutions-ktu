#ifndef BOX_H
#define BOX_H
#include "coord.h"

class Box{
	private:
		float density, width, height;
		Coord boxCoordinate;
	public:
		void setDensity(float);
		void setWidth(float);
		void setHeight(float);
		float getDensity();
		float getWidth();
		float getHeight();
		void setXY(float,float);
		float getX();
		float getY();
};

#endif
