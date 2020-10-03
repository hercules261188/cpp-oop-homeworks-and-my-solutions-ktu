#include "image.h"

int main(int argc, char* argv[])
{

    Image firstImage;
    argv[1] >> firstImage;
    firstImage.sobel();
    firstImage.threshold(100);
    
    Image secondImage;
    argv[2] >> secondImage;
    secondImage.sobel();
    secondImage.threshold(100);
    argv[3] << firstImage;
    argv[4] << secondImage;

    // Image thirdImage;
    // thirdImage = firstImage + secondImage;
    // thirdImage.sobel();
    // thirdImage.threshold(100);
    // thirdImage.getFileName() << thirdImage;

    Image fourthImage;
    fourthImage = firstImage * secondImage;
    fourthImage.sobel();
    fourthImage.threshold(100);
    // for(int i = 0; i < fourthImage.getHeight(); i++){
    //     for(int j = 0; j < fourthImage.getWidth(); j++){
    //         cout << (unsigned int)fourthImage.getPixelValue(i, j);
    //     }
    //     cout<<endl;
    // }
    Image temp = fourthImage;
    (temp.getFileName()) << temp;
    
    return 0;

}