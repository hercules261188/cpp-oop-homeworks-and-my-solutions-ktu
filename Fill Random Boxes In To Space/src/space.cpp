#include "space.h"

Space::Space(int spaceWidth, int spaceHeight){
	this->spaceHeight = spaceHeight;
	this->spaceWidth = spaceWidth;
	cout << endl << endl << setw(43) << "Your Space" << endl;
	for(int i = -1; i < this->spaceHeight + 1; i++){
		for(int j = -1; j < this->spaceWidth + 1; j++){
			if(i == -1 || i == this->spaceHeight){
				if(j==-1){
					cout << setw(39 - this->spaceWidth / 2 - 1) << '-';
				}
				else
				cout<<'-';
			}
			else{
				if(j == -1){
					cout << setw(39 - this->spaceWidth / 2 - 1) << '|';
				}
				else if(j == this->spaceWidth){
					cout << '|';
				}
				else{
					cout << ' ';
				}
			}	
		}
		cout<<endl;
	}
}

void Space::fillRandomBox(int boxCount, int boxMaxWidthHeight, int density){
	bool error = false;
	this->setBoxCount(boxCount);
	this->boxes = new Box[boxCount];
	srand(time(NULL));
	int **space = new int*[this->spaceHeight];
	for(int i = 0;i < this->spaceHeight; i++){
		space[i] = new int[this->spaceWidth];
		for(int j = 0; j < this->spaceWidth; j++){
			space[i][j] = 1;
		}
	}
	for(int i = 0; i < boxCount; i++){
		int iterations = 0;
		int boxHeight = rand() % boxMaxWidthHeight + 1;
		int boxWidth = rand() % boxMaxWidthHeight + 1;
label3:float spaceX = float(rand() % this->spaceWidth);
		float spaceY = float(rand() % this->spaceHeight);
		if(spaceX + boxWidth > this->spaceWidth || spaceY + boxHeight > this->spaceHeight)goto label3;
		for(int j = spaceY;j < spaceY + boxHeight; j++){
			for(int k = spaceX; k < spaceX + boxWidth; k++){
				if(space[j][k] == -1){
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
					this->boxes[i].setXY(0, 0);
					this->boxes[i].setHeight(boxHeight);
					this->boxes[i].setWidth(boxWidth);
					this->boxes[i].setDensity(-1);
					continue;
				}
				else{
					goto label3;	
				}
		}
		else{
			for(int j = spaceY; j < spaceY + boxHeight; j++){
				for(int k = spaceX; k < spaceX + boxWidth; k++){
					space[j][k] = -1;
				}
			}
		}
		this->boxes[i].setXY(spaceX, spaceY);
		this->boxes[i].setHeight(boxHeight);
		this->boxes[i].setWidth(boxWidth);
		this->boxes[i].setDensity(density);
	}
	this->printSpace(space);	
}

void Space::fillRandomBox(int boxCount, int boxMaxWidthHeight, int density, int k){
	bool error = false;
	this->setBoxCount(boxCount);
	this->boxes = new Box[boxCount];
	srand(time(NULL));
	int **space = new int*[this->spaceHeight];
	for(int i = 0; i < this->spaceHeight; i++){
		space[i]=new int[this->spaceWidth];
		for(int j = 0; j < this->spaceWidth; j++){
			space[i][j] = 1;
		}
	}
	for(int i=0; i < boxCount; i++){
		int iterations = 0;
		int boxHeight = rand() % boxMaxWidthHeight + 1;
		int boxWidth = rand() % boxMaxWidthHeight + 1;
		int boxDensity = rand() % density + 1;
label3:float spaceX = float(rand() % this->spaceWidth);
		float spaceY = float(rand() % this->spaceHeight);
		if(spaceX + boxWidth > this->spaceWidth || spaceY + boxHeight > this->spaceHeight)goto label3;
		for(int j = spaceY; j < spaceY + boxHeight; j++){
			for(int k = spaceX; k < spaceX + boxWidth; k++){
				if(space[j][k] == -1){
					error = true;
				}
			}
		}
		if(error){
			error = false;
			iterations++;
				if(iterations == 100){
					if(i > 2 && i < 20){
						cout<<" "<< i + 1 <<"th box wasn't placed..."<<endl;
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
					this->boxes[i].setXY(0, 0);
					this->boxes[i].setHeight(boxHeight);
					this->boxes[i].setWidth(boxWidth);
					this->boxes[i].setDensity(-1);
					continue;
				}
				else{
					goto label3;	
				}
		}
		else{
			for(int j = spaceY; j < spaceY + boxHeight; j++){
				for(int k = spaceX; k < spaceX + boxWidth; k++){
					space[j][k]=-1;
				}
			}
		}
		this->boxes[i].setXY(spaceX, spaceY);
		this->boxes[i].setHeight(boxHeight);
		this->boxes[i].setWidth(boxWidth);
		this->boxes[i].setDensity(boxDensity);
	}
	this->printSpace(space);
}

void Space::centerOfMass(){
	float sumX = 0 , sumY = 0;
	int   sumM = 0;
	for(int i = 0 ; i< this->boxCount; i++){
		if(boxes[i].getDensity() != -1){
			sumX += ( boxes[i].getX() + (boxes[i].getWidth()  / 2 )) * ( boxes[i].getDensity() * boxes[i].getHeight() * boxes[i].getWidth() );
			sumY += ( boxes[i].getY() + (boxes[i].getHeight() / 2 )) * ( boxes[i].getDensity() * boxes[i].getHeight() * boxes[i].getWidth() );
			sumM +=   boxes[i].getDensity() * boxes[i].getHeight() * boxes[i].getWidth();
			}
		}
	sumX /= sumM;
	sumY /= sumM;
	cout<<endl<<" Center of Mass--> X: "<<sumX<<"\tY: "<<sumY<<endl;
}

void Space::printSpace(int **space){
	cout << endl << endl << setw(43) << "Your Space" << endl;
	for(int i = -1; i < this->spaceHeight + 1; i++){
		for(int j = -1; j < this->spaceWidth + 1; j++){
			if(i == -1 || i == this->spaceHeight){
				if(j == -1){
					cout << setw(39 - this->spaceWidth / 2 - 1) << '-';
				}
				else
				cout << '-';
			}
			else{
				if(j == -1){
					cout << setw(39 - this->spaceWidth / 2 - 1) << '|';
				}
				else if(j == this->spaceWidth){
					cout<<'|';
				}
				else{
					if(space[i][j] == -1){
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

void Space::printBoxCoordinates(){
	for(int i = 0;i < this->boxCount; i++){
		if(boxes[i].getDensity() != -1)
		if(i > 2 && i < 20){
			if(i < 9){
				cout<<"  "<<i+1<<"th Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
			}
			else{
				cout<<" "<<i+1<<"th Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
			}
		}
		else{
			if(i % 10 == 0){
				if(i < 9){
					cout<<"  "<<i+1<<"st Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"st Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
			}
			else if(i % 10 == 1){
				if(i < 9){
					cout<<"  "<<i+1<<"nd Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"nd Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
			}
			else if(i % 10 == 2){
				if(i < 9){
					cout<<"  "<<i+1<<"rd Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
				else{
					cout<<" "<<i+1<<"rd Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
				}
			}
			else{
				cout<<" "<<i+1<<"th Box X: "<<boxes[i].getX()<<setw(5)<<"Y: "<<boxes[i].getY()<<setw(9)<<"Width: "<<boxes[i].getWidth()<<" Height: "<<boxes[i].getHeight()<<" Density: "<<boxes[i].getDensity()<<setw(13)<<"New ->> X: "<<boxes[i].getX()+boxes[i].getWidth()<<setw(5)<<"Y: "<<boxes[i].getY()+boxes[i].getHeight()<<endl;
			}
		}	
	}
}