/*
	Yazici Simulasyonu
	
	Ad Soyad	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com

*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct OwnerOfDocument
{
	string name, surname, username, e_mail;
	int year_of_birthdate;
};

struct CreatedDateOfDocument
{
	int year, month, day, hour, minute, second;
};

struct Document
{
	string name;
	int size, page_count;
	OwnerOfDocument owner;
	CreatedDateOfDocument created_date;
};

void findRowOfFile(ifstream &fileOfDocuments, int &rowOfFile);

void pushDocumentToTail(ifstream &fileOfDocuments, Document *tail);

int main()
{
	int maxTailSize, speedOfPrinter, rowOfFile = 0;
	ifstream fileOfDocuments;
	cout << "Lutfen yazici kuyrugunda tutulabilecek maximum belge sayisini giriniz:";
etiket1:
	cin >> maxTailSize;
	if (maxTailSize < 1)
	{
		cout << "Kuyrukta tutulabilecek belge sayisi 1 den kucuk olamaz." << endl
			 << "Lutfen tekrar giriniz:";
		goto etiket1;
	}
	cout << "Lutfen yazicinin saniyede kac sayfa yazdirabilegini belirtin:";
etiket2:
	cin >> speedOfPrinter;
	if (speedOfPrinter < 1)
	{
		cout << "Lutfen daha hizli bir yazici kullanin :)" << endl
			 << "Yeni yazici hizi:";
		goto etiket2;
	}
	else if (speedOfPrinter > 5)
	{
		cout << "Lutfen gercekci degerler giriniz :)" << endl
			 << "Yeni yazici hizi:";
		goto etiket2;
	}

	findRowOfFile(fileOfDocuments, rowOfFile);

	Document *tail = new Document[rowOfFile];

	pushDocumentToTail(fileOfDocuments, tail);

	int seconds = 0;
	int secondpointer = 0;
	int topSecondOfPushing = 0;
	bool printerBeginPrint = false;
	for (int i = 0; i < rowOfFile; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < tail[i].size / 100 + 1; j++)
			{
				cout << tail[i].name << " belgesi yaziciya gonderiliyor..." << endl;
				Sleep(1000);
				seconds++;
			}
			cout << tail[i].name << " belgesi " << seconds << ". saniyede yaziciya gonderildi. Kuyruk: " << tail[i].name << endl;
			secondpointer++;
			topSecondOfPushing += seconds;
		}
		if (tail[i].page_count == 0)
		{
			if (!printerBeginPrint && i > 0)
			{
				for (int j = 0; j < tail[i].size / 100 + 1; j++)
				{
					cout << tail[i].name << " belgesi yaziciya gonderiliyor..." << endl;
					Sleep(1000);
					seconds++;
				}
				cout << tail[i].name << " belgesi " << seconds << ". saniyede yaziciya gonderildi. Kuyruk: " << tail[i].name << endl;
				secondpointer++;
				topSecondOfPushing += seconds;
			}
			if (i != rowOfFile - 1)
			{
				if (!printerBeginPrint)
				{
					cout << tail[i].name << " belgesinin yazdirilacak sayfasi yok. Kuyruk: Bos" << endl;
				}
				else
				{
					cout << tail[i].name << " belgesinin yazdirilacak sayfasi yok. Kuyruk: ";
					for (int j = i + 1; j < secondpointer; j++)
					{
						cout << tail[j].name << " ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << tail[i].name << " belgesinin yazdirilacak sayfasi yok. Kuyruk: Bos" << endl;
				cout << "Yazdirma islemi tamamlandi";
				exit(0);
			}
		}
		else
		{
			if (!printerBeginPrint)
			{
				printerBeginPrint = true;
				for (int j = 0; j < tail[i].size / 100 + 1; j++)
				{
					cout << tail[i].name << " belgesi yaziciya gonderiliyor..." << endl;
					Sleep(1000);
					seconds++;
					cout << tail[i].name << " belgesi " << seconds << ". saniyede yaziciya gonderildi. Kuyruk: " << tail[i].name << endl;
					secondpointer++;
				}
			}
			for (int j = 0; j < tail[i].page_count / speedOfPrinter; j++)
			{
				cout << tail[i].name << " Belgesi yazdiriliyor..." << endl;
				Sleep(1000);
				seconds++;
				if (secondpointer < rowOfFile)
				{
					if (seconds == tail[secondpointer].size / 100 + 1 + topSecondOfPushing)
					{
						cout << tail[secondpointer].name << " belgesi " << seconds << ". saniyede yaziciya gonderildi. Kuyruk: ";
						topSecondOfPushing += tail[secondpointer].size / 100 + 1;
						secondpointer++;
						for (int j = i; j < secondpointer; j++)
						{
							cout << tail[j].name << " ";
						}
						cout << endl;
					}
				}
			}
			if (i == rowOfFile - 1)
			{
				cout << tail[i].name << " belgesinin yazdirilma islemi tamamlandi! Kuyruk: Bos" << endl;
				cout << "Yazdirma islemi tamamlandi";
				exit(0);
			}
			else
			{
				cout << tail[i].name << " belgesinin yazdirilma islemi tamamlandi! Kuyruk: ";
				for (int j = i + 1; j < secondpointer; j++)
				{
					cout << tail[j].name << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}

void findRowOfFile(ifstream &fileOfDocuments, int &rowOfFile)
{
	char data[350];
again_file_control:
	fileOfDocuments.open("Document.txt");
	if (!fileOfDocuments)
	{
		cout << "Belge bulunamadi." << endl;
		cout << "Lutfen programin bulundugu dizine uygun formattaki belgeyi ekleyin." << endl;
		cout << "Belgeyi eklediyseniz herhangi bir sayiya, programdan cikmak icin 0'a basiniz.";
		int file_control;
		cin >> file_control;
		if (file_control == 0)
		{
			exit(0);
		}
		goto again_file_control;
	}
	while (!fileOfDocuments.eof())
	{
		fileOfDocuments.getline(data, 300);
		rowOfFile++;
	}
	fileOfDocuments.close();
}

void pushDocumentToTail(ifstream &fileOfDocuments, Document *tail)
{
	fileOfDocuments.open("Document.txt");
	int i = 0;
	while (!fileOfDocuments.eof())
	{
		fileOfDocuments >> tail[i].name;
		fileOfDocuments >> tail[i].size;
		fileOfDocuments >> tail[i].page_count;
		fileOfDocuments >> tail[i].owner.name;
		fileOfDocuments >> tail[i].owner.surname;
		fileOfDocuments >> tail[i].owner.username;
		fileOfDocuments >> tail[i].owner.e_mail;
		fileOfDocuments >> tail[i].owner.year_of_birthdate;
		fileOfDocuments >> tail[i].created_date.year;
		fileOfDocuments >> tail[i].created_date.month;
		fileOfDocuments >> tail[i].created_date.day;
		fileOfDocuments >> tail[i].created_date.hour;
		fileOfDocuments >> tail[i].created_date.minute;
		fileOfDocuments >> tail[i].created_date.second;
		i++;
	}
	fileOfDocuments.close();
}
