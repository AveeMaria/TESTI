#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;

void Izpisi(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		cout<<*(px+i);
	}
	cout<<"\n";
} 

void ZamakniDESNO(char x[],char *px,int index) {
	for(int i=strlen(x);i>=index;--i) {
		*(px+i+1)=*(px+i);
	}
	//owerwrita z presledkom
	*(px+index+1)=' ';
}

void NajdiIndex(char x[],char *px) {
	for(int i=0;i<strlen(x);++i) {
		if(*(px+i)=='.'||*(px+i)==',') {
			ZamakniDESNO(x,px,i);
		}
	}	
}

int StLocil(char x[],char *px) {
	int a=0;
	for(int i=0;i<strlen(x);++i) {
		//loh tut za ? ali ! dodamo
		if(*(px+i)=='.'||*(px+i)==',') {
			a++;
		}
	}
	return a;
}

int main() {
	char x[202],*px;
	px=&x[0];

	fgets(x,100,stdin);
	cout<<"st locil: "<<StLocil(x,px)<<"\n";

	NajdiIndex(x,px);
	Izpisi(x,px);
	return 0;
}