#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int edit(int m, int n, string x, string y){
    int** a;
    a= new int* [m+1];
    for(int i=0; i<=m; i++){
        a[i]= new int[n+1];
    }
    for(int i=0; i<=m; i++){//nell'edit la prima riga e la prima colonna sono riempite con numeri progressivi
        a[i][0]=i;          //da 1 a n e da 1 a m
    }
    for(int i=0; i<=n; i++){
        a[0][i]=i;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                a[i][j]= a[i-1][j-1];
            }
            else{
                a[i][j]=(min(min(a[i-1][j],a[i][j-1]), a[i-1][j-1])+1);
            }
        }
    }
    return a[m][n];
}

int main(){
    for(int i=0;i<100;i++){
        int m; in>>m;
        int n; in>>n;
        string x; in>>x;
        string y; in>>y;
        out<<edit(m,n,x,y)<<endl;
    }
}