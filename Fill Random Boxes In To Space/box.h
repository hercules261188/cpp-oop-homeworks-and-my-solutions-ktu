#ifndef BOX_H
#define BOX_H
#include "coord.h"
class box{
	private:
		float density,width,height;
		coord bc;
	public:
		void setdensity(float);
		void setwidth(float);
		void setheight(float);
		float getdensity();
		float getwidth();
		float getheight();
		void setxy(float,float);
		float getx();
		float gety();
};

void box::setheight(float a){
	height=a;
}
float box::getheight(){
	return height;
}
void box::setwidth(float a){
	width=a;
}
float box::getwidth(){
	return width;
}
void box::setdensity(float a){
	density=a;
}
float box::getdensity(){
	return density;
}
void box::setxy(float a,float b){
	bc.setxy(a,b);
}
float box::getx(){
	return bc.getx();
}
float box::gety(){
	return bc.gety();
}


#endif
