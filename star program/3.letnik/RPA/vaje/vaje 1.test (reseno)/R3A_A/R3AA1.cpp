#include <iostream>
#include <cstring>

using std::string;
using std::cout;
using std::cin;

void Izpisi(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		cout<<*(px+i);
	}
}

void MalaZacetnica(char x[],char *px) {
	//prva crka
	if(*(px)>=97&&*(px)<=112) {
		*(px)=*(px)-32;
	}
	for(int i=1;i<strlen(x);++i) {
		if(*(px+i)==' ') {
			if(*(px+i+1)>=97&&*(px+i+1)<=112) {
				*(px+i+1)=*(px+i+1)-32;
			}
		}
	}
}

void ZamakniDESNO(char x[],char *px,int index) {
	for(int i=strlen(x);i>index;--i) {
		*(px+i+2)=*(px+i);
	}
}

void Pika(char x[],char *px) {
	for(int i=1;i<strlen(x);++i) {
		if(*(px+i)>=65&&*(px+i)<=90) {
			ZamakniDESNO(x,px,i);
			*(px+i+1)='.';
			*(px+i+2)=' ';
			return;
		}
	}
}

void VelikaZacetnicaPredPiko(char x[],char *px) {
	//teoreticno je i loh 2
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)=='.') {
			if(*(px+i-1)>=97&&*(px+i-1)<=112) {
				*(px+i-1)=*(px+i-1)-32;
			}
		}
	}
}

int main() {
	char x[202],*px;
	px=&x[0];

	fgets(x,100,stdin);
	//cout<<(int)'a'<<(int)'A'<<(int)'z'<<(int)'Z';
	
	Pika(x,px);
	VelikaZacetnicaPredPiko(x,px);
	MalaZacetnica(x,px);
	
	Izpisi(x,px);
	return 0;
}