#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

string print_lcs(int m, int n, string x, string y, int** a){
    int k= a[m][n];
    char c[k+1];
    c[k]= '\0';
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            c[k-1]=x[i-1];
            k--;
            i--;
            j--;
        }
        else{
            if(a[i][j-1]>= a[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    return c;
}

string lcs(int m, int n, string x, string y){
    int** a;
    a= new int*[m+1];
    for(int i=0; i<=m; i++){
        a[i]=new int[n+1];
    }
    for(int i=0; i<=m; i++){
        a[i][0]=0;
    }
    for(int i=0; i<=n; i++){
        a[0][i]=0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                a[i][j]= (a[i-1][j-1]+1);
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    return print_lcs(m,n,x,y,a);
}

int main(){
    for(int i=0;i<100;i++){
        int m;
        int n;
        string x;
        string y;
        in>>m;
        in>>n;
        in>>x;
        in>>y;
        out<<lcs(m,n,x,y)<<endl;
    }
}