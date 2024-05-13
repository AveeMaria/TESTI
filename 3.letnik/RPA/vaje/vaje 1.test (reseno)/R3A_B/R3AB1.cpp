#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;

//ta funkcija je nepotrebna 
int StPresledkov(char x[],char *px) {
	int presledki=0;
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)==' ') {
			presledki++;
		}
	}
	return presledki;
}

void ZamakniDESNO(char x[],char y[],char *px,char *py,int index) {
	for(int i=strlen(x);i>index;--i) {
		*(px+i+strlen(y))=*(px+i);
		//Izpisi(x,px);
	}	
}

void VstaviIme(char x[],char y[],char *px,char *py,int index) {
	for(int i = 0;i<strlen(y)-1; i++){
        *(px+i+index+1) = *(py+i);
    }
    //presledek po drugem imenu/priimku
    *(px+strlen(y)+index) = ' ';
}

int NajdiIndex(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)==' ') {
			return i;
		}
	}
}

//a=97 z=122 A=65 Z=90
//preveris: char a='A';cout<<(int)a;
void VelikaZacetnica(char x[],char *px) {
	//za prvo crko k je vedn velka
	if(*(px)>=97&&*(px)<=122) {
		*(px)=*(px)-32;
	}
	//za ostala imena/priimke
	for(int i=1;i<strlen(x);++i) {
		if(*(px+i)==' ') {
			if(*(px+i+1)>=97&&*(px+i+1)<=122) {
				*(px+i+1)=*(px+i+1)-32;
			}
		}
	}
	
}

void Izpisi(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		cout<<*(px+i);
	}
	cout<<"\n";
}

int main() {
	char x[202],*px,y[101],*py;
	px=&x[0];py=&y[0];

	cout<<"vpisi ime in priimek: ";fgets(x,100,stdin);
	cout<<"vpisi drugo ime: ";fgets(y,100,stdin);
	
	ZamakniDESNO(x,y,px,py,NajdiIndex(x,px));
	VstaviIme(x,y,px,py,NajdiIndex(x,px));
	VelikaZacetnica(x,px);

	Izpisi(x,px);
	return 0;
}