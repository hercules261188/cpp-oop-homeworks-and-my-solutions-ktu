#ifndef COORD_H
#define COORD_H
class coord{
	private:
		float x,y;
	public:
		void setxy(float a,float b){
			x=a;
			y=b;
		}
		float getx(){
			return x;
		}
		float gety(){
			return y;
		}
};

#endif
