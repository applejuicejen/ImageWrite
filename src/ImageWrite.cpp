#include "ImageWrite.h"
#include <cassert>
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

void ImageWrite::save(const std::string &_fname)
{

}

void ImageWrite::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  assert(_x < m_width && _y < m_height);
  unsigned int index = (_y*m_width*3)+(_x*3);
  m_data[index]=_r;
  m_data[index+1]=_g;
  m_data[index+2]=_b;
}
