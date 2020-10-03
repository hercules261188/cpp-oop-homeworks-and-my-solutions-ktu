#ifndef SPACE_H
#define SPACE_H
#include "box.h"

using namespace std;

class space{
	private:
		int spacew,spaceh,boxdensity,boxnum;
		box *boxes;
	public:
		space(int,int);
		void fillrandombox(int,int,int);
		void fillrandombox(int,int,int,int);
		int centerofmass();
		void printBoxCoordinates();
		int getspacew(){
			return spacew;
		}
		int getspaceh(){
			return spaceh;
		}
		void setspacew(int w1){
			spacew=w1;
		}
		void setspaceh(int h1){
			spaceh=h1;
		}
		void setboxnum(int bn){
			boxnum=bn;
		}
		void printspace(int**);
};

space::space(int w1,int h1){
	spaceh=h1;
	spacew=w1;
	cout<<endl<<endl<<setw(43)<<"Your Space"<<endl;
	for(int i = -1; i < spaceh + 1; i++){
		for(int j = -1; j < spacew + 1; j++){
			if(i == -1 || i == spaceh){
				if(j==-1){
					cout<<setw(39-spacew/2-1)<<'-';
				}
				else
				cout<<'-';
			}
			else{
				if(j == -1){
					cout<<setw(39-spacew/2-1)<<'|';
				}
				else if(j == spacew){
					cout<<'|';
				}
				else{
					cout<<' ';
				}
			}	
		}
		cout<<endl;
	}
}

void space::fillrandombox(int a, int b, int c){
	bool error = false;
	setboxnum(a);
	boxes = new box[a];
	srand(time(NULL));
	int **spacedizi=new int*[spaceh];
	for(int i=0;i<spaceh;i++){
		spacedizi[i]=new int[spacew];
		for(int j=0;j<spacew;j++){
			spacedizi[i][j]=1;
		}
	}
	for(int i = 0; i < a; i++){
		int iterations=0;
		int bh = rand() % b + 1;
		int bw = rand() % b + 1;
etiket3:float xx = float(rand() % spacew);
		float yy = float(rand() % spaceh);
		if(xx + bw > spacew || yy + bh > spaceh)goto etiket3;
		for(int j = yy;j < yy + bh; j++){
			for(int k = xx; k < xx + bw; k++){
				if(spacedizi[j][k] == -1){
					error = true;
				}
			}
		}
		if(error){
			error=false;
			iterations++;
				if(iterations == 100){
					if(i > 2 && i < 20){
						cout<<" "<<i+1<<"th box wasn't placed..."<<endl;
					}
					else{
						if(i % 10 == 0){
							cout<<" "<<i+1<<"st box wasn't placed..."<<endl;
						}
						else if(i % 10 == 1){
							cout<<" "<<i+1<<"nd box wasn't placed..."<<endl;
						}
						else if(i % 10 == 2){
							cout<<" "<<i+1<<"rd box wasn't placed..."<<endl;
						}
						else{
							cout<<" "<<i+1<<"th box wasn't placed..."<<endl;
						}
					}
					boxes[i].setxy(0,0);
					boxes[i].setheight(bh);
					boxes[i].setwidth(bw);
					boxes[i].setdensity(-1);
					continue;
				}
				else{
					goto etiket3;	
				}
		}
		else{
			for(int j = yy; j < yy + bh; j++){
				for(int k = xx; k < xx + bw; k++){
					spacedizi[j][k] = -1;
				}
			}
		}
		boxes[i].setxy(xx,yy);
		boxes[i].setheight(bh);
		boxes[i].setwidth(bw);
		boxes[i].setdensity(c);
	}
	printspace(spacedizi);	
}

