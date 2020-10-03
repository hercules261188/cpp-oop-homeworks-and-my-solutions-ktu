/*

	Uzunlugu ve Genisligi Belirlenerek Olusturulan Bir Uzaya Rastgele Yerlestirilen Kutular
		
	Ad Soyad	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com
		
*/

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
	
	label3:cout<<endl<<endl<<" Space Width: ";
	cin>>space_width;
	if(space_width<=0){
		cout<<" This Value Must Positive!"<<endl;goto label3;
		}
	label4:cout<<endl<<endl<<" Space Height: ";
	cin>>space_height;
	if(space_height<=0){
		cout<<" This Value Must Positive!"<<endl;goto label4;
	}
	Space mySpace(space_width, space_height);
	cout<<endl<<setw(53)<<"It's Time to Add Random Boxes"<<endl;
	int boxMax, boxDensity, boxQuantity;
	label7:cout<<endl<<endl<<" How Many Boxes Do You Want to Place in Your Space:";
	cin>>boxQuantity;
	if(boxQuantity <= 0){
		cout<<" This Value Must Positive!"<<endl;goto label7;
	}
	
	label1:cout<<endl<<endl<<" Max Width and Height for Random Boxes: ";
	cin>>boxMax;
	if(boxMax <= 0){
		cout<<" This Value Must Positive!"<<endl;goto label1;
	}
	else if(boxMax>space_width || boxMax>space_height){
		cout<<" This Value Can't Greater Than Space Width or Height!"<<endl;goto label1;
	}
	cout<<endl<<endl<<endl<<setw(60)<<"Wait. Every Box Have Density in This Space!"<<endl<<endl<<setw(63)<<"You Can Set Density With Your Choice or Random Value"<<endl<<endl;
	cout<<" Setting Random(Press R) or Your Choice(Any Key): ";
	char kontrol;
	cin>>kontrol;
	switch(kontrol){
		case 'R':
			label2:cout<<endl<<endl<<" Max Value For Random Density: ";
			cin>>boxDensity;
			if(boxDensity <= 0){
				cout<<" This Value Must Positive!"<<endl;goto label2;
			}
			mySpace.fillRandomBox(boxQuantity, boxMax, boxDensity, 1);
			break;
		default :
			label5:cout<<endl<<endl<<" Density Which Your Choice: ";
			cin>>boxDensity;
			if(boxDensity <= 0){
				cout<<" This Value Must Positive!"<<endl;goto label5;
			}
			mySpace.fillRandomBox(boxQuantity, boxMax, boxDensity);
			break;
		}
	cout<<endl<<endl;
	mySpace.printBoxCoordinates();
	cout<<endl<<endl;
	mySpace.centerOfMass();
	cout<<endl<<endl<<" Press Anykey To Restart or Press 0(Zero) to Exit:";
	cin>>kontrol;
	switch(kontrol){
		case '0':exit(0);break;
		default:cout<<endl;goto label3;break;
	}
	return 0;
}
