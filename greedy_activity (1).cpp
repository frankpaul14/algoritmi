#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void sort(int* s, int* f, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(f[i] > f[j]){
                int tmp= f[i];
                f[i]= f[j];
                f[j]= tmp;

                tmp= s[i];
                s[i]= s[j];
                s[j]= tmp;
            }
        }
    }
}

int main(){
    for(int i=0; i<100; i++){
        int n; in>>n;
        int* s= new int[n];
        int* f= new int[n];
        int si, fi;
        for(int j=0; j<n; j++){
            char c;
            in>>c>>si>>fi>>c;
            s[j]= si;
            f[j]= fi;
        }
        sort(s,f,n);
        int cont=1;
        int k=0;
        for(int j=k+1; j<n; j++){
            if(f[k]<= s[j]){
                cont++;
                k=j;
            }
        }
        out<<cont<<endl;
    }
}