#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void IzpisiTXT(const char* filename) {
    ifstream datai(filename);
    
    if(!datai.is_open()) {cout<<"file not open\n";return ;}

    string s;
    while(getline(datai,s)) {
        cout<<s<<"\n";
    }

    datai.close();
}

int main(int argc, char const *argv[])
{
    //to je sam za testiranje na testu ni treba izpisa
    IzpisiTXT("besedilo.txt");//ali IzpisiTXT(argv[1]);

    //zdej najde in zbrise tm k je najvec samoglasnikov

    ifstream datai("besedilo.txt");
    //ifstream datai(argv[1]); to das ce hocs v CMDju runnat da odpre "besedilo.txt"
    //comands: besedilo.exe zvezdice

    if(!datai.is_open()) {cout<<"file not open\n";return -1;}

    int line=0;
    int maxsam=0;
    string s;

    int deleteLine=-1;
    //ta while najde kje je najvec samoglasov da pol zbrise
    while(getline(datai,s)) {
        ++line;
        int sam=0;
        for(int i=0;i<s.size();++i) {
            //gre cez vse crke v vrstici in presteje samoglasnike
            switch (s[i]) {
                case 'A':case 'E':case 'I':case 'O':case 'U':
                case 'a':case 'e':case 'i':case 'o':case 'u':
                    ++sam;
            }
        }

        if(sam>maxsam) {
            maxsam=sam;
            deleteLine=line;
        }
    }
    datai.close();

    ifstream datai2("besedilo.txt");//datai2(argc[1]);
    ofstream datao("tmp.txt");//datao(argc[1]);

    if(!datai2.is_open()||!datao.is_open()) {cout<<"file not open\n";return -1;}

    int i=0;

    //to prepise vse razn to k brisemo v tmp
    while(getline(datai2,s)) {
        ++i;

        //ce stevilka vrstice ni enaka vrstici k jo brisemo napise v tmp
        if(i!=deleteLine) {
            datao<<s<<"\n";
        }
    }
    
    datai2.close();
    datao.close();
    
    //PAZI ce delas z argc[];
    remove("besedilo.txt");rename("tmp.txt","besedilo.txt");

    return 0;
}