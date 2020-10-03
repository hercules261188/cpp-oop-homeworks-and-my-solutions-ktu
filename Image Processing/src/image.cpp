#include "image.h"

void Image::setWidth(unsigned int width){
    this->width = width;
}

void Image::setHeight(unsigned int height){
    this->height = height;
}

unsigned int Image::getWidth(){
    return this->width;
}

unsigned int Image::getHeight(){
    return this->height;
}


void Image::setPixels(BYTE* pixels){
    this->pixels = new BYTE*[this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++)
    {
        this->pixels[i] = new BYTE[this->getWidth()];
        for(int j = 0; j < this->getWidth(); j++){
            this->pixels[i][j] = pixels[j * this->getHeight() + i]; // first 220 bytes of the binary file is first column of the image
        }
    }
}

BYTE Image::getPixelValue(unsigned int row, unsigned int column){
    return this->pixels[row][column];
}

void Image::setPixelValue(unsigned int row, unsigned int column, BYTE value){
    this->pixels[row][column] = value;
}

void Image::setFileName(char* fileName){
    this->fileName = fileName;
}

char* Image::getFileName(){
    return this->fileName;
}

void Image::threshold(unsigned int thresholdValue){
    for (int i = 0; i < this->getHeight(); i++)
    {
        for(int j = 0; j < this->getWidth(); j++){
            this->pixels[i][j] = (unsigned int)this->pixels[i][j] < thresholdValue ? (BYTE)0 : (BYTE)1;
        }
    }
}

void Image::sobel(){
    BYTE** tempArray = new BYTE*[this->getHeight()];
    for(int i = 0; i < this->getHeight(); i++){
        tempArray[i] = new BYTE[this->getWidth()];
    }

    for(int i = 1; i < this->getHeight() - 1; i++){
        for(int j = 1; j < this->getWidth() - 1; j++){
            int totalX = 0, totalY = 0;
            for(int k = -1, maskFirstIndex = 0; k < 2; k++, maskFirstIndex++){
                for(int t = -1, maskSecondIndex = 0; t < 2; t++, maskSecondIndex++){
                    totalX += this->sobelX[maskFirstIndex][maskSecondIndex] * (unsigned int)this->pixels[i + k][j + t];
                    totalY += this->sobelY[maskFirstIndex][maskSecondIndex] * (unsigned int)this->pixels[i + k][j + t];
                }
            }
            tempArray[i][j] = (BYTE)sqrt(pow(totalX, 2) + pow(totalY, 2));
        }
    }

    for (int i = 1; i < this->getHeight() - 1; i++) {
		for (int j = 1; j < this->getWidth() - 1; j++) {
			this->pixels[i][j] = tempArray[i][j];
		}
	}
    for(int i = 0; i < this->getHeight(); i++){
        delete[] tempArray[i];
    }
    delete[] tempArray;
}

Image& Image::operator=(const Image& image)
{
  this->fileName = image.fileName;
  this->height = image.height;
  this->width = image.width;
  this->pixels = new BYTE*[this->height];
  for(int i = 0; i < this->height; i++){
      this->pixels[i] = new BYTE[this->width];
      for(int j = 0; j < this->width; j++){
          this->pixels[i][j] = image.pixels[i][j];
      }
  }
  return *this;
}

Image& Image::operator+(const Image& image){
    Image *result = new Image();
    result->height = this->height;
    result->width = this->width;
    result->fileName = new char[8];
    result->fileName = (char*)"OR.txt";
    result->pixels = new BYTE*[this->height];
    for(int i = 0; i < this->height; i++){
        result->pixels[i] = new BYTE[this->width];
        for(int j = 0; j < this->width; j++){
            result->pixels[i][j] = this->pixels[i][j] | image.pixels[i][j];
        }
    }
    return *result;
}

Image& Image::operator*(const Image& image){
    Image *result = new Image();
    result->height = this->height;
    result->width = this->width;
    result->fileName = new char[8];
    result->fileName = (char*)"AND.txt";
    result->pixels = new BYTE*[this->height];
    for(int i = 0; i < this->height; i++){
        result->pixels[i] = new BYTE[this->width];
        for(int j = 0; j < this->width; j++){
            result->pixels[i][j] = this->pixels[i][j] & image.pixels[i][j];
        }
    }
    return *result;
}

Image& Image::operator!(){
    Image *result = new Image();
    result->height = this->height;
    result->width = this->width;
    result->fileName = new char[8];
    result->fileName = (char*)"NOT.txt";
    result->pixels = new BYTE*[this->height];
    for(int i = 0; i < this->height; i++){
        result->pixels[i] = new BYTE[this->width];
        for(int j = 0; j < this->width; j++){
            result->pixels[i][j] = !this->pixels[i][j];
        }
    }
    return *result;
}


istream& operator>> (char* fileName, Image& image)
{

    image.setFileName(fileName);
    char filePath[100];

    strcpy(filePath, "./doc/inputs/");
    strcat(filePath, fileName);

    ifstream file(filePath, ios::binary);
    if(!file){
        cout << "Please check file parameters. File does not exist!" << endl;
        exit(0);
    }

    BYTE* firstTwoByte = new BYTE[2]; // first byte -> height. second byte -> width
    file.read((char*)firstTwoByte, 2);

    image.setHeight((unsigned int)firstTwoByte[0]);
    image.setWidth((unsigned int)firstTwoByte[1]);

    file.seekg(2, ios::beg);
    BYTE* pixels = new BYTE[image.getHeight() * image.getWidth()];
    file.read((char*)pixels, image.getHeight() * image.getWidth()); // get all pixels from the image
    file.close();

    image.setPixels(pixels);
    
}

ostream& operator<< (char* fileName, Image& image)
{
    char filePath[100];
    strcpy(filePath, "./doc/outputs/");
    strcat(filePath, fileName);
    ofstream file(filePath);
    for (int i = 0; i < image.height; i++)
    {
        for(int j = 0; j < image.width; j++){
            file << (image.pixels[i][j] == (BYTE)1 ? "*" : "-");
        }
        file << endl;
    }
    file.close();
    return cout << fileName << " is printed now!" << endl;
}


Image::~Image()
{
    cout<< this->getFileName() << " destructor is called now!"<<endl;
    for(int i = 0; i < this->getHeight(); i++){
        delete[] this->pixels[i];
    }
    delete[] this->pixels;
}

