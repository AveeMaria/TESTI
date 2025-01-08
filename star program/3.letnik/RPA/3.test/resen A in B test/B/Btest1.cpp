#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Zvezda{
	char ime[20];
	int oddaljenost;
	float velikost;
	void izpis();
};

void Zvezda::izpis() {
	cout<<"ime: "<<ime<<"\n"<<
	"oddaljenost: "<<oddaljenost<<
	"\tvelikost: "<<velikost<<"\n\n";
}

//najde najbolj oddaljeno zvezdo in jo zbrise in vrne v main
Zvezda NajdiBrisi() {
	ifstream datai("Zvezde.bin",ios::binary);
	ifstream datai2("Zvezde.bin",ios::binary);
	
	ofstream datao("tmp.bin",ios::binary);

	
	if(!datai.is_open()) {cout<<"file not open\n";return Zvezda{"",-1,-1.0};}
	if(!datai2.is_open()) {cout<<"file not open\n";return Zvezda{"",-1,-1.0};}
	if(!datao.is_open()) {cout<<"file not open\n";return Zvezda{"",-1,-1.0};}

	Zvezda deleted,a;

	//dam to najdeno/najbl oddaljeno na prvo
	datai2.read((char*)&deleted,sizeof(deleted));

	//najde najbl oddaljeno zvezdo
	while(datai2.read((char*)&a,sizeof(a))) {
		if(a.oddaljenost>deleted.oddaljenost) {
			deleted=a;
		}
	}

	//to je da ce se podvoji zbrise sam 1x
	bool zbrisano=false;

	while(datai.read((char*)&a,sizeof(a))) {

		if(a.oddaljenost != deleted.oddaljenost && zbrisano == false) {
			zbrisano=true;
			//prepise v tmp vse razn to k hocmo deletat
			datao.write((char*)&a,sizeof(a));
		}

	}

	//prever ce je prazn file da ni frke ce ni returna 
	if(zbrisano==false) {
		return Zvezda{"",-1,-1.0};
	}

	datai.close();
	datai2.close();
	datao.close();

	remove("Zvezde.bin");rename("tmp.bin","Zvezde.bin");

	return deleted;
}

void IzpisiBIN() {
	ifstream datai("Zvezde.bin",ios::binary);
		
	if(!datai.is_open()) {cout<<"file not open\n";return;}
	
	Zvezda a;
	
	while(datai.read((char*)&a,sizeof(a))) {
		a.izpis();
	}

	datai.close();
}

void VpisiBIN(Zvezda a) {
	ofstream datao("Zvezde.bin",ios::binary|ios::app);
		
	if(!datao.is_open()) {cout<<"file not open\n";return;}

	datao.write((char*)&a,sizeof(a));

	datao.close();
}

//to sam enkratno napolne dat z fake podatki
void NapolniDAT() {
	//spuca datoteko
	ofstream datao("Zvezde.bin",ios::binary);datao.close();

	//vpise 5 random podatkov
	VpisiBIN(Zvezda{"zvezda1",120430,244});
	VpisiBIN(Zvezda{"zvezda2",371327,923});
	VpisiBIN(Zvezda{"zvezda3",92921230,192});
	VpisiBIN(Zvezda{"zvezda4",912020,842});
	VpisiBIN(Zvezda{"zvezda5",2309100,7201});
}

int main(int argc, char const *argv[])
{
	NapolniDAT();
	IzpisiBIN();

	//najde, zbrise in izpise najbl oddaljeno (3.) zvezdo
	Zvezda zbrisana=NajdiBrisi();cout<<"\n--------------\n";
	zbrisana.izpis();cout<<"\n--------------\n";

	return 0;
}