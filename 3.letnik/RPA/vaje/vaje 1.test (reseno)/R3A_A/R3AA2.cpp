#include <iostream>
#include <cstring>

using std::string;
using std::cout;
using std::cin;

struct El {
	struct El *next;
	string naziv;
	int kolicina;
	bool papir;
}*start=nullptr;

struct El2 {
	string naziv;
	int kolicina;
	bool papir;
	struct El2 *next,*prev;
}*start2=nullptr,*end2=nullptr,*start3=nullptr,*end3=nullptr;

void Izpisi1() {
	if(start==nullptr) {
		cout<<"empty list";
	}
	else {
		struct El *tmp=start;
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t"<<tmp->papir<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi2() {
	if(start2==nullptr) {
		cout<<"empty list";
	}
	else {
		struct El2 *tmp=start2;
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t"<<tmp->papir<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Izpisi2Obratno() {
	if(end2==nullptr) {
		cout<<"empty list";
	}
	else {
		struct El2 *tmp=end2;
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t"<<tmp->papir<<"\n";
			tmp=tmp->prev;
		}
	}
	cout<<"\n";
}

void Izpisi3Obratno() {
	if(end3==nullptr) {
		cout<<"empty list";
	}
	else {
		struct El2 *tmp=end3;
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t"<<tmp->papir<<"\n";
			tmp=tmp->prev;
		}
	}
	cout<<"\n";
}

void Izpisi3() {
	if(start3==nullptr) {
		cout<<"empty list";
	}
	else {
		struct El2 *tmp=start3;
		while(tmp!=nullptr) {
			cout<<tmp->naziv<<"\t"<<tmp->kolicina<<"\t"<<tmp->papir<<"\n";
			tmp=tmp->next;
		}
	}
	cout<<"\n";
}

void Ustvari1(string n,int k,bool p) {
	struct El *tmp=new struct El;
	tmp->naziv=n;tmp->kolicina=k;tmp->papir=p;
	if(start==nullptr) {
		tmp->next=nullptr;
		start=tmp;
	}
	else {
		tmp->next=start;
		start=tmp;
	}
}

void Urejen2(string n,int k,bool p) {
	struct El2 *tmp=new struct El2;
	tmp->naziv=n;tmp->kolicina=k;tmp->papir=p;
	if(start2==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start2=tmp;
		end2=tmp;
	}
	else {
		struct El2 *c=start2;
		while(c!=nullptr&&c->kolicina<tmp->kolicina) {
			c=c->next;
		}
		//ce je prvi
		if(c==start2) {
			tmp->next=start2;
			start2->prev=tmp;
			tmp->prev=nullptr;
			start2=tmp;
		}
		//ce je zadnji
		else if(c==nullptr) {
			tmp->prev=end2;
			end2->next=tmp;
			tmp->next=nullptr;
			end2=tmp;
		}
		//ce je umes
		else {
			c->prev->next=tmp;
			tmp->prev=c->prev;
			tmp->next=c;
			c->prev=tmp;
		}
	}
}

//ce je prvi zadnji umes
void Urejen3(string n,int k,bool p) {
	struct El2 *tmp=new struct El2;
	tmp->naziv=n;tmp->kolicina=k;tmp->papir=p;
	if(start3==nullptr) {
		tmp->next=nullptr;
		tmp->prev=nullptr;
		start3=tmp;
		end3=tmp;
	}
	else {
		struct El2 *c=start3;
		while(c!=nullptr&&c->kolicina<tmp->kolicina) {
			c=c->next;
		}
		//ce je prvi
		if(c==start3) {
			tmp->next=start3;
			start3->prev=tmp;
			tmp->prev=nullptr;
			start3=tmp;
		}
		//ce je zadnji
		else if(c==nullptr) {
			tmp->prev=end3;
			end3->next=tmp;
			tmp->next=nullptr;
			end3=tmp;
		}
		//ce je umes
		else {
			c->prev->next=tmp;
			tmp->prev=c->prev;
			tmp->next=c;
			c->prev=tmp;
		}
	}
}

void Brisi2(string n) {
	if(start2==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *c=start2;
		while(c!=nullptr&&c->naziv!=n) {
			c=c->next;
		}
		//ce je prvi/edini
		if(c==start2) {
			//ce je edini da ne zgubimo enda
			if(c->next==nullptr) {
				start2=nullptr;
				end2=nullptr;
				delete c;
			}
			//ce je sam prvi
			else {
				start2=start2->next;
				start2->prev=nullptr;
				delete c;
			}			
		}
		//ce je zadnji
		else if(c==end2) {
			end2=end2->prev;
			end2->next=nullptr;
			delete c;
		}
		//ce je umes
		else if(c!=nullptr){
			c->next->prev=c->prev;
			c->prev->next=c->next;
			delete c;
		}
		else {
			cout<<"ni elementa\n";
		}
	}
}

void Brisi3(string n) {
	if(start3==nullptr) {
		cout<<"empty list\n";
	}
	else {
		struct El2 *c=start3;
		while(c!=nullptr&&c->naziv!=n) {
			c=c->next;
		}
		//ce je prvi/edini
		if(c==start3) {
			//ce je edini da ne zgubimo enda
			if(c->next==nullptr) {
				start3=nullptr;
				end3=nullptr;
				delete c;
			}
			//ce je sam prvi
			else {
				start3=start3->next;
				start3->prev=nullptr;
				delete c;
			}			
		}
		//ce je zadnji
		else if(c==end3) {
			end3=end3->prev;
			end3->next=nullptr;
			delete c;
		}
		//ce je umes
		else if(c!=nullptr){
			c->next->prev=c->prev;
			c->prev->next=c->next;
			delete c;
		}
		else {
			cout<<"ni elementa\n";
		}
	}
}

void Napolni() {
	Ustvari1("plakat",21,1);
	Ustvari1("guma",44,0);
	Ustvari1("karton",17,1);
	Ustvari1("plenice",53,0);
	Ustvari1("miska",73,0);
	Ustvari1("mapa",39,1);
}

void Sort() {
	struct El *tmp=start;
	while(tmp!=nullptr) {
		if(tmp->papir==0) {
			Urejen2(tmp->naziv,tmp->kolicina,tmp->papir);
		}
		else {
			Urejen3(tmp->naziv,tmp->kolicina,tmp->papir);
		}
		tmp=tmp->next;
	}
}

void Popravi() {
	struct El2 *tmp=start2;
	//v seznamu 2 je nepapir
	while(tmp!=nullptr) {
		if(tmp->papir==1) {
			Urejen3(tmp->naziv,tmp->kolicina,tmp->papir);
			Brisi2(tmp->naziv);
		}
		tmp=tmp->next;
	}
	//return;
	//v seznamu 3 je papir
	tmp=start3;
	while(tmp!=nullptr) {
		if(tmp->papir==0) {
			Urejen2(tmp->naziv,tmp->kolicina,tmp->papir);
			Brisi3(tmp->naziv);
		}
		tmp=tmp->next;
	}
}

int main() {
	cout<<"naziv\tkol.\tpapir\n\n";
	Napolni();
	Sort();
	//dodamo dve napaki
	Urejen2("error1",999,1);
	Urejen3("error2",111,0);

	Izpisi1();
	Izpisi2();//Izpisi2Obratno();
	Izpisi3();//Izpisi3Obratno();
	//popravi napako
	Popravi();
	Izpisi1();Izpisi2();Izpisi3();
	return 0;
}