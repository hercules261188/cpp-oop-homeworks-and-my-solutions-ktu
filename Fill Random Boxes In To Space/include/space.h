#ifndef SPACE_H
#define SPACE_H
#include <iostream>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>

#include "box.h"

using namespace std;

class Space{
	private:
		int spaceWidth, spaceHeight, boxDensity, boxCount;
		Box *boxes;
	public:
		Space(int spaceWidth, int spaceHeight);
		void fillRandomBox(int boxCount, int boxMaxWidthHeight, int density);
		void fillRandomBox(int, int, int, int);
		void centerOfMass();
		void printBoxCoordinates();
		int getSpaceWidth(){
			return this->spaceWidth;
		}
		int getSpaceHeight(){
			return this->spaceHeight;
		}
		void setSpaceWidth(int spaceWidth){
			this->spaceWidth = spaceWidth;
		}
		void setSpaceHeight(int spaceHeight){
			this->spaceHeight = spaceHeight;
		}
		void setBoxCount(int boxCount){
			this->boxCount = boxCount;
		}
		void printSpace(int** space);
};

#endif
