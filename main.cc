#include <iostream>
#include <sstream>
#include <time.h>
#include "utf8.h"

using namespace std;

const int loopend = 1000000;

void advanced(utf8 * str)
{
  clock_t start = clock();
  for (int i = 0; i < loopend; i++)
  {
    for (int j = 0; j < 4; j++){}
  }
  clock_t end = clock();
  double for_time = (double)(end - start);

  for (int i = 0; i < 4; i++)
  {
    cout << str[i];
    if (i == 3)
    {
      cout << endl;
    }
  }
  start = clock();
  for (int i = 0; i < loopend; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      str[j].countBytes13();
    }
  }
  end = clock();
  double str_13= (double)(end - start);
  start = clock();
  for (int i = 0; i < loopend; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      str[j].countBytes31();
    }
  }
  end = clock();
  double str_31= (double)(end - start);
  start = clock();
  for (int i = 0; i < loopend; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      str[j].countBytes();
    }
  }
  end = clock();
  double diff_table = (double)(end - start) - for_time;
  cout << "clock diff13     : " << str_13 - for_time << endl;
  cout << "clock diff31     : " << str_31 - for_time << endl;
  cout << "clock diff_table : " << diff_table - for_time << endl;
}

int main()
{
//  utf8 u2[] = {utf8(0xe6, 0xb3, 0x95), utf8(0xe6, 0x94, 0xbf), utf8(0xe5, 0xa4, 0xa7), utf8(0xe5, 0xad, 0xa6)};
//  utf8 u3[4];
//  utf8 u4;
//  utf8 u5[10];
//
//  // show utf-8 character
//  for(int i = 0; i < 4; i++)
//  {
//    cout << i << " : " << u2[i] << endl;
//  }
//
//  string s("法政大学");
//  int offset = 0;
//  const char* sp = s.c_str();
//  for (int i = 0; i < 4; i++)
//  {
//    u3[i] = utf8(sp+offset);
//    offset += u3[i].countBytes();
//    cout << u3[i] << '/';
//  }
//  cout << endl;

// 標準課題  
  cout << endl << "標準課題" << endl;

  utf8 uc = utf8(0xe6, 0xb3, 0x95);

  clock_t start = clock();
  for (int i = 0; i < loopend; i++) {}
  clock_t end = clock();
  double for_time = (double)(end - start);

  start = clock();
  for (int i = 0; i < loopend; i++)
  {
    uc.countBytes13();
  }
  end = clock();
  double diff13 = (double)(end - start);

  start = clock();
  for (int i = 0; i < loopend; i++)
  {
    uc.countBytes31();
  }
  end = clock();
  double diff31 = (double)(end - start);

  cout << "clock diff13 : " << diff13 - for_time << endl;
  cout << "clock diff31 : " << diff31 - for_time << endl;

// 発展課題
  cout << endl << "発展課題" << endl;
  // 情報科学 -------------------------------------------------------
  cout << "==============================" << endl;
  utf8 str1[] = {utf8(0xe6, 0xb3, 0x95), utf8(0xe6, 0x94, 0xbf), utf8(0xe5, 0xa4, 0xa7), utf8(0xe5, 0xad, 0xa6)};
  advanced(str1);

  // ABCD ----------------------------------------------------------
  cout << "==============================" << endl;
  utf8 str2[] = {utf8(0x41), utf8(0x42), utf8(0x43), utf8(0x44)};
  advanced(str2);

  // 法政AB
  cout << "==============================" << endl;
  utf8 str3[] = {utf8(0xe6, 0xb3, 0x95), utf8(0xe6, 0x94, 0xbf), utf8(0x41), utf8(0x42)};
  advanced(str3);

  // AB法政
  cout << "==============================" << endl;
  utf8 str4[] = {utf8(0x41), utf8(0x42), utf8(0xe6, 0xb3, 0x95), utf8(0xe6, 0x94, 0xbf)};
  advanced(str4);

  // A法政情
  cout << "==============================" << endl;
  utf8 str5[] = {utf8(0x41), utf8(0xe6, 0xb3, 0x95), utf8(0xe6, 0x94, 0xbf), utf8(0xe5, 0xa4, 0xa7)};
  advanced(str5);

  // ABC法
  cout << "==============================" << endl;
  utf8 str6[] = {utf8(0x41), utf8(0x42), utf8(0x43), utf8(0xe6, 0xb3, 0x95)};
  advanced(str6);

}
