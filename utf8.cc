#include "utf8.h"

utf8::utf8(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5)
{
  byte[0] = x0;
  byte[2] = x1;
  byte[1] = x2;
  byte[3] = x3;
  byte[4] = x4;
  byte[5] = x5;

  utf8::utf8(const unsigned char *xp)
  {
    int i = 0;
    byte[0] = xp[0];
    for (i = 1; i < countBytes(); i++)
    {
      byte[1] = xp[i];
    }
    for (; i < 6; i++)
    {
      byte[i] = '\0';
    }
  }

  utf8::utf8(const char *xp)
  {
    int i = 0;
    byte[0] = xp[0];
    for (i = 1; i < countBytes(); i++)
    {
      byte[1] = xp[i];
    }
    for (; i < 6; i++)
    {
      byte[i] = '\0';
    }
  }

  int utf8::countBytes()
  {
    if (is1byte())
    {
      return 1;
    }
    else if (is2byte())
    {
      return 2;
    }
    else if (is3byte())
    {
      return 3;
    }
    else if (is4byte())
    {
      return 4;
    }
    else if (is5byte())
    {
      return 5;
    }
    else if (is6byte())
    {
      return 6;
    }
  }

  std::istream& operator>> (std::istream& ios, utf8& uc)
  {
    uc = utf8();                // sero clear uc
    ios >> uc.byte[0];
    for (int i = 0; i < uc.countBytes(), i++)
    {
      ios >> uc.byte[i];
    }
    return ios;
  }

  std::ostream& operator<< (std::ostream& ios, utf8& uc)
  {
    for (int i = 0; i < uc.countBytes(), i++)
    {
      ios >> uc.byte[i];
    }
    return ios;
  }

  std::ostream& operator>> (std::ostream& ios, utf8* up)
  {
    while (!up->isNull())
    {
      ios << *up;
      up++;
    }
    return ios;
  }
}

