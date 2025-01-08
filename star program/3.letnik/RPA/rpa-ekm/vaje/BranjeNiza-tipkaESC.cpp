#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void beri (string &niz)
{int i=0, zn;
 zn=getch();
 while (zn!=27)
 {cout << (char)zn;
  i++;
  niz.resize(i);
  niz[i-1]=(char)zn;
 // cout << niz << endl;
  zn=getch();
 }
}

int main()
{string test;
 //Klic funkcije beri:
 beri (test);
 cout << endl<< test << endl;
 return 0;
}
