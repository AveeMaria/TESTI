#include <iostream>
#include <string>
#include <conio.h>
#include <cstdio>
using namespace std;
struct Sosolec
{string ime, priimek, GSM;
};

bool beriNiz (string &niz)
{char znak;
 int i=1;
 znak=getche();
 while (znak!=(char)27 && znak!=(char)13) //Gre za tipki Escape ali ENTER
 {niz.resize(i);
  niz[i-1]=znak;
  znak=getche();
  i++;
 }
 cout << endl;
 if (znak==(char)13) return 0;
 else return 1;
}

void izpis(Sosolec x)
{cout << endl << "Ime: " << x.ime << endl;
 cout << "Priimek: " << x.priimek << endl;
 cout << "GSM stevilka: " << x.GSM << endl;
}

int main()
{Sosolec x;
 cout << "Ime: ";
 while (beriNiz(x.ime)!=1)
 {fflush (stdin);
  cout << "Priimek: ";
  getline (cin, x.priimek);
  fflush(stdin);
  cout << "GSM stevilka: ";
  getline (cin, x.GSM);
  fflush(stdin);
  izpis (x);
  cout << "Ime: ";
 }

 return 0;
}

