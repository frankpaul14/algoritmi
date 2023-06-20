#include <iostream>
#include <fstream>
using namespace std;

int lcs(int m,int n, string x, string y){
    int** a;
    a= new int*[m+1];
    for(int i=0; i<=m; i++){
        a[i]= new int[n+1];
    }
    for(int i=0; i<=n; i++){//inizializzo le colonne(primo el)
        a[0][i]=0;
    }
    for(int i=0; i<=m; i++){//inizializzo le righe(primo el)
        a[i][0]=0;
    }
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                a[i][j]=(a[i-1][j-1]+1);
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    return a[m][n];
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int i=0; i<100; i++){
        int m,n;
        in>>m;
        in>>n;
        string x;
        in>>x;
        string y;
        in>>y;
        out<<lcs(m,n,x,y)<<endl;
    }
}