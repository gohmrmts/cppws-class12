#include <iostream>

class utf8 
{
  unsigned char byte[6];

  // utf8 内部で使う定数
  static unsigned const char Mask1Byte  = 0x80;
  static unsigned const char Match1Byte = 0x00;
  static unsigned const char Mask2Byte  = 0xe0;
  static unsigned const char Match2Byte = 0xc0;
  static unsigned const char Mask3Byte  = 0xf0;
  static unsigned const char Match3Byte = 0xe0;
  static unsigned const char Mask4Byte  = 0xf8;
  static unsigned const char Match4Byte = 0xf0;
  static unsigned const char Mask5Byte  = 0xfc;
  static unsigned const char Match5Byte = 0xf8;
  static unsigned const char Mask6Byte  = 0xfe;
  static unsigned const char Match6Byte = 0xfc;
  
  // バイト数判定
  inline bool is1byte()
  {
    return ((byte[0] & Mask1Byte) == Match1Byte);
  }
  inline bool is2byte()
  {
    return ((byte[0] & Mask2Byte) == Match2Byte);
  }
  inline bool is3byte()
  {
    return ((byte[0] & Mask3Byte) == Match3Byte);
  }
  inline bool is4byte()
  {
    return ((byte[0] & Mask4Byte) == Match4Byte);
  }
  inline bool is5byte()
  {
    return ((byte[0] & Mask5Byte) == Match5Byte);
  }
  inline bool is6byte()
  {
    return ((byte[0] & Mask6Byte) == Match6Byte);
  }

  public:
  // コンストラクタ
    utf8(unsigned char x0 = 0, unsigned char x1 = 0, unsigned char x2 = 0, unsigned char x3 = 0, unsigned char x4 = 0, unsigned char x5 = 0);
    utf8(const unsigned char *xp);
    utf8(const char *xp);
    inline bool isNull()
    {
      return (byte[0] == 0);
    }
    int countBytes();
  friend std::istream& operator>> (std::istream&m, utf8&);
  friend std::ostream& operator<< (std::ostream&m, utf8&);
  friend std::ostream& operator>> (std::ostream&m, utf8*);
};
