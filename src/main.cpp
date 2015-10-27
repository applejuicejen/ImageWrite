#include <iostream>
#include <cstdlib>

#include "ImageWrite.h"
int main()
{
  std::cout<<"working\n";
  ImageWrite myImage(200,200);
  //myImage.setPixel(50,50,255,255,255);
  myImage.clear(0,0,0);
  /*for(int y=0; y<200; y++)
    for(int x=0; x<200; x++)
    {
      myImage.setPixel(x, y, rand()%255, rand()%255, rand()%255);
    }*/
  myImage.line(100, 50, 0, 0);
  myImage.save("test.ppm");
  return EXIT_SUCCESS;
}
