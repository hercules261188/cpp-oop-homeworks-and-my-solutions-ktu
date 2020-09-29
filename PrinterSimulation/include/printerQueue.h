#ifndef PRINTERQUEUE_H
#define PRINTERQUEUE_H

#include "document.h"
#include <math.h>

struct SpeedArgs
{
	int speedOfPrinter;
	int speedOfPC;
};

struct PrinterQueue{
	int queueSize;
	int documentCount;
	int printedDocumentCount;
	bool isPrinting = true;
	int timeToStartPrinting;
	int totalPrintTimeOfThePrintingDocument;
	Document* documents;
	PrinterQueue() : documentCount(0), printedDocumentCount(0) {}
	void addDocument(Document document, int& queuedDocumentIndex, int processingTime){
		if(documentCount == queueSize){
			cout << "Printer queue is full now!" << endl;
		}
		else{
			if(documentCount == 0){
				documents = new Document[++documentCount];
				documents[0] = document;
			}
			else{
				Document* tempDocuments = new Document[documentCount];
				for(int index = 0; index < documentCount; index++){
					tempDocuments[index] = documents[index];
				}
				documents = new Document[++documentCount];
				for(int index = 0; index < documentCount - 1; index++){
					documents[index] = tempDocuments[index];
				}
				documents[documentCount - 1] = document;
				delete[] tempDocuments;
			}
			queuedDocumentIndex++;
			cout << "The printer pushed the " << document.name << " document to queue when "<< processingTime << ". second!" << endl;
		}
		
	}
	void deleteDocument(){
		if(documentCount == 1){
			documentCount--;
			delete[] documents;
		}
		else{
			Document* tempDocuments = new Document[--documentCount];
			for(int index = 1; index < documentCount + 1; index++){
				tempDocuments[index - 1] = documents[index];
			}
			documents = new Document[documentCount];
			for(int index = 0; index < documentCount; index++){
				documents[index] = tempDocuments[index];
			}
			delete[] tempDocuments;
		}
		printedDocumentCount++;
		
	}
	void printing(int processingTime, SpeedArgs speedArgs){
		cout << "Printing is in process... " << processingTime << ". sn" << endl;
		if(documents[0].pageCount == 0){
			cout << documents[0].name << " document has no page to print!" << endl;
			this->deleteDocument();
		}
		else{
			if(isPrinting){
				timeToStartPrinting = processingTime;
				totalPrintTimeOfThePrintingDocument = ceil(documents[0].pageCount * 60 / double(speedArgs.speedOfPrinter));
				isPrinting = false;
			}
			cout<<documents[0].name << " document is printing " << endl;
			if(processingTime == timeToStartPrinting + totalPrintTimeOfThePrintingDocument){
				cout << documents[0].name << " document printed when " << processingTime << ". second!" << endl;
				this->deleteDocument();
				isPrinting = true;
			}
		}
	}
};

#endif