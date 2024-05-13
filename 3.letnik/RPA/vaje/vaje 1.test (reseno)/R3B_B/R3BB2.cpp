#include <iostream>
#include <time.h>
#include <cstring>

using std::string;
using std::cout;
using std::cin;

struct El {
	string ime,priimek;
	bool gim;
	struct El *next;
}*start2=nullptr,*start3=nullptr;

struct El2 {
	string ime,priimek;
	bool gim;
	struct El2 *next,*prev;
}*start=nullptr,*end=nullptr;

void Izpisi1() {
	if(start==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *tmp=start;
		while(tmp!=nullptr) {
			cout<<tmp->ime<<"\t\t"<<tmp->priimek<<"\t\t"<<tmp->gim<<"\n";
			tmp=tmp->next;
		}
		cout<<"\n";
	}	
}

void Izpisi1Obratno() {
	if(end==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *tmp=end;
		while(tmp!=nullptr) {
			cout<<tmp->ime<<"\t\t"<<tmp->priimek<<"\t\t"<<tmp->gim<<"\n";
			tmp=tmp->prev;
		}
		cout<<"\n";
	}	
}

void Izpisi2() {
	if(start2==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *tmp=start2;
		while(tmp!=nullptr) {
			cout<<tmp->ime<<"\t\t"<<tmp->priimek<<"\t\t"<<tmp->gim<<"\n";
			tmp=tmp->next;
		}
		cout<<"\n";
	}	
}

void Izpisi3() {
	if(start3==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *tmp=start3;
		while(tmp!=nullptr) {
			cout<<tmp->ime<<"\t\t"<<tmp->priimek<<"\t\t"<<tmp->gim<<"\n";
			tmp=tmp->next;
		}
		cout<<"\n";
	}
}

//ustvarim dvostranski seznam
void Ustvari1(string name,string surname,bool g) {
	struct El2 *tmp=new struct El2;
	tmp->ime=name;
	tmp->priimek=surname;
	tmp->gim=g;
	if(start==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start=tmp;
		end=tmp;
	}
	else {
		start->prev=tmp;
		tmp->next=start;
		tmp->prev=nullptr;
		start=tmp;
	}
}

void Urejen2(string name,string surname,bool g) {
	struct El *tmp=new struct El;
	tmp->ime=name;
	tmp->priimek=surname;
	tmp->gim=g;
	if(start2==nullptr) {
		tmp->next=nullptr;
		start2=tmp;
	}
	else {
		struct El *c=start2,*p=nullptr;
		while(c!=nullptr&&c->priimek<tmp->priimek) {
			p=c;c=c->next;
		}
		//ce je prvi
		if(c==start2) {
			tmp->next=start2;
			start2=tmp;
		}
		//ce je zadnji
		else if(c==nullptr) {
			p->next=tmp;
			tmp->next=nullptr;
		}
		//ce je umes
		else {
			p->next=tmp;
			tmp->next=c;
		}
	}
}

void Urejen3(string name,string surname,bool g) {
	struct El *tmp=new struct El;
	tmp->ime=name;
	tmp->priimek=surname;
	tmp->gim=g;
	if(start3==nullptr) {
		tmp->next=nullptr;
		start3=tmp;
	}
	else {
		struct El *c=start3,*p=nullptr;
		while(c!=nullptr&&c->priimek<tmp->priimek) {
			p=c;c=c->next;
		}
		//ce je prvi
		if(c==start3) {
			tmp->next=start3;
			start3=tmp;
		}
		//ce je zadnji
		else if(c==nullptr) {
			p->next=tmp;
			tmp->next=nullptr;
		}
		//ce je umes
		else {
			p->next=tmp;
			tmp->next=c;
		}
	}
}

void Napolni() {
	Ustvari1("maky","bregy",0);
	Ustvari1("nikc","pikc",1);
	Ustvari1("roki","poki",1);
	Ustvari1("dinky","pinky",0);
	Ustvari1("leon","debeli",1);
}

void Sort() {
	if(start==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *tmp=start;
		while(tmp!=nullptr) {
			if(tmp->gim==0) {
				Urejen2(tmp->ime,tmp->priimek,tmp->gim);
			}else {
				Urejen3(tmp->ime,tmp->priimek,tmp->gim);
			}
			tmp=tmp->next;
		}
	}
}

void Brisi2(string name,string surname) {
	if(start2==nullptr) {
		cout<<"empty list\n";
		return;
	}
	struct El *c=start2,*p=nullptr;
	//najdemo prov ta ime in priimek
	while(c!=nullptr&&c->ime!=name&&c->priimek!=surname) {
			p=c;c=c->next;
	}
	//ce je prvi
	if(c==start2) {
		start2=start2->next;
		delete c;
	}
	//ce je umes/zadnji
	else if(c!=nullptr) {
		p->next=c->next;
		delete c;
	}
	//ce ga ni
	else {
		cout<<"ni elementa\n";
	}
}

void Brisi3(string name,string surname) {
	if(start3==nullptr) {
		cout<<"empty list\n";
		return;
	}
	struct El *c=start3,*p=nullptr;
	//najdemo prov ta ime in priimek
	while(c!=nullptr&&c->ime!=name&&c->priimek!=surname) {
			p=c;c=c->next;
	}
	//ce je prvi
	if(c==start3) {
		start3=start3->next;
		delete c;
	}
	//ce je umes/zadnji
	else if(c!=nullptr) {
		p->next=c->next;
		delete c;
	}
	//ce ga ni
	else {
		cout<<"ni elementa\n";
	}
}

int main() {
	cout<<"ime\t\tpriimek\t\tgimnazija\n";
	cout<<"-----------------------------------------\n";
	Napolni();
	Izpisi1();
	Sort();
	Urejen3("jaka","kaka",0);Izpisi3();Brisi3("jaka","kaka");
	Izpisi2();
	Izpisi3();
	
	return 0;
}