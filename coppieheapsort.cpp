#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template <class H>
class Coppia{
public:
	H x, y;

	Coppia(H x, H y){
		this->x=x;
		this->y=y;
	}

	friend bool operator> (Coppia &a, Coppia b){
		if(a.x>b.x)
			return 1;
		else if(a.x==b.x && a.y>b.y)
			return 1;
		return 0;
	}

	friend ostream& operator<<(ostream &os, Coppia &a){
		return os<< "(" << a.x<< " " << a.y<< ")";
	}
};


template <class H>
class Heap{
public:
	Coppia<H>** vett;
	int heapsize, chiamate;

	int left(int i){return i<<1;}
	int right(int i){return (i<<1)|1;}
	int parent(int i){return i>>1;}

	Heap(){
		heapsize=0;
		chiamate=0;
	} 

	void heapify(int i){
		if(heapsize>=1)
			chiamate++;
		int l=left(i);
		int r=right(i);
		int max=i;

		if(l<= heapsize && *vett[l] > *vett[max])
			max=l;
		if(r<= heapsize && *vett[r] > *vett[max])
			max=r;
		if(max !=i){
			swap(vett[max], vett[i]);
			heapify(max);
		}
	}

	void build(Coppia<H>** A, int n){
		vett=A;
		heapsize=n;

		for(int i=heapsize/2; i>0; i--)
			heapify(i);
	}

	Coppia<H>* extract(){
		swap(vett[1], vett[heapsize]);
		heapsize--;
		heapify(1);
		return vett[heapsize+1];
	}

};

template <class H>
void printvett(Coppia<H>** vett, int n){
	for(int i=1; i<=n; i++)
		out<<*vett[i]<<" ";
	out<<endl;
}


int main(){
	for(int i=0; i<100; i++){
		string type;
		int n;
		in>>type>>n;

		if(type=="int" || type=="bool"){

			Coppia<int>** vett=new Coppia<int>*[n+1];
			Heap<int>* h=new Heap<int>();

			for(int j=1; j<=n; j++){
				char tmp;
				in>>tmp;
				int x, y;
				in>>x>>y;
				in>>tmp;
				vett[j]=new Coppia<int>(x, y);
			}
			Coppia<int>** vettoreordinato=new Coppia<int>*[n+1];
			h->build(vett, n);
			for(int j=n; j>0; j--)
				vettoreordinato[j]=h->extract();
			out<<h->chiamate<<" ";
			printvett(vettoreordinato, n);
		}

		else if(type=="double"){
			Coppia <double>** vett=new Coppia<double>*[n+1];
			Heap<double>* h=new Heap<double>();

			for(int j=1; j<=n; j++){
				char tmp;
				in>>tmp;
				double x, y;
				in>>x>>y>>tmp;
				vett[j]=new Coppia<double>(x, y);
			}
			Coppia<double>** vettoreordinato=new Coppia<double>*[n+1];
			h->build(vett, n);
			for(int j=n; j>0; j--)
				vettoreordinato[j]=h->extract();
			out<<h->chiamate<<" ";
			printvett(vettoreordinato, n);
		}

		else if(type=="char"){
			Coppia <char>** vett=new Coppia <char>*[n+1];
			Heap<char>* h=new Heap<char>();

			for(int j=1; j<=n; j++){
				char tmp, x, y;
				in>>tmp;
				in>>x>>y>>tmp;
				vett[j]=new Coppia<char>(x, y);
			}
			Coppia<char>** vettoreordinato=new Coppia<char>*[n+1];
			h->build(vett, n);
			for(int j=n; j>0; j--)
				vettoreordinato[j]=h->extract();
			out<<h->chiamate<<" ";
			printvett(vettoreordinato, n);
		}
	}
}