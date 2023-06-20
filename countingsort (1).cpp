#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int findMax(int* vett, int n){
    int max=1;
    for(int i=1; i<=n; i++){
        if(vett[i]>vett[max])
            max=i;
    }
    return vett[max];
}

int findMin(int* vett, int n){
    int min=1;
    for(int i=1; i<=n; i++){
        if(vett[i]<vett[min])
            min=i;
    }
    return vett[min];
}

void printvett(int* vett, int n){
    for(int i=1; i<=n; i++){
        out<<vett[i]<<" ";
    }
}

int* counting(int* A, int n){
    int max= findMax(A,n);
    int min= findMin(A,n);
    int k= (max-min)+1;
    int C[k+1];
    int* B= new int[n+1];
    for(int i=0; i<=k; i++)
        C[i]=0;
    for(int i=1; i<=n; i++)
        C[A[i]-min+1]++;
    for(int i=2; i<=k; i++)
        C[i]= C[i]+C[i-1];
    
    out<<"0 ";
    printvett(C,k-1);
    for(int i=n; i>=1; i--){
        B[C[A[i]-min+1]]= A[i];
        C[A[i]-min+1]--;
    }
    return B;
}

int main(){
    for(int i=0; i<100; i++){
        int n; in>>n;
        int* vett= new int[n+1];
        for(int j=1; j<=n; j++){
            in>>vett[j];
        }
        vett=counting(vett,n);
        printvett(vett,n);
        delete []vett;
        out<<endl;
    }
}