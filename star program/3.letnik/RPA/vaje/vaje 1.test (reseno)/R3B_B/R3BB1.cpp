#include <iostream>
#include <time.h>
#include <cstring>

using std::string;
using std::cout;
using std::cin;

void Izpisi(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		cout<<*(px+i);
	}
	cout<<"\n";
}

void ZamakniLEVO(char x[],char *px,int index) {
	for(int i=index;i<strlen(x);++i) {
		*(px+i)=*(px+i+1);
	}
}

int NajdiIndex(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)==*(px+i+1)) {
			return i;
		}
	}
}

int StPodvojitev(char x[],char *px)  {
	int dupes=0;
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)==*(px+i+1)) {
			dupes++;
		}
	}
	return dupes;
}

void Neki(char x[],char *px,int dupes) {
	for(int i=0;i<dupes;++i) {
		ZamakniLEVO(x,px,NajdiIndex(x,px));
	}
}

int main() {
	char x[202],*px,*py;
	px=&x[0];
	fgets(x,100,stdin);
	
	Neki(x,px,StPodvojitev(x,px));
	Izpisi(x,px);
	
	return 0;
}  