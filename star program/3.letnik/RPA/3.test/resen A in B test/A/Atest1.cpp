#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Potovanje{
    char dest[20];
    int st_dni;
    float cena;

    void izpis();
};

void Potovanje::izpis() {
    cout<<"destinacija: "<<dest<<"\n";
    cout<<"st_dni: "<<st_dni<<" cena: "<<cena<<"\n\n";
}

/*
Na disku neprazna Potovanja.bin s podatki
o destinaciji,st dni, ceni potovanja

Napisi funkcijo ki izpise podatke o vseh potovanjih
cenejsih od vpisane vsote. 
funkcija naj vrne podatke o prvem potovanju v datoteki;
*/

Potovanje Funkcija() {
    ifstream datai("Potovanja.bin",ios::binary);

    Potovanje prvo{"empty file",-1,-1};//to je kle da spodn return ce ni fila dela :3

    if(!datai.is_open()) {cout<<"file not open\n";return prvo;}
    
    cout<<"vpisi zeljeno ceno: ";
    float zeljenaCena;cin>>zeljenaCena;//vpises zeljeno ceno
    
    //za returnat prvo prebere prviga pa izpise ce je cenejsa od zelene cene
    //prebere prvo
    datai.read((char*)&prvo,sizeof(prvo));
    
    //sezmer more prvega izpisat ce je cenejsi
    if(prvo.cena<zeljenaCena) {
        prvo.izpis();
    }

    Potovanje a;
    while(datai.read((char*)&a,sizeof(a))) {
        if(a.cena<zeljenaCena) {
            a.izpis();
        }        
    }    
    datai.close();

    return prvo;
}

void IzpisiBIN() {
    ifstream datai("Potovanja.bin",ios::binary);
    
    if(!datai.is_open()) {cout<<"file not open\n";return ;}
    cout<<"\n-------------------------\n";
    Potovanje a;
    while(datai.read((char*)&a,sizeof(a))) {
        a.izpis();
    }
    cout<<"-------------------------\n";

    datai.close();
}

void VpisiBIN(Potovanje a) {
    ofstream datao("Potovanja.bin",ios::binary|ios::app);
    
    if(!datao.is_open()) {cout<<"file not open\n";return ;}

    datao.write((char*)&a,sizeof(a));

    datao.close();
}

void NapolniFile() {
    //spuca file da je prazn
    ofstream SpucaFile("Potovanja.bin",ios::binary);
    SpucaFile.close();
    VpisiBIN(Potovanje{"smrekec",69,42042.0});
    VpisiBIN(Potovanje{"soncni dvoir",12,420.69});
    VpisiBIN(Potovanje{"brezje pr grosuplem",9,937.3});
    VpisiBIN(Potovanje{"vegova",4,497.9});
    VpisiBIN(Potovanje{"litostroj",13,23443.34});
}

int main(int argc, char const *argv[])
{
//    NapolniFile();
    IzpisiBIN();
    Funkcija();
    return 0;
}