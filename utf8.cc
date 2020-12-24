#include <iostream>
#include <sstream>
#include "utf8.h"

unsigned const char utf8::SizePattern[] = 
{
  0, 1, 1, 1, 1, 1, 1, 1,       // 00-07
  1, 1, 1, 1, 1, 1, 1 ,1,       // 08-15
  1, 1, 1, 1, 1, 1, 1, 1,       // 16-23
  1, 1, 1, 1, 1, 1, 1 ,1,       // 24-31
  0, 0, 0, 0, 0, 0, 0, 0,       // 32-39
  0, 0, 0, 0, 0, 0, 0, 0,       // 40-47
  2, 2, 2, 2, 2, 2, 2, 2,       // 48-55
  3, 3, 3, 3, 4, 4, 5 ,6,       // 56-63
};

utf8::utf8(unsigned char x0, unsigned char x1, unsigned char x2, unsigned char x3, unsigned char x4, unsigned char x5)
{
  byte[0] = x0;
  byte[1] = x1;
  byte[2] = x2;
  byte[3] = x3;
  byte[4] = x4;
  byte[5] = x5;
}

utf8::utf8(const unsigned char *xp)
{
  int i = 0;
  byte[0] = xp[0];
  for (i = 1; i < countBytes(); i++)
  {
    byte[i] = xp[i];
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
    byte[i] = xp[i];
  }
  for (; i < 6; i++)
  {
    byte[i] = '\0';
  }
}

int utf8::countBytes13()
{
  if (is1byte()) return 1;
  else if (is2byte()) return 2;
  else if (is3byte()) return 3;
  else if (is4byte()) return 4;
  else if (is5byte()) return 5;
  else return 6;
}

int utf8::countBytes31()
{
  if (is3byte()) return 3;
  else if (is2byte()) return 2;
  else if (is1byte()) return 1;
  else if (is4byte()) return 4;
  else if (is5byte()) return 5;
  else 
  {
    std::cerr << "ERROR" << std::endl;
    return 6;
  }

}

std::istream& operator>> (std::istream& ios, utf8& uc)
{
  uc = utf8();                // sero clear uc
  ios >> uc.byte[0];
  for (int i = 0; i < uc.countBytes(); i++)
  {
    ios >> uc.byte[i];
  }
  return ios;
}

std::ostream& operator<< (std::ostream& ios, utf8& uc)
{
  for (int i = 0; i < uc.countBytes(); i++)
  {
    ios << uc.byte[i];
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

