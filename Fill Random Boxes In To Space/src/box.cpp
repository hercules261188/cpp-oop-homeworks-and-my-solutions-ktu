#include "box.h"

void Box::setHeight(float height){
	this->height = height;
}
float Box::getHeight(){
	return this->height;
}
void Box::setWidth(float width){
	this->width = width;
}
float Box::getWidth(){
	return this->width;
}
void Box::setDensity(float density){
	this->density = density;
}
float Box::getDensity(){
	return this->density;
}
void Box::setXY(float x,float y){
	this->boxCoordinate.setXY(x, y);
}
float Box::getX(){
	return this->boxCoordinate.getX();
}
float Box::getY(){
	return this->boxCoordinate.getX();
}