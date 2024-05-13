#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream datai("zvezdice.txt");
    //ifstream datai(argv[1]); to das ce hocs v CMDju runnat da odpre "zvedice.txt"
    //comands: zvezdice.exe zvezdice

    if(!datai.is_open()) {cout<<"file not open\n";return -1;}

    string s;

    int line=0;
    while(getline(datai,s)) {
        ++line;
        int st_zvezdic=0;

        for(int i=0;i<s.size();++i) {
            if(s[i]=='*') {
                st_zvezdic++;
            }
        }

        cout<<"zvezdice v "<<line<<". vrstici: "<<st_zvezdic<<"\n";
    }
    datai.close();
    return 0;
}