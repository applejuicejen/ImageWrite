#ifndef IMAGEWRITE_H__
#define IMAGEWRITE_H__

#include <string>
class ImageWrite
{
  public :
    ImageWrite() : m_width(0), m_height(0), m_data(0){}
    ImageWrite(int _w, int _h);
    ~ImageWrite();
    void save(const std::string &_fname);
    void setPixel(int _x, int _y, unsigned char _r,
                  unsigned char _g, unsigned char _b);
  private :
    int m_width;
    int m_height;
    unsigned char *m_data;
};
#endif
