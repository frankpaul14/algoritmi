#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
                        //n-> numero taglio di monete disponibili
                        //r-> resto da restituire
                        //a-> tagli di monete
int monete(int*a, int n, int r){
    int t[r+1];
    t[0]=0;
    for(int i=1; i<=r; i++){
        t[i]=INT_MAX;
    }
    for(int i=1; i<=r; i++){
        for(int j=0; j<n; j++){
            if(a[j]<=i){
                int resto= t[i-a[j]];
                if(resto!=INT_MAX && resto+1<t[i]){
                    t[i]=resto+1;
                }
            }
        }   
    }
    return t[r];
}
int main(){
    for(int i=0; i<100; i++){
        int r; in>>r;
        int n; in>>n;
        int*a=new int[n];
        for(int j=0; j<n; j++){
            in>>a[j];
        }
        out<<monete(a,n,r)<<endl;
    }
}