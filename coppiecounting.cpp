#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

template <class H>
class Coppia{
public:
	H x;
	H y;

	Coppia(H x, H y){
		this->x=x;
		this->y=y;
	}

//overloading di <<
	friend ostream& operator<<(ostream& os, const Coppia& a){
		return os<<"("<<a.x<<" "<<a.y<<")";//SANTAMARIA TI ODIO
	}
};


int findMax(Coppia<int>** vett, int n){
	int max=vett[0]->x;
	for(int i=1; i<n; i++)
		if(max < vett[i]->x)
			max=vett[i]->x;
	return max;
}

int findMin(Coppia<int>** vett, int n){
	int min=vett[0]->x;
	for(int i=1; i<n; i++)
		if(min > vett[i]->x)
			min=vett[i]->x;
	return min;
}


void printCoppia(Coppia<double>** vett, int n){
	for(int i=0; i<n; i++)
		out<<*vett[i]<<" ";
}

void printvett(int* vett, int n){
	for(int i=0; i<n; i++)
		out<<vett[i]<<" ";
	
}

void countingsort(Coppia<double>** A, int n){
	cout<<"SONO NEL COUNTINSORT"<<endl;
	Coppia<int>** vett=new Coppia<int>*[n];

	for(int i=0; i<n; i++)
		vett[i]=new Coppia<int>(int(A[i]->x*10), int(A[i]->y*10));
	int max=findMax(vett, n);
	int min=findMin(vett, n);
	int k=max-min+1;
	cout<<"k= "<<k<<" max= "<<max<<" min= "<<min<<endl;
	int* C=new int[k];

	for(int i=0; i<k; i++)
		C[i]=0;
	for(int i=0; i<n; i++)
		C[vett[i]->x - min]++;
	for(int i=1; i<k; i++)
		C[i]=C[i]+C[i-1];


	Coppia<double>** B=new Coppia<double>*[n];
	for(int i=n-1; i>=0; i--){
		B[C[vett[i]->x - min]-1]=new Coppia<double>(double(vett[i]->x/10.0), double(vett[i]->y/10.0));
		C[vett[i]->x - min]--;
	}
	//	printvett(C, k);
	//	printCoppia(B, n);

	for(int i=0; i<k; i++)
		out<<C[i]<<" ";

	for(int i=0; i<n; i++)
		out<<*B[i]<<" ";
	
	out<<endl;
	delete[] vett;
	delete[] C;
	delete[] B;
}

int main(){
	for(int i=0; i<100; i++){
		int n;
		char tmp;
		double x, y;
		in>>n;
		Coppia<double>** cp=new Coppia<double>*[n];
		for(int j=0; j<n; j++){
		in>>tmp>>x;
		//in>>tmp;		//supposto che la virgola la mette
		in>>y>>tmp;
		cp[j]=new Coppia<double>(x, y);
		}
		countingsort(cp, n);

	}
}