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

    Image thirdImage;
    thirdImage = firstImage + secondImage;
    thirdImage.getFileName() << thirdImage;

    Image fourthImage;
    fourthImage = firstImage * secondImage;
    (fourthImage.getFileName()) << fourthImage;

    Image fifthImage;
    fifthImage = !firstImage;
    (fifthImage.getFileName()) << fifthImage;
    
    return 0;

}