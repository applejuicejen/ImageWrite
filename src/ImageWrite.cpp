#include "ImageWrite.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <cmath>
ImageWrite::ImageWrite(int _w, int _h)
{
  m_width=_w;
  m_height=_h;
  m_data = new unsigned char [m_width*m_height*3];
}

ImageWrite::~ImageWrite()
{
  if(m_data != 0)
  {
    delete [] m_data;
  }

}

void ImageWrite::clear(unsigned char _r, unsigned char _g, unsigned char _b)
{
  for(int y=0; y < m_height; y++)
  {
    for(int x=0; x < m_width; x++)
    {
      setPixel(x, y, _r, _g, _b);
    }
  }
}

void ImageWrite::save(const std::string &_fname)
{
  std::ofstream output;
  output.open(_fname);

  if(!output.is_open())
  {
    std::cerr<<"Problem opening file "<<_fname<<"\n";
    exit(EXIT_FAILURE);
  }

  output<<"P3\n";
  output<<m_width<<" "<<m_height<<"\n";
  output<<"255\n";
  for(int i=0; i<m_height*m_width*3; i++)
  {
    output<<(int)m_data[i]<<" ";
  }
  output<<"\n";
  output.close();
}

void ImageWrite::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  assert(_x < m_width && _y < m_height);
  unsigned int index = (_y*m_width*3)+(_x*3);
  m_data[index]=_r;
  m_data[index+1]=_g;
  m_data[index+2]=_b;
}

void ImageWrite::line(int _x0, int _y0, int _x1, int _y1)
{
  float deltax = _x1 - _x0;
  float deltay = _y1 - _y0;
  float error = 0.0f;

  float deltaerr = std::abs(deltay / deltax);
  int y = _y0;
  if(_x0 < _x1)
  {
    for(int x = _x0; x < _x1; x++)
    {
      setPixel(x, y, 255, 255, 255);
      error = error + deltaerr;
      while( error > 0.5 )
      {
        setPixel(x, y, 255, 255, 255);
        y = y + sign(_y1-_y0);
        error = error - 1.0;
      }
    }
  }
  else
  {
    for(int x = _x1; x < _x0; x++)
    {
      setPixel(x, y, 255, 255, 255);
      error = error + deltaerr;
      while( error > 0.5 )
      {
        setPixel(x, y, 255, 255, 255);
        y = y + sign(_y1-_y0);
        error = error - 1.0;
      }
    }
  }
}

int ImageWrite::sign(float _val)
{
  if(_val >= 0)
    return 1;
  else
    return -1;
}



































