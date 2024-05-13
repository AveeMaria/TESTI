#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void IzpisiZnaki() {
    ifstream datai("Znaki.txt");
    
    if(!datai.is_open()) {cout<<"file not open\n";return ;}
    cout<<"\n-----------------------\n";
    string s;
    while(getline(datai,s)) {
        cout<<s<<"\n";
    }
    cout<<"-----------------------\n";
    datai.close();
}

void IzpisiSamoglasnik() {
    ifstream datai("Samoglasnik.txt");
    
    if(!datai.is_open()) {cout<<"file not open\n";return ;}
    cout<<"\n-----------------------\n";
    string s;
    while(getline(datai,s)) {
        cout<<s<<"\n";
    }
    cout<<"-----------------------\n";
    datai.close();
}

//vstavi samogl. iz znaki.txt v samogl.txt na 3. mesto 
void Samoglasniki() {
    ifstream datai("Znaki.txt");
    ifstream datai2("Samoglasnik.txt");
    ofstream datao("tmp.txt");

    if(!datai.is_open()) {cout<<"file not open\n";return ;}
    if(!datai2.is_open()) {cout<<"file not open\n";return ;}
    if(!datao.is_open()) {cout<<"file not open\n";return ;}

    bool prenos=false;
    char c;

    //prepise prva dva znaka iz obstojece samoglasnik.txt da potem na 3. mesto vstavlja
    datai2>>c;datao<<c;
    datai2>>c;datao<<c;

    while(datai>>c) {
        //pogleda ce je crka iz znaki.txt samoglasnik
        //chainam case da se ne ponavla
        switch (c) {
            case 'A':case 'E':case 'I':case 'O':case 'U':
            case 'a':case 'e':case 'i':case 'o':case 'u':
                datao<<c;
                prenos=true;
        }
    }

    //nakonc prepisemo se ostale stvari iz prejsnga samoglasniki.txt da se ne zgubi
    while(datai2>>c) {
        datao<<c;
    }

    datai.close();
    datai2.close();
    datao.close();

    if(prenos==false) {
        cout<<"ni bilo prenosa\n";
    }
    else {
        remove("Samoglasnik.txt");rename("tmp.txt","Samoglasnik.txt");
    }
}


int main(int argc, char const *argv[]) {
    

    IzpisiZnaki();

    IzpisiSamoglasnik();

    Samoglasniki();

    IzpisiSamoglasnik();

    return 0;
}