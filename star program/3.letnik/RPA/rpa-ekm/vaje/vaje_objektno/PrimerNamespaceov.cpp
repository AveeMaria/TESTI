#include <cstdlib>
#include <iostream>

using namespace std;

namespace EvroCar{
    char znamka[10];
    char model[15];
    int teza;
    int km;
    int navor;
    float potencial(){
        float pot;
            pot=(float)km/teza;
            pot=pot*1000;
            cout<<pot<<endl;
            return pot;
        }
        
    void Beri(){
        cin>>znamka;
        fflush(stdin);
        cin>>model;
        fflush(stdin);
        cin>>teza;
        fflush(stdin);
        cin>>km;
        fflush(stdin);
        cin>>navor;
        cout<<znamka<<endl;
        cout<<model<<endl;
        cout<<teza<<endl;
        cout<<km<<endl;
        cout<<navor<<endl;
    }
}

namespace USACar{
    char znamka[10];
    char model[15];
    int teza;
    int km;
    int navor;
    float potencial(){
        float pot;
        pot=(float)navor/teza;
        pot=pot*1000;
        cout<<pot<<endl;
        return pot;
    }
    void Beri(){
        cin>>znamka>>model;
        fflush(stdin);
        cin>>teza>>km;
        cin>>navor;

    }
}



int main(int argc, char *argv[])
{EvroCar::Beri();
USACar::Beri();
cout<<EvroCar::potencial()<<endl;
cout<<USACar::potencial()<<endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
