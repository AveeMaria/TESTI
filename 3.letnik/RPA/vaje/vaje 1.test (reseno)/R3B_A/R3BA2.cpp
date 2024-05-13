#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;

struct El {
	string priimek;
	short ocena;
	struct El *next;
}*start1=nullptr,*start2=nullptr;

struct El2 {
	string priimek;
	short ocena;
	struct El2 *next,*prev;
}*start3=nullptr,*end3=nullptr;

void Ustvari1(string surname,short grade) {
	struct El *tmp=new struct El;
	tmp->priimek=surname;
	tmp->ocena=grade;
	if(start1==nullptr ){
		tmp->next=nullptr;
		start1=tmp;
	}
	else {
		tmp->next=start1;
		start1=tmp;
	}
}

void Ustvari2(string surname,short grade) {
	struct El *tmp=new struct El;
	tmp->priimek=surname;
	tmp->ocena=grade;
	if(start2==nullptr ){
		tmp->next=nullptr;
		start2=tmp;
	}
	else {
		tmp->next=start2;
		start2=tmp;
	}
}

void Izpisi1() {
	cout<<"RPA:\n";
	if(start1==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *tmp=start1;
		while(tmp!=nullptr) {
			cout<<tmp->priimek<<"\t\t"<<tmp->ocena<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi2() {
	cout<<"RPAv:\n";
	if(start2==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *tmp=start2;
		while(tmp!=nullptr) {
			cout<<tmp->priimek<<"\t\t"<<tmp->ocena<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi3() {
	cout<<"Skupen seznam:\n";
	if(start3==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *tmp=start3;
		while(tmp!=nullptr) {
			cout<<tmp->priimek<<"\t\t"<<tmp->ocena<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi3Obratno() {
	cout<<"Skupen seznam obratno:\n";
	if(end3==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *tmp=end3;
		while(tmp!=nullptr) {
			cout<<tmp->priimek<<"\t\t"<<tmp->ocena<<"\n";
			tmp=tmp->prev;
		}
	}
	cout<<"\n";
}

void Napolni() {
	Ustvari1("bregar",3);
	Ustvari1("cehlar",4);
	Ustvari1("zdeslar",1);
	Ustvari2("suric",5);
	Ustvari2("pantar",2);
	Ustvari2("kakar",3);
}

void Urejen3(string surname,short grade) {
	struct El2 *tmp=new struct El2;
	tmp->priimek=surname;
	tmp->ocena=grade;
	if(start3==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start3=tmp;
		end3=tmp;
	}
	else {
		struct El2 *c=start3;//*p=nullptr;
		while(c!=nullptr&&c->priimek<tmp->priimek) {
			c=c->next;
		}
		//ce je prvi
		if(c==start3) {
			tmp->next=start3;
			start3->prev=tmp;
			tmp->prev=nullptr;
			start3=tmp;
		}
		//ce je edini
		else if(nullptr) {
			end3->next=tmp;
			tmp->prev=end3;
			tmp->next=nullptr;
			end3=tmp;
		}
		//ce je umes
		else {
			c->prev->next=tmp;
			tmp->prev=c->prev;
			c->prev=tmp;
			tmp->next=c;
		}
	}

}

void Napolni3() {
	struct El *tmp=start1;
	while(tmp!=nullptr) {
		Urejen3(tmp->priimek,tmp->ocena);
		tmp=tmp->next;
	}
	tmp=start2;
	while(tmp!=nullptr) {
		Urejen3(tmp->priimek,tmp->ocena);
		tmp=tmp->next;
	}
}

void Brisi1(string surname) {
	if(start1==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *c=start1,*p=nullptr;
		while(c!=nullptr&&c->priimek!=surname) {
			p=c;c=c->next;
		}
		if(c==start1) {
			start1=start1->next;
			delete c;
		}
		else if(c!=nullptr) {
			p->next=c->next;
			delete c;
		}
		else {
			cout<<"ni elementa\n";
		}
	}
}

void Brisi2(string surname) {
	if(start2==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El *c=start2,*p=nullptr;
		while(c!=nullptr&&c->priimek!=surname) {
			p=c;c=c->next;
		}
		if(c==start2) {
			start2=start2->next;
			delete c;
		}
		else if(c!=nullptr) {
			p->next=c->next;
			delete c;
		}
		else {
			cout<<"ni elementa\n";
		}
	}
}

int main() {
	cout<<"priimek\t\tocena\n"<<"---------------------\n";
	Napolni();
	Napolni3();
	Izpisi1();
	Izpisi2();
	Izpisi3();
	return 0;
}