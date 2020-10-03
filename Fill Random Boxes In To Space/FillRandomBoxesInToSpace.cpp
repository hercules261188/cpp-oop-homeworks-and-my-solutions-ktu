/*

	Uzunlugu ve Genisligi Belirlenerek Olusturulan Bir Uzaya Rastgele Yerlestirilen Kutular
		
	Ad Soyad	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com
		
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include "space.h"

int main(){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	MoveWindow(console, r.left, r.top,650,400,TRUE);
	int space_width,space_height;
	cout<<endl<<setw(75)<<"**You can create your space**"<<endl;
	cout<<setw(75)<<"**You can add boxes in your space**";
	cout<<endl<<endl<<endl<<setw(50)<<"!!! --> WELCOME <-- !!!"<<endl<<endl<<endl;
	cout<<setw(56)<<"Firstly You Must Create Your Space"<<endl;
	
	etiket3:cout<<endl<<endl<<" Space Width: ";
	cin>>space_width;
	if(space_width<=0){
		cout<<" This Value Must Positive!"<<endl;goto etiket3;
		}
	etiket4:cout<<endl<<endl<<" Space Height: ";
	cin>>space_height;
	if(space_height<=0){
		cout<<" This Value Must Positive!"<<endl;goto etiket4;
	}
	space myspace(space_width,space_height);
	cout<<endl<<setw(53)<<"It's Time to Add Random Boxes"<<endl;
	int boxmax,boxdensity,boxquantity;
	etiket7:cout<<endl<<endl<<" How Many Boxes Do You Want to Place in Your Space:";
	cin>>boxquantity;
	if(boxquantity<=0){
		cout<<" This Value Must Positive!"<<endl;goto etiket7;
	}
	
	etiket1:cout<<endl<<endl<<" Max Width and Height for Random Boxes: ";
	cin>>boxmax;
	if(boxmax<=0){
		cout<<" This Value Must Positive!"<<endl;goto etiket1;
	}
	else if(boxmax>space_width || boxmax>space_height){
		cout<<" This Value Can't Greater Than Space Width or Height!"<<endl;goto etiket1;
	}
	cout<<endl<<endl<<endl<<setw(60)<<"Wait. Every Box Have Density in This Space!"<<endl<<endl<<setw(63)<<"You Can Set Density With Your Choice or Random Value"<<endl<<endl;
	cout<<" Setting Random(Press R) or Your Choice(Any Key): ";
	char kontrol;
	cin>>kontrol;
	switch(kontrol){
		case 'R':
			etiket2:cout<<endl<<endl<<" Max Value For Random Density: ";
			cin>>boxdensity;
			if(boxdensity<=0){
				cout<<" This Value Must Positive!"<<endl;goto etiket2;
			}
			myspace.fillrandombox(boxquantity,boxmax,boxdensity,1);
			break;
		default :
			etiket5:cout<<endl<<endl<<" Density Which Your Choice: ";
			cin>>boxdensity;
			if(boxdensity<=0){
				cout<<" This Value Must Positive!"<<endl;goto etiket5;
			}
			myspace.fillrandombox(boxquantity,boxmax,boxdensity);
			break;
		}
	cout<<endl<<endl;
	myspace.printBoxCoordinates();
	cout<<endl<<endl;
	myspace.centerofmass();
	cout<<endl<<endl<<" Press Anykey To Restart or Press 0(Zero) to Exit:";
	cin>>kontrol;
	switch(kontrol){
		case '0':exit(0);break;
		default:cout<<endl;goto etiket3;break;
	}
	return 0;
}
