#include <iostream>
#include <cstring>
#include <time.h>

using std::string;
using std::cout;
using std::cin;

struct El {
	string naziv;
	int kolicina;
	bool zaloga;
	struct El *next;
}*start3=nullptr;

struct El2 {
	string naziv;
	int kolicina;
	bool zaloga;
	struct El2 *next,*prev;
}*start1=nullptr,*end1=nullptr,*start2=nullptr,*end2=nullptr;

void Izpisi1() {
	if(start1==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=start1; 
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t\t"<<tmp->zaloga<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi2() {
	if(start2==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=start2; 
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t\t"<<tmp->zaloga<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi3() {
	if(start3==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El *tmp=start3; 
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t\t"<<tmp->zaloga<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi1Obratno() {
	if(end1==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=end1; 
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t\t"<<tmp->zaloga<<"\n";
			tmp=tmp->prev;
		}
	}
	cout<<"\n";
}

void Izpisi2Obratno() {
	if(end2==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=end2; 
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t\t"<<tmp->zaloga<<"\n";
			tmp=tmp->prev;
		}
	}
	cout<<"\n";
}

void Ustvari1(string n,int k,bool z) {
	struct El2 *tmp=new struct El2;
	tmp->naziv=n;tmp->kolicina=k;tmp->zaloga=z;
	if(start1==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start1=tmp;
		end1=tmp;
	}
	else {
		tmp->next=start1;
		start1->prev=tmp;
		tmp->prev=nullptr;
		start1=tmp;
	}
}

void Ustvari2(string n,int k,bool z) {
	struct El2 *tmp=new struct El2;
	tmp->naziv=n;tmp->kolicina=k;tmp->zaloga=z;
	if(start2==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start2=tmp;
		end2=tmp;
	}
	else {
		tmp->next=start2;
		start2->prev=tmp;
		tmp->prev=nullptr;
		start2=tmp;
	}
}

void Urejen3(string n,int k,bool z) {
	struct El *tmp=new struct El;
	tmp->naziv=n;tmp->kolicina=k;tmp->zaloga=z;
	if(start3==nullptr) {
		tmp->next=nullptr;
		start3=tmp;
	}
	else {
		struct El *p=nullptr,*c=start3;
		while(c!=nullptr&&c->naziv<tmp->naziv) {
			p=c;c=c->next;
		}
		//ce je prvi
		if(c==start3) {
			tmp->next=start3;
			start3=tmp;
		}
		//ce je umes
		else if(c!=nullptr) {
			p->next=tmp;
			tmp->next=c;
		}
		//ce je zadni
		else {
			p->next=tmp;
			tmp->next=nullptr;
		}
	}
}

void Napolni3() {
	struct El2 *tmp=start1; 
	while(tmp!=nullptr) {
		Urejen3(tmp->naziv,tmp->kolicina,tmp->zaloga);
		tmp=tmp->next;
	}
	tmp=start2;
	while(tmp!=nullptr) {
		Urejen3(tmp->naziv,tmp->kolicina,tmp->zaloga);
		tmp=tmp->next;
	}	
}

void Brisi1(string n) {
	if(start1==nullptr&&end1==nullptr) {
        cout<<"prazen seznam";
        return;
    }
    struct El2 *tmp=start1;
    while(tmp!=nullptr&&tmp->naziv!=n) {
        tmp=tmp->next;
    }
    //ce je prvi
    if(tmp->prev==nullptr) {
        //ce je prvi
        if(start1!=nullptr) {
            start1=start1->next;
            start1->prev=nullptr;
            delete tmp;
        }
        //ce je edini
        else {
            start1=nullptr;
            end1=nullptr;
            delete tmp;
        }
    }
    //ce je zadnji
    else if(tmp->next==nullptr) {
        end1=end1->prev;
        end1->next=nullptr;
        delete tmp;
    }
    //ce je nekje vmes
    else if(tmp!=nullptr) {
        tmp->next->prev=tmp->prev;
        tmp->prev->next=tmp->next;
        delete tmp;
    }
    else {
        cout<<"\nelementa ni v seznamu.";
    }
}

void Brisi2(string n) {
	if(start2==nullptr&&end2==nullptr) {
        cout<<"prazen seznam";
        return;
    }
    struct El2 *tmp=start2;
    while(tmp!=nullptr&&tmp->naziv!=n) {
        tmp=tmp->next;
    }
    //ce je prvi
    if(tmp->prev==nullptr) {
        //ce je prvi
        if(start2!=nullptr) {
            start2=start2->next;
            start2->prev=nullptr;
            delete tmp;
        }
        //ce je edini
        else {
            start2=nullptr;
            end2=nullptr;
            delete tmp;
        }
    }
    //ce je zadnji
    else if(tmp->next==nullptr) {
        end2=end2->prev;
        end2->next=nullptr;
        delete tmp;
    }
    //ce je nekje vmes
    else if(tmp!=nullptr) {
        tmp->next->prev=tmp->prev;
        tmp->prev->next=tmp->next;
        delete tmp;
    }
    else {
        cout<<"\nelementa ni v seznamu.";
    }
}

void Napaka1() {	
	if(start1==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=start1; 
		while(tmp!=nullptr) {
			if(tmp->kolicina<=0) {
				Ustvari2(tmp->naziv,tmp->kolicina,tmp->zaloga);
				Brisi1(tmp->naziv);
			}
			tmp=tmp->next;
		}
	}		
}

void Napaka2() {	
	if(start2==nullptr) {
		cout<<"emtpy list\n";
	}
	else {
		struct El2 *tmp=start2; 
		while(tmp!=nullptr) {
			if(tmp->kolicina>0) {
				Ustvari1(tmp->naziv,tmp->kolicina,tmp->zaloga);
				Brisi2(tmp->naziv);
			}
			tmp=tmp->next;
		}
	}		
}

void Napolni() {
	Ustvari1("avto",988,1);
	Ustvari1("medo",-301,0);
	Ustvari1("letalo",19,1);
	Ustvari2("kocke",-202,0);
	Ustvari2("traktor",113,1);
	Ustvari2("vlakec",-93,0);
}

int main() {
	cout<<"naziv\tkolicina\tzaloga\n";
	cout<<"--------------------------------------\n";
	Napolni();Napolni3();

	Izpisi1();
	Izpisi2();
	Izpisi3();
	//najde use napake in popravi
	Napaka1();Napaka2();
	cout<<"--------------------------------------\n";
	Izpisi1();
	Izpisi2();
	Izpisi3();
	return 0;
}