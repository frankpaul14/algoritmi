#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");



template <class H>
class Terna{
public:
	H x, y, z;

	Terna(H x, H y, H z){
		this->x=x;
		this->y=y;
		this->z=z;
	}

	friend bool operator > (Terna &a, Terna&b){
	if(a.x > b.x)
		return true;
	else if(a.x == b.x && a.y > b.y)
		return true;
	else if(a.x == b.x && a.y == b.y && a.z > b.z)
		return true;
	else
		return false;
	}
	friend ostream& operator <<(ostream &os, Terna &a){
	return os<<"("<<a.x<<" "<<a.y<<" "<<a.z<<")";
	}
};

template <class H>
class Heap{
public:
	Terna<H>** vett;
	int heapsize, chiamate;

	int left(int i){return i<<1;}
	int right(int i){return (i<<1)|1;}
	int parent(int i){return i>>1;}
	Heap(){ chiamate=heapsize=0; }

	void heapify(int i){
		if(heapsize >=1)
			chiamate++;
		int l=left(i);
		int r=right(i);
		int max=i;

		if(l<=heapsize && *vett[l] > *vett[max])
			max=l;
		if(r <= heapsize && *vett[r] > *vett[max])
			max=r;
		if(max != i){
			swap(vett[max], vett[i]);
			heapify(max);
		}
	}

	void build(Terna<H>** A, int n){
		vett=A;
		heapsize=n;

		for(int i=heapsize/2; i>0; i--)
			heapify(i);
	}

	Terna<H>* extract(){
		swap(vett[1], vett[heapsize]);
		heapsize--;
		heapify(1);
		return vett[heapsize+1];
	}

};



template <class H>
void printvett(Terna<H>** vett, int n){
	for(int i=1; i<=n; i++)
		out<<*vett[i]<<" ";
	out<<endl;
}


template <class H>
void esec(Terna<H>** vett, Heap<H>* t, int n, Terna<H>** vettordinato){
	for(int j=1; j<=n; j++){
		char tmp;
		in>>tmp;
		H x, y, z;
		in>>x>>y>>z;
		in>>tmp;
		vett[j]=new Terna<H>(x, y, z);
	}
	t->build(vett, n);

	for(int j=n; j>0; j--)
		vettordinato[j]=t->extract();
	out<<t->chiamate<<" ";
	printvett(vettordinato, n);

}

int main(){
	for(int i=0; i<100; i++){
		string type;
		int n;
		in>>type>>n;

		if(type=="int" || type=="bool"){
			Terna<int>** vett=new Terna<int>*[n+1];
			Terna<int>** vettordinato=new Terna<int>*[n+1];
			Heap<int>* t=new Heap<int>();
			esec(vett, t, n, vettordinato);
		}
		else if(type=="char"){
			Terna<char>** vett=new Terna<char>*[n+1];
			Terna<char>** vettordinato=new Terna<char>*[n+1];
			Heap<char>* t=new Heap<char>();
			esec(vett, t, n, vettordinato);		
		}
		else if(type=="double"){
			Terna<double>** vett=new Terna<double>*[n+1];
			Terna<double>** vettordinato=new Terna<double>*[n+1];
			Heap<double>* t=new Heap<double>();
			esec(vett, t, n, vettordinato);
		}
	}
}