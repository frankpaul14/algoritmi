#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int matrixChain(int* vett, int n){
    int m[n][n];
    for(int i=1; i<n; i++){
        m[i][i]=0; //inizializzo la diagonale a 0
    }
    for (int l=1; l<n; l++){
        for(int i=1; i<n-l; i++){
            int j= l+i;
            m[i][j]= INT_MAX;
            for(int k=i; k<j; k++){
                int q= m[i][k]+ m[k+1][j]+ vett[i-1]* vett[k]* vett[j];
                if(q< m[i][j])
                    m[i][j]= q;
            }
        }
    }
    return m[1][n-1];
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int i=0; i<100; i++){
        int n; in>>n;
        int* vett= new int[n+1];
        int r, c;
        for(int j=0; j<n; j++){
            char tmp;
            in>>tmp>>r>>tmp>>c>>tmp;
            vett[j]= r;
        }
        vett[n]= c;
        out<<matrixChain(vett,n+1)<<endl;
    }
}