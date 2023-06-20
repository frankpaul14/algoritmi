#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

void print(int vett[], int n){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(vett[i] > vett[j])
				swap(vett[i], vett[j]);

	for(int i=0; i<n; i++)
		out<<vett[i]<<" ";
	out<<endl;	
}

void resto(int r, int* vett, int n){
	int table[r+1];
	int s[r+1];
	table[0]=0; 
	s[0]=0;

	for(int i=1; i<r+1; i++){
		table[i]=INT_MAX;
		s[i]=0;
	}

	for(int i=1; i<r+1; i++){
		for(int j=0; j<n; j++){
			if(vett[j] <= i){
				int sub_res=table[i - vett[j]];
				if(sub_res != INT_MAX && sub_res + 1 <table[i]){
					table[i]=sub_res + 1;
					s[i]=j;
				}
			}
		}
	}

	int k=r;
	int i=0;
	int result[table[r]];

	while(k>0){
		result[i]=vett[s[k]];
		i++;
		k=k-vett[s[k]];
	}
	out<<table[r]<<" ";
	print(result, table[r]);
}

int main(){
	for(int i=0; i<100; i++){
		int r, n;
		in>>r>>n;
		int*vett= new int[n];
		for(int j=0; j<n; j++)
			in>>vett[j];
		for(int w=0; w<n-1; w++)
			for(int k=0; k<n-1; k++)
				if(vett[k] < vett[k+1])
					swap(vett[k], vett[k+1]);

		resto(r, vett, n);
	}
}