void space::fillrandombox(int a,int b,int c,int k){
	bool error=false;
	setboxnum(a);
	boxes=new box[a];
	srand(time(NULL));
	int **spacedizi=new int*[spaceh];
	for(int i=0;i<spaceh;i++){
		spacedizi[i]=new int[spacew];
		for(int j=0;j<spacew;j++){
			spacedizi[i][j]=1;
		}
	}
	for(int i=0; i < a; i++){
		int iterations = 0;
		int bh = rand() % b + 1;
		int bw = rand() % b + 1;
		int bd = rand()% c + 1;
etiket3:float xx=float(rand()%spacew);
		float yy=float(rand()%spaceh);
		if(xx + bw > spacew || yy + bh > spaceh)goto etiket3;
		for(int j = yy; j < yy + bh; j++){
			for(int k = xx; k < xx + bw; k++){
				if(spacedizi[j][k] == -1){
					error=true;
				}
			}
		}
		if(error){
			error=false;
			iterations++;
				if(iterations == 100){
					if(i > 2 && i < 20){
						cout<<" "<<i+1<<"th box wasn't placed..."<<endl;
					}
					else{
						if(i % 10 == 0){
							cout<<" "<<i+1<<"st box wasn't placed..."<<endl;
						}
						else if(i % 10 == 1){
							cout<<" "<<i+1<<"nd box wasn't placed..."<<endl;
						}
						else if(i % 10 == 2){
							cout<<" "<<i+1<<"rd box wasn't placed..."<<endl;
						}
						else{
							cout<<" "<<i+1<<"th box wasn't placed..."<<endl;
						}
					}
					boxes[i].setxy(0,0);
					boxes[i].setheight(bh);
					boxes[i].setwidth(bw);
					boxes[i].setdensity(-1);
					continue;
				}
				else{
					goto etiket3;	
				}
		}
		else{
			for(int j=yy;j<yy+bh;j++){
				for(int k=xx;k<xx+bw;k++){
					spacedizi[j][k]=-1;
				}
			}
		}
		boxes[i].setxy(xx,yy);
		boxes[i].setheight(bh);
		boxes[i].setwidth(bw);
		boxes[i].setdensity(bd);
	}
	printspace(spacedizi);
}

int space::centerofmass(){
	float topx=0 , topy=0;
	int   topm=0;
	for(int i=0 ; i<boxnum ; i++){
		if(boxes[i].getdensity()!=-1){
			topx += ( boxes[i].getx() + (boxes[i].getwidth()  / 2 )) * ( boxes[i].getdensity() * boxes[i].getheight() * boxes[i].getwidth() );
			topy += ( boxes[i].gety() + (boxes[i].getheight() / 2 )) * ( boxes[i].getdensity() * boxes[i].getheight() * boxes[i].getwidth() );
			topm +=   boxes[i].getdensity() * boxes[i].getheight() * boxes[i].getwidth();
			}
		}
	topx /= topm;
	topy /= topm;
	cout<<endl<<" Center of Mass--> X: "<<topx<<"\tY: "<<topy<<endl;
}

void space::printspace(int **spacedizi){
	cout<<endl<<endl<<setw(43)<<"Your Space"<<endl;
	for(int i = -1; i < spaceh + 1; i++){
		for(int j = -1; j < spacew + 1; j++){
			if(i == -1 || i == spaceh){
				if(j==-1){
					cout<<setw(39-spacew/2-1)<<'-';
				}
				else
				cout<<'-';
			}
			else{
				if(j == -1){
					cout<<setw(39-spacew/2-1)<<'|';
				}
				else if(j == spacew){
					cout<<'|';
				}
				else{
					if(spacedizi[i][j] == -1){
						cout<<'X';
					}
					else
					cout<<' ';
				}
				
			}	
		}
		cout<<endl;
	}
}

void space::printBoxCoordinates(){
	for(int i=0;i<boxnum;i++){
		if(boxes[i].getdensity()!=-1)
		if(i > 2 && i < 20){
			if(i < 9){
				cout<<"  "<<i+1<<"th Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
			}
			else{
				cout<<" "<<i+1<<"th Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
			}
		}
		else{
			if(i % 10 == 0){
				if(i < 9){
					cout<<"  "<<i+1<<"st Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"st Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
			}
			else if(i % 10 == 1){
				if(i < 9){
					cout<<"  "<<i+1<<"nd Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"nd Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
			}
			else if(i % 10 == 2){
				if(i < 9){
					cout<<"  "<<i+1<<"rd Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"rd Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
				}
			}
			else{
				cout<<" "<<i+1<<"th Box X: "<<boxes[i].getx()<<setw(5)<<"Y: "<<boxes[i].gety()<<setw(9)<<"Width: "<<boxes[i].getwidth()<<" Height: "<<boxes[i].getheight()<<" Density: "<<boxes[i].getdensity()<<setw(13)<<"New ->> X: "<<boxes[i].getx()+boxes[i].getwidth()<<setw(5)<<"Y: "<<boxes[i].gety()+boxes[i].getheight()<<endl;
			}
		}	
	}
}

#endif
