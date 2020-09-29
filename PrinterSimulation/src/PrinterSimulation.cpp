/*
	Printer Simulation
	
	Full Name	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com

*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <math.h>
#include "printerQueue.h"

using namespace std;

void welcomeScreen(PrinterQueue& printerQueue, SpeedArgs& speedArgs);

void getDocumentCountFromFile(ifstream &documentsFile, int &documentCount);

void getDocumentsFromFile(ifstream &documentsFile, Document* documents);

int main()
{
	PrinterQueue printerQueue;
	SpeedArgs speedArgs;
	welcomeScreen(printerQueue, speedArgs);
	
	ifstream documentsFile;
	int documentCount = 0;
	getDocumentCountFromFile(documentsFile, documentCount);

	Document* documents = new Document[documentCount];
	getDocumentsFromFile(documentsFile, documents);

	int processingTime = 0;
	int queuedDocumentIndex = 0;
	do
	{
		Sleep(1000);
		processingTime++;
		if(processingTime % speedArgs.speedOfPC == 0 && queuedDocumentIndex < documentCount){
			printerQueue.addDocument(documents[queuedDocumentIndex], queuedDocumentIndex, processingTime);
		}
		printerQueue.printing(processingTime, speedArgs);
	} while (printerQueue.printedDocumentCount < documentCount);
	cout << "Printer queue is empty!" << endl;
	cout << "Printing process completed!" << endl;

	return 0;
}

void welcomeScreen(PrinterQueue& printerQueue, SpeedArgs& speedArgs)
{
	cout << "Please enter the maximum number of documents that can be kept in the printer queue:";
label1:
	cin >> printerQueue.queueSize;
	if (printerQueue.queueSize < 1)
	{
		cout << "Maximum number of documents can't be less than one" << endl
			 << "Please re-enter the maximum number of documents:";
		goto label1;
	}
	cout << "Please specify how many pages per minute the printer can print:";
label2:
	cin >> speedArgs.speedOfPrinter;
	if (speedArgs.speedOfPrinter < 10)
	{
		cout << "Please use a faster printer :)" << endl
			 << "Please re-enter the printer speed:";
		goto label2;
	}
	cout << "Please specify in how many seconds the PC will send 1 document to the printer:";
label3:
	cin >> speedArgs.speedOfPC;
	if (speedArgs.speedOfPrinter < 1)
	{
		cout << "What era do we live in :)" << endl
			 << "Please re-enter:";
		goto label3;
	}
}

void getDocumentCountFromFile(ifstream &documentsFile, int &documentCount)
{
	char data[350];
again_file_control:
	documentsFile.open("./doc/Document.txt");
	if (!documentsFile)
	{
		cout << "Document file does not found." << endl;
		cout << "Please add the document which appropriate format in the to the directory where the program is located." << endl;
		cout << "If you added the document, press any number, or 0 to exit the program:";
		int file_control;
		cin >> file_control;
		if (file_control == 0)
		{
			exit(0);
		}
		goto again_file_control;
	}
	else if(documentsFile.peek() == std::ifstream::traits_type::eof()){
		cout << "Document file is empty!" << endl;
		exit(0);
	}
	while (!documentsFile.eof())
	{
		documentsFile.getline(data, 300);
		documentCount++;
	}
	documentsFile.close();
}

void getDocumentsFromFile(ifstream &documentsFile, Document *documents)
{
	documentsFile.open("./doc/Document.txt");
	int index = 0;
	while (!documentsFile.eof())
	{
		documentsFile >> documents[index].name;
		documentsFile >> documents[index].size;
		documentsFile >> documents[index].pageCount;
		documentsFile >> documents[index].owner.name;
		documentsFile >> documents[index].owner.surname;
		documentsFile >> documents[index].owner.username;
		documentsFile >> documents[index].owner.email;
		documentsFile >> documents[index].owner.yearOfBirthdate;
		documentsFile >> documents[index].createdDate.year;
		documentsFile >> documents[index].createdDate.month;
		documentsFile >> documents[index].createdDate.day;
		documentsFile >> documents[index].createdDate.hour;
		documentsFile >> documents[index].createdDate.minute;
		documentsFile >> documents[index].createdDate.second;
		index++;
	}
	documentsFile.close();
